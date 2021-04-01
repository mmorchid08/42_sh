/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:22:43 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/30 14:02:31 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

/*int			ft_execve(char **args)
{
	char	**env;
	char	*full_path;
	int		exit_status;
	int		pid;

	full_path = get_executable_pathname(args[0]);
	env = shell_env_to_envp(g_shell_env);
	if ((pid = fork()) == -1)
	{
		ft_strerror(EFORK, NULL, NULL, FALSE);
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(full_path, args, env) == -1)
			;//check for what error
	}
	else
		waitpid(pid, &exit_status, 0);
	ft_strdel(&full_path);
	ft_free_strings_array(env);
}

int			execute_simple_cmd(t_simple_command *cmd, t_bool is_job)
{
	char	**args;
	int		exit_status;

	args = (char **)cmd->args->array;
	/*
	**	TODO: Do redirections. And remove quotes.
	**
	if (is_builtins(args[0]))
		exit_status = do_builtins(args);
	else
		exit_status = ft_execve(args);
	return (exit_status);
}*/

int	execute_simple_cmd(t_simple_command *simple_cmd, t_bool is_background,
	t_bool is_interactive)
{
	pid_t	pid;
	t_job	*job;
	char	**args;
	char	*full_path;
	char	**env;
	int		exit_status;

	//TODO: talk to mohamed about if he needs the fork to be in the same fun.
	pid = fork();
	args = (char **)simple_cmd->args->array;
	full_path = get_executable_pathname(args[0]);
	env = shell_env_to_envp(g_shell_env);
	if (pid == 0)
	{
		// TODO dup pipes if any then execve, exit if error. Also thinking about spliting.
		// since this will be a simple command execution, there will be no pipes.
		if (execve(full_path, args, env) == -1)
			; // check for what type of error.
	}
	else if (pid < 0)
	{
		ft_strerror(EFORK, NULL, NULL, FALSE);
		return (EXIT_FAILURE); // TODO error
	}
	else
	{
		waitpid(pid, &exit_status, 0);
		ft_strdel(&full_path);
		ft_free_strings_array(env);
	}
	// TODO hatim parent code
	if (is_interactive == FALSE)
		return (wait_children(pid));
	job = new_job(is_background);
	add_process_to_job(job, pid);
	job.ret_pid = pid;
	if (is_background)
		return (wait_job(job));
	return (0);
}