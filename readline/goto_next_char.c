/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_next_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 02:22:36 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	goto_next_char(void)
{
	if (g_rl_state.current_line + 1 == g_rl_state.lines->length &&
			g_rl_state.cursor_line_pos ==
				g_rl_state.lines->array[g_rl_state.current_line].len)
		return ;
	else if (g_rl_state.cursor_line_pos ==
				g_rl_state.lines->array[g_rl_state.current_line].len)
	{
		move_cursor_to(g_rl_state.current_line + 1, 0);
	}
	else
		move_cursor_to(g_rl_state.current_line, g_rl_state.cursor_line_pos + 1);
}
