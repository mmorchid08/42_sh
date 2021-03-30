/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:50:46 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/31 10:39:17 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_job	*new_job(t_bool is_background)
{
	t_job	job;

	job.is_background = is_background;
	job.state = RUNNING;
	job.processes = vector_init(sizeof(t_process), NULL);
	// TODO vector_push(job_list, &job) or 	add_job_to_jobs_list(&job)
	return // TODO address of job in jobs list
}
