/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_history_allocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:12:57 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	free_history_allocs(void)
{
	t_history_state	*const	hist = &g_history;
	t_readline_state *const	rl = &g_rl_state;

	if (hist->current_entry != -1 &&
			rl->lines == hist->entries->array[hist->current_entry].temp)
	{
		vector_free((t_vector*)rl->lines);
		hist->entries->array[hist->current_entry].temp = NULL;
		hist->entries->array[hist->current_entry].is_dirty = 0;
	}
	vector_free((t_vector*)hist->stage);
}
