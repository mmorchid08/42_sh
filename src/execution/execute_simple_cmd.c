/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:57:00 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/16 17:21:35 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_vector	*ft_execve_scmd(char *full_path, char **cmd, char **a_env)
{
	t_vector	*vec_pid;
	pid_t		pid;

	vec_pid = NULL;
	pid = fork();
	if (pid == -1)
	{
		ft_printf(2, "Error forking\n");
		return (NULL);
	}
	else if (pid == 0)
	{
		if (execve(full_path, cmd, a_env) == -1)
		{
			ft_printf(2, "Error\n");
			exit(127);
			return (NULL);
		}
	}
	else
	{
		vec_pid = vector_init(sizeof(pid_t), free);
		vector_push(vec_pid, &pid);
	}
	return (vec_pid);
}

int		execute_simple_cmd(t_simple_command *simple_cmd, t_bool is_background,
	t_bool is_interactive)
{
	t_vector	*vec_pid;
	char		*full_path;
	char		**cmd;
	char		**a_env;
	int			i;

	vec_pid = NULL;
	cmd = (char **)simple_cmd->args->array;
	full_path = get_full_path(cmd[0]);
	a_env = g_shell_env;
	i = 0;
	while (cmd[i])
		remove_quotes(&cmd[i++]);
	vec_pid = ft_execve_scmd(full_path, cmd, a_env);
	if (vec_pid != NULL)
	{
		if (is_interactive == FALSE)
			return (get_exit_code(wait_children((pid_t)vec_pid->array)));
		else
			return (execute_job(vec_pid, simple_cmd->job_name, is_background));
	}
	return (1);
}
