/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:41:18 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:08:41 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

t_bool	g_is_interrupted;

static void	sigwinch_handler(int signum)
{
	(void)signum;
	update_win_dimensions();
}

static void	sigint_handler(int signum)
{
	(void)signum;
	ft_putstr("^C");
	goto_end();
	ft_putchar('\n');
	ioctl(0, TIOCSTI, "\0");
	g_is_interrupted = TRUE;
}

void	set_signal_handlers(T_SIGHANDLER *signals)
{
	signals[SIGINT_HANDLER] = signal(SIGINT, sigint_handler);
	signals[SIGWINCH_HANDLER] = signal(SIGWINCH, sigwinch_handler);
}

void	restore_signal_handlers(T_SIGHANDLER *signals)
{
	signal(SIGINT, signals[SIGINT_HANDLER]);
	signal(SIGWINCH, signals[SIGWINCH_HANDLER]);
}
