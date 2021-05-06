/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:29:53 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 11:40:53 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static void	sig_handler(int signum)
{
	t_job	*job;

	if (signum == SIGINT)
		ft_putchar('\n');
	else if (signum == SIGHUP)
	{
		while (g_job_list->length > 0)
		{
			job = vector_get(g_job_list, 0);
			kill(-job->pgid, SIGHUP);
			vector_remove(g_job_list, 0);
		}
	}
}

void	reset_signals(void)
{
	signal(SIGTERM, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGHUP, SIG_DFL);
}

void	setup_disabled_job_signals(void)
{
	signal(SIGTERM, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
}

void	setup_enabled_job_signals(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handler);
	signal(SIGHUP, sig_handler);
}
