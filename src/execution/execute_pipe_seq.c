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

int	manage_pipes(int i, int len)
{
	static int		fd[2];

	if (i != len)
	{
		if (pipe(fd) == -1)
			exit(0);
		dup2(fd[1], 1);
		close(fd[1]);
		return (fd[0]);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		return (-1);
	}
}

pid_t		execute_pip_pt2(char **args, char **a_env, int index, int len)
{
	pid_t		pid;
	char		*full_path;
	static int	fd;
	int			i;

	fd = -1;
	i = -1;
	while (args[++i])
		remove_quotes(&args[i]);
	fd = manage_pipes(index, len);
	pid = fork();
	if (pid == -1)
	{
		ft_printf(2, "Error forking.\n");
		return (-1);
	}
	else if (pid == 0)
	{
		full_path = get_full_path(args[0]);
		if (fd != -1)
			close(fd);
		if (execve(full_path, args, a_env))
		{
			ft_printf(2, "Error executing\n");
			exit(127);
			return (-1);
		}
	}
	else
	{
		backups(2);
		//for_testing
		if (index == len)
			while (wait(0) > 0)
				;
	}
	return (pid);
}

t_vector	*execute_pip(t_simple_command *cmd, int len)
{
	t_vector	*vec_pid;
	char		**args;
	pid_t		pid;
	int			i;

	i = 0;
	vec_pid = vector_init(sizeof(pid_t), free);
	while (i < len)
	{
		args = cmd[i].args->array;
		pid = execute_pip_pt2(args, g_shell_env, i + 1, len);
		i++;
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
		is_background = false;
		if (is_interactive == FALSE)
			return (wait_children(f_pid));
		//else
		//	execute_job(vec_pid, pipe_seq->job_name, is_background);
	}
	return (0);
}
// TODO fix norme
