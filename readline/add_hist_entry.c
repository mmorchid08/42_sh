/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hist_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:08:18 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/07 10:49:39 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

void	add_hist_entry(char *entry_str)
{
	t_hist_entry hist_entry;

	hist_entry.temp = NULL;
	hist_entry.is_dirty = FALSE;
	hist_entry.entry = str_to_dynstr_vec(entry_str);
	vector_push((void*)g_history.entries, &hist_entry);
}
