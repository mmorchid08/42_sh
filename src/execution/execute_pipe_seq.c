/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_seq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:58:09 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/29 23:35:34 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"
#include <stdbool.h>

void	ft_execve_pip(char **cmd)
{
	char	*full_path;
	char	**a_env;

	full_path = get_full_path(cmd[0]);
	a_env = env_to_envp(g_shell_env);
	if (execve(full_path, cmd, a_env) == -1)
	{
		if (access(full_path, F_OK) == 0)
			ft_strerror(EACCES, cmd[0], NULL, FALSE);
		else
			ft_strerror(ENOCMD, cmd[0], NULL, FALSE);
		exit(127);
	}
}

pid_t	execute_pip_pt2(char **args, pid_t *pgid, t_bool is_background)
{
	pid_t		pid;

	pid = fork();
	if (pid == -1)
	{
		ft_strerror(EFORK, NULL, NULL, FALSE);
		return (-1);
	}
	set_process_group(ter_i(pid == 0, getpid(), pid), pgid, is_background);
	if (pid == 0)
	{
		reset_signals();
		if (check_builtins(args[0]))
		{
			execute_builtins(args);
			exit(g_exit_status);
		}
		else if (args && args[0])
			ft_execve_pip(args);
		else
			exit(0);
	}
	backups(2);
	return (pid);
}

t_vector	*execute_pip(t_simple_command *cmd, int len, t_bool is_background)
{
	t_vector	*vec_pid;
	char		**args;
	pid_t		pid;
	int			i;
	pid_t		pgid;

	i = 0;
	pgid = 0;
	vec_pid = vector_init(sizeof(pid_t), NULL);
	while (i < len)
	{
		vector_push(cmd[i].args, &(char *){NULL});
		args = (char **)cmd[i].args->array;
		remove_quotes_from_args(args);
		if (do_pipes_and_red(i, len, cmd[i].redirections) == 1)
			return (NULL);
		pid = execute_pip_pt2(args, &pgid, is_background);
		if (pid != -1)
			vector_push(vec_pid, &pid);
		else
			return (NULL);
		i++;
	}
	return (vec_pid);
}

int	execute_pipe_seq(t_pipe_sequence *pipe_seq, t_bool is_background,
			t_bool is_interactive)
{
	t_simple_command	*s_cmd;
	t_vector			*vec_pid;
	pid_t				*pid;
	pid_t				f_pid;
	int					i;

	s_cmd = (t_simple_command *)pipe_seq->commands->array;
	vec_pid = execute_pip(s_cmd, pipe_seq->commands->length, is_background);
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
