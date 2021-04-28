/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:57:00 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/27 13:16:00 by hmzah            ###   ########.fr       */
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
		ft_strerror(EFORK, NULL, NULL, FALSE);
		return (NULL);
	}
	else if (pid == 0)
	{
		if (execve(full_path, cmd, a_env) == -1)
		{
			if (access(full_path, F_OK) == 0)
				ft_strerror(EACCES, cmd[0], NULL, FALSE);
			else
				ft_strerror(ENOCMD, cmd[0], NULL, FALSE);
			exit(127);
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
	vector_push(simple_cmd->args, &(char *){NULL});
	cmd = (char **)simple_cmd->args->array;
	if (!check_builtins(cmd[0]))
		full_path = get_full_path(cmd[0]);
	a_env = env_to_envp(g_shell_env);
	i = 0;
	while (cmd[i])
		remove_quotes(&cmd[i++]);
	if ((i = do_pipes_and_red(0, 0, simple_cmd->redirections)) == 1)
		return (-1);
	if (check_builtins(cmd[0]) && is_background == FALSE)
		execute_builtins(cmd);
	else
		vec_pid = ft_execve_scmd(full_path, cmd, a_env);
	if (vec_pid != NULL)
	{
		if (is_interactive == FALSE)
			return (get_exit_code(wait_children((pid_t)vec_pid->array)));
		else
			return (execute_job(vec_pid, simple_cmd->job_name, is_background));
	}
	else
		return (-1);
	return (0);
}
