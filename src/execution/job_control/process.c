/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:54:34 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/23 17:52:24 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static t_process	new_process(pid_t pid)
{
	t_process	proc;

	proc.state = RUNNING;
	proc.wait_status = 0;
	proc.pid = pid;
	return (proc);
}

void	add_process_to_job(t_job *job, pid_t pid)
{
	t_process	proc;

	if (job->processes->length == 0)
	{
		setpgid(pid, pid);
		job->pgid = pid;
		if (job->is_background == FALSE)
			tcsetpgrp(g_term_fd, job->pgid);
	}
	else
		setpgid(pid, job->pgid);
	proc = new_process(pid);
	vector_push(job->processes, &proc);
	job->count.running++;
}

t_process	*get_process_from_job(t_job *job, pid_t pid)
{
	t_process *const	proc_array = job->processes->array;
	size_t				i;

	i = 0;
	while (i < job->processes->length)
	{
		if (pid == proc_array[i].pid)
			return (proc_array + i);
		i++;
	}
	return (NULL);
}

void	remove_process_from_job(t_job *job, pid_t pid)
{
	t_process *const	proc_array = job->processes->array;
	size_t				i;

	i = 0;
	while (i < job->processes->length)
	{
		if (pid == proc_array[i].pid)
		{
			vector_remove(job->processes, i);
			return ;
		}
		i++;
	}
}
