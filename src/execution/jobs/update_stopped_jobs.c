/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stopped_jobs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:43:06 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/06 18:57:51 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_vector	*g_stopped_jobs_ids;

void	update_stopped_jobs(t_job *job)
{
	int	i;

	i = 0;
	if (job->state == STOPPED)
		vector_push(g_stopped_jobs, job->id);
	else
	{
		while (i < g_stopped_jobs->length)
		{
			if (*(int*)vector_get(g_stopped_jobs, i) == job->id)
			{
				vector_remove(g_stopped_jobs, i);
				break;
			}
			i++;
		}
	}
}