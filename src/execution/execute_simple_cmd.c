/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:57:00 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/07 19:11:31 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	execute_simple_cmd(t_simple_command *simple_cmd, t_bool is_background,
	t_bool is_interactive)
{
	pid_t	pid;
	t_job	*job;

	pid = fork();
	if (pid == 0)
	{
		;// TODO dup pipes if any then execve, exit if error
	}
	else if (pid < 0)
	{
		// TODO fork error
		return (-1); // TODO error
	}
	// TODO hatim parent code
	if (is_interactive == FALSE)
		return (get_exit_code(wait_children(pid)));
	job = new_job(is_background);
	add_process_to_job(job, pid);
	job->ret_pid = pid;
	if (is_background)
		return (get_exit_code(wait_job(job)));
	return (0);
}
