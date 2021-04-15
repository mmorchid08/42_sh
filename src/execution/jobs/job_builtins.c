/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:22:37 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/11 18:05:16 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static int	print_selected_jobs(char **selectors, t_job_print_mode mode,
	t_special_jobs *special_jobs)
{
	int		ret;
	int		i;
	t_job	*job;

	ret = 0;
	i = 0;
	while (selectors[i])
	{
		job = get_job_by_selector(selectors[i]);
		if (job == NULL)
		{
			ret = 1;
			ft_printf(2, "42sh: jobs: %s no such job\n", selectors[i]);
		}
		else
			print_job(job, mode, special_jobs);
		i++;
	}
	return (ret);
}

int	fg(char **args)
{
	t_job	*job;

	if (args[0])
		job = get_job_by_selector(args[0]);
	else
		job = get_current_job();
	if (job == NULL)
	{
		ft_printf(2, "42sh: fg: no such job\n"); // TODO use ft_setrerror instead
		return (1);
	}
	ft_printf(1, "%s\n", job->job_name);
	job->is_background = FALSE;
	tcsetpgrp(g_term_fd, job->pgid);
	kill(-job->pgid, SIGCONT);
	update_job(job);
	return (wait_job(job));
}

int	bg(char **args)
{
	int		ret;
	int		i;
	t_job	*job;

	i = 0;
	ret = 0;
	while (*args)
	{
		job = get_job_by_selector(*args);
		if (job == NULL)
		{
			ret = 1;
			ft_printf(2, "42sh: fg: %s no such job\n", *args); // TODO use ft_setrerror instead
			args++;
			continue ;
		}
		kill(-job->pgid, SIGCONT);
		update_job(job);
		ft_printf(1, "[%d] %s\n", job->id, job->job_name);
		args++;
	}
	return (ret);
}

int	jobs(char **args)
{
	t_job_print_mode	mode;
	t_job				*job;
	int					i;
	int					ret;
	t_special_jobs		special_jobs;

	mode = NORMAL;
	if (ft_strequ(args[0], "-p") && args++)
		mode = PGID;
	else if (ft_strequ(args[0], "-l") && args++)
		mode = LONG;
	special_jobs.current = get_current_job();
	special_jobs.previous = get_previous_job();
	i = 0;
	if (*args == NULL)
	{
		while (i < g_job_list->length)
			print_job(vector_get(g_job_list, i++), mode, &special_jobs);
		return (0);
	}
	ret = print_selected_jobs(args, mode, &special_jobs);
	return (ret);
}