/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:06:10 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:50:17 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

t_dyn_str	*dyn_str_dup(t_dyn_str *dyn_str, char *str)
{
	size_t	str_len;
	size_t	new_capacity;

	str_len = ft_strlen(str);
	new_capacity = ter_ul(str_len + 1 > 16,
			get_close_power_of_2(str_len + 1), 16);
	if (str == NULL)
		return (NULL);
	if (dyn_str == NULL)
		dyn_str = dyn_str_create(str_len + 1);
	else
	{
		dyn_str->capacity = new_capacity;
		dyn_str->str = safe_malloc(dyn_str->capacity);
		dyn_str->str[0] = '\0';
	}
	dyn_str->len = str_len;
	ft_strcpy(dyn_str->str, str);
	return (dyn_str);
}
