/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:57:00 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/29 21:20:59 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	ft_execve(char *full_path, char **cmd, char **a_env)
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

void	ft_execve_scmd(char **cmd, char **a_env, t_vector **vec_pid,
	t_bool is_background)
{
	pid_t		pid;
	char		*full_path;

	pid = fork();
	if (pid == -1)
	{
		ft_strerror(EFORK, NULL, NULL, FALSE);
		return ;
	}
	set_process_group(ter_i(pid == 0, getpid(), pid), (int [1]){0},
		is_background);
	if (pid == 0)
	{
		reset_signals();
		full_path = get_full_path(cmd[0]);
		if (check_builtins(cmd[0]))
		{
			execute_builtins(cmd);
			exit(g_exit_status);
		}
		else
			ft_execve(full_path, cmd, a_env);
	}
	*vec_pid = vector_init(sizeof(pid_t), NULL);
	vector_push(*vec_pid, &pid);
}

int	exec_pt2(char ***cmd, t_vector *red, t_vector **p_vec, t_bool is_background)
{
	char	**a_env;
	char	*full_path;

	a_env = env_to_envp(g_shell_env);
	remove_quotes_from_args(*cmd);
	full_path = get_full_path((*cmd)[0]);
	if (do_pipes_and_red(0, 0, red) == 1)
		return (-1);
	if (check_builtins((*cmd)[0]) && is_background == FALSE)
		execute_builtins(*cmd);
	else
		ft_execve_scmd(*cmd, a_env, p_vec, is_background);
	return (EXIT_SUCCESS);
}

/*void	do_value(t_vector *values)
{
	
}*/

int	execute_simple_cmd(t_simple_command *simple_cmd, t_bool is_background,
	t_bool is_interactive)
{
	t_vector	*vec_pid;
	char		**cmd;

	vec_pid = NULL;
	vector_push(simple_cmd->args, &(char *){NULL});
	cmd = (char **)simple_cmd->args->array;
	//do_values(simple_cmd->assignments);
	if (cmd[0] && cmd)
		if (exec_pt2(&cmd, simple_cmd->redirections, &vec_pid, is_background)
			== -1)
			return (-1);
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
