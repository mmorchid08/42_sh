/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:50:46 by mel-idri          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/31 10:39:17 by mel-idri         ###   ########.fr       */
=======
/*   Updated: 2021/04/11 17:55:52 by mel-idri         ###   ########.fr       */
>>>>>>> origin/job_control
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

<<<<<<< HEAD
t_job	*new_job(t_bool is_background)
{
	t_job	job;

	job.is_background = is_background;
	job.state = RUNNING;
	job.processes = vector_init(sizeof(t_process), NULL);
	// TODO vector_push(job_list, &job) or 	add_job_to_jobs_list(&job)
	return // TODO address of job in jobs list
=======
t_job	*new_job(t_bool is_background, char *job_name)
{
	t_job	job;

	ft_bzero(&job, sizeof(t_job));
	job.is_background = is_background;
	job.state = RUNNING;
	job.job_name = job_name;
	job.processes = vector_init(sizeof(t_process), NULL);
	add_to_job_list(&job); // TODO make sure init_jobs is called at shell startup
	return vector_get(g_job_list, g_job_list->length - 1);
>>>>>>> origin/job_control
}
