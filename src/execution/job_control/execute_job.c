/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:21:23 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 12:28:41 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	execute_job(t_vector *pids_vec, char *job_name, t_bool is_background)
{
	size_t	i;
	pid_t	*pid;
	t_job	*job;

	if (pids_vec == NULL || pids_vec->length == 0)
	{
		ft_printf(2, "42sh: job has no process");
		return (1);
	}
	if (pids_vec->length > 0)
		job = new_job(is_background, job_name);
	i = 0;
	while (i < pids_vec->length)
	{
		pid = vector_get(pids_vec, i);
		add_process_to_job(job, *pid);
		i++;
	}
	vector_free(pids_vec);
	job->ret_pid = *pid;
	if (is_background)
		ft_printf(1, "[%d] %d\n", job->id, job->ret_pid);
	else
		return (get_exit_code(wait_job(job)));
	return (0);
}
