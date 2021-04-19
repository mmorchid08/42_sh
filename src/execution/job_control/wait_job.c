/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:22:47 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/19 23:28:31 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	wait_job(t_job *job)
{
	pid_t	pid;
	int		wait_status;
	int		recent_stop_sig;

	while (1)
	{
		pid = waitpid(-job->pgid, &wait_status, WUNTRACED);
		if (pid == -1)
			break ;
		if (WIFSTOPPED(wait_status))
			recent_stop_sig = WSTOPSIG(wait_status);
		if (job->ret_pid == pid)
			job->wait_status = wait_status;
		update_job_state(job, pid, wait_status);
		if (job->state == STOPPED)
		{
			job->is_background = TRUE;
			tcsetpgrp(g_term_fd, getpgrp());
			return (128 + recent_stop_sig);
		}
	}
	tcsetpgrp(g_term_fd, getpgrp());
	return (get_exit_code(job->wait_status));
}
