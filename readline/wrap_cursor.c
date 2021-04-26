/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:52:54 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	wrap_cursor(void)
{
	t_readline_state *const	rl = &g_rl_state;

	if ((rl->cursor_line_pos + (rl->current_line == 0 ? rl->prompt_len : 0)) %
			rl->win_cols == 0)
	{
		ft_putchar(' ');
		tputs(tgetstr("le", NULL), 1, ft_putchar);
	}
}
