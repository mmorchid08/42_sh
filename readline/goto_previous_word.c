/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_previous_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:21:07 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void			goto_previous_word(void)
{
	t_readline_state *const	rl = &g_rl_state;
	int						i;
	int						j;

	j = rl->current_line;
	i = rl->cursor_line_pos - 1;
	if (i < 0)
		i = rl->lines->array[--j].len;
	while (j >= 0)
	{
		while (i >= 0 && !ft_isalnum(rl->lines->array[j].str[i]))
			i--;
		if (i >= 0 && ft_isalnum(rl->lines->array[j].str[i]))
			break ;
		j--;
		i = rl->lines->array[j].len - 1;
	}
	if (j < 0)
	{
		goto_home();
		return ;
	}
	while (i >= 0 && ft_isalnum(rl->lines->array[j].str[i]))
		i--;
	move_cursor_to(j, i < 0 ? 0 : i + 1);
}
