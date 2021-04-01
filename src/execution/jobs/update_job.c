/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:30:55 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/02 11:43:29 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static void	update_proc_state(t_job *job, t_process *proc, int wait_status)
{
	if (WIFEXITED(wait_status) || WIFSIGNALED(wait_status))
	{
		job->count.completed++;
		proc->state = COMPLETED;
		if (proc->pid == job->ret_pid)
			job->wait_status = wait_status;
		remove_process_from_job(job, proc->pid);
	}
	else if (WIFSTOPPED(wait_status))
	{
		job->count.stopped++;
		proc->state = STOPPED;
	}
	else if (WIFCONTINUED(wait_status))
	{
		job->count.running++;
		proc->state = RUNNING;
	}
}

void		update_job_state(t_job *job, pid_t pid, int wait_status)
{
	t_process	*proc;
	t_run_state	recent_job_state;

	proc = get_process_from_job(job, pid);
	proc->wait_status = wait_status;
	recent_job_state = job->state;
	if (proc->state == RUNNING)
		job->count.running++;
	else if (proc->state == STOPPED)
		job->count.stopped++;
	update_proc_state(job, proc, wait_status);
	if (job->count.running > 0)
		job->state = RUNNING;
	else if (job->count.stopped > 0)
		job->state = STOPPED;
	else
		job->state = COMPLETED;
	if (recent_job_state != job->state)
		job->to_notify = TRUE;
}

void		update_job()
