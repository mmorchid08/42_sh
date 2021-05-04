/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_dynstr_vec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:54:02 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 10:07:52 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

t_dynstr_vector	*str_to_dynstr_vec(char *str)
{
	char			**lines;
	int				i;
	t_dyn_str		dynstr;
	t_dynstr_vector	*dynstr_vec;

	if (str == NULL)
		return (NULL);
	dynstr_vec = (void *)vector_init(sizeof(t_dyn_str), free_dyn_str);
	i = 0;
	lines = ft_strsplit2(str, '\n', ALLOW_EMPTY_WORD);
	while (lines[i])
	{
		dyn_str_dup(&dynstr, lines[i]);
		vector_push((void *)dynstr_vec, &dynstr);
		i++;
	}
	ft_free_strings_array(lines);
	return (dynstr_vec);
}
