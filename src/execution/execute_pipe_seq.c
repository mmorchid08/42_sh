/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_seq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:58:09 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/15 16:57:24 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	manage_pipes(t_bool is_true)
{
	static int		fd[2];

	if (is_true == true)
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

pid_t		execute_pip_pt2(char **args, char **a_env, t_bool is_end))
{
	pid_t	pid;
	char	*full_path;
	int		fd;
	int		is_cmd;

	fd = manage_pipes(is_end);
	pid = fork();
	if (pid == -1)
	{
		ft_printf(2, "Error forking.\n");
		return (-1);
	}
	else if (pid == 0)
	{
		full_path = get_full_path(args[0], g_shell_env);
		if (fd != -1)
			close(fd);
		if (execve(full_path, args, a_env))
		{
			ft_printf(2, "Error executing\n");
			exit(127);
			return (-1)
		}
	}
	else
	{
		backups(2);
		return (pid);
	}
}

t_vector	*execute_pip(t_simple_command *cmd, int len)
{
	t_vector	*vec_pid;
	char		**args;
	char		**a_env;
	pid_t		pid;
	int			i;

	i = 0;
	vec_pid = vector_init(sizeof(pid_t), free);
	while (i < len)
	{
		args = cmd[i].args->array;
		a_env = env_to_array(g_shell_env);
		if ((pid = execute_pip_pt2(args, a_env, (i + 1 != len))) == -1)
		{
			ft_free_strings_array(a_env);
			return (NULL);
		}
		else
			vector_push(vec_pid, pid);
		i++;
	}
}

int	execute_pipe_seq(t_pipe_sequence *pipe_seq, t_bool is_background,
			t_bool is_interactive)
{
	t_simple_command	*s_cmd;
	t_vector			*vec_pid;
	char				**a_env;
	int 				i;

	i = 0;
	s_cmd = (t_simple_command *)pipe_seq->commands->array;
	vec_pid = execute_pip(s_cmd, pipe_seq->commands->length);
	if (vec_pid)
	{
		if (is_interactive == FALSE)
			return (wait_children(pid));
		else
			execute_job(vec_pid, pipe_seq->job_name, is_background);
	}
	return (0);
}
// TODO fix norme
