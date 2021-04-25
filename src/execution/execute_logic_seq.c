/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_logic_seq.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:42:48 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/16 16:58:01 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static int	execute_logical_segment(t_command *cmd, t_bool is_background,
	t_bool is_interactive)
{
	int ret;

	if (cmd->type == PIPE_SEQ)
		ret = execute_pipe_seq((t_pipe_sequence*)cmd->command, is_background,
			is_interactive);
	else
		ret = execute_simple_cmd((t_simple_command*)cmd->command, is_background,
			is_interactive);
	return (ret);
}


static int	logic_seq_executor(t_logic_sequence *logic_seq, 
	t_bool is_background, t_bool is_interactive)
{
	int					ret;
	int 				i;
	t_command *const	cmds = logic_seq->commands->array;
	t_token_type *const	ops = logic_seq->logic_ops->array;

	i = 0;
	ret = execute_logical_segment(&cmds[0], is_background, is_interactive);
	while (i < (int)logic_seq->logic_ops->length)
	{
		if ((ret == 0 && ops[i] == ANDAND)
			|| (ret != 0 && ops[i] == OROR))
			ret = execute_logical_segment(&cmds[i + 1], is_background,
				is_interactive);
		else
<<<<<<< HEAD
			break ;
=======
			break;
>>>>>>> 27eb4429e170203ed8c98927b8c2e5c213fae565
		i++;
	}
	return (ret);
}

static int	execute_logic_seq_background(t_logic_sequence *logic_seq)
{
	pid_t	pid;
	t_job	*job;

	pid = fork();
	if (pid == 0)
		exit(logic_seq_executor(logic_seq, TRUE, FALSE));
	else if (pid < 0)
	{
		// TODO handle fork error
		return (-1);// TODO handle fork error
	}
	job = new_job(TRUE, logic_seq->job_name);
	add_process_to_job(job, pid);
	job->ret_pid = pid;
	return (0);
}

int			execute_logic_seq(t_logic_sequence *logic_seq, t_bool is_background)
{
	if (is_background)
		return (execute_logic_seq_background(logic_seq));
	else
		return (logic_seq_executor(logic_seq, FALSE, TRUE));
}
