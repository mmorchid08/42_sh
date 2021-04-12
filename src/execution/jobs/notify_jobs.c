/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notify_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:56:32 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/11 14:17:40 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	notify_job_state(void)
{
	int		i;
	t_job	*job;

	i = 0;
	while (i < g_job_list->length)
	{
		job = vector_get(g_job_list, i);
		if (job->to_notify && job->is_background)
		{
			print_job(job);
			job->to_notify = FALSE;
			if (job->state == COMPLETED)
				remove_from_job_list(job->id);
		}
	}
}
