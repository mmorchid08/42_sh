/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_hist_entry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:15:24 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

char	*get_last_hist_entry(void)
{
	t_dynstr_vector	*last_hist_entry;

	if (g_history.entries->length == 0)
		return (NULL);
	last_hist_entry =
		g_history.entries->array[g_history.entries->length - 1].entry;
	return (dynstr_vec_to_str(last_hist_entry));
}
