/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_seq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:58:09 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/16 17:20:58 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"
#include <stdbool.h>

pid_t		execute_pip_pt2(char **args, char **a_env)
{
	pid_t		pid;
	char		*full_path;

	pid = fork();
	if (pid == -1)
	{
		ft_printf(2, "Error forking.\n");
		return (-1);
	}
	else if (pid == 0)
	{
		if (!check_builtins(args[0]))
			full_path = get_full_path(args[0]);
		if (check_builtins(args[0]))
			execute_bultins(args);
		if (execve(full_path, args, a_env))
		{
			ft_printf(2, "Error executing\n");
			exit(127);
			return (-1);
		}
	}
	else
		backups(2);
	return (pid);
}

t_vector	*execute_pip(t_simple_command *cmd, int len)
{
	t_vector	*vec_pid;
	char		**args;
	pid_t		pid;
	int			i;
	int			x;

	i = -1;
	vec_pid = vector_init(sizeof(pid_t), NULL);
	while (++i < len)
	{
		args = cmd[i].args->array;
		x = -1;
		while (args[++x])
			remove_quotes(&args[x]);
		x = do_pipes_and_red(index, len, cmd[i].redirections);
		pid = execute_pip_pt2(args, g_shell_env, i, len);
		if (pid != -1)
			vector_push(vec_pid, &pid);
		else
			return (NULL);
	}
	return (vec_pid);
}

int	execute_pipe_seq(t_pipe_sequence *pipe_seq, t_bool is_background,
			t_bool is_interactive)
{
	t_simple_command	*s_cmd;
	t_vector			*vec_pid;
	pid_t			*pid;
	pid_t			f_pid;
	int			i;

	s_cmd = (t_simple_command *)pipe_seq->commands->array;
	vec_pid = execute_pip(s_cmd, pipe_seq->commands->length);
	if (vec_pid)
	{
		i = 0;
		pid = (pid_t *)vec_pid->array;
		while (i < (int)vec_pid->length)
		{
			if (!pid[i + 1])
				f_pid = pid[i];
			i++;
		}
		if (is_interactive == FALSE)
			return (wait_children(f_pid));
		else
			execute_job(vec_pid, pipe_seq->job_name, is_background);
	}
	return (0);
}
// TODO fix norme
