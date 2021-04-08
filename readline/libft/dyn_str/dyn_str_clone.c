/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_clone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:25:53 by mel-idri          #+#    #+#             */
/*   Updated: 2020/12/12 14:33:51 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

t_dyn_str	*dyn_str_clone(t_dyn_str *container, t_dyn_str *old_dyn_str)
{
	t_dyn_str	*new_dyn_str;

	if (old_dyn_str == NULL)
		return (NULL);
	if (container == NULL)
		new_dyn_str = safe_malloc(sizeof(t_dyn_str));
	else
		new_dyn_str = container;
	new_dyn_str->str = safe_malloc(old_dyn_str->capacity);
	new_dyn_str->str[0] = '\0';
	ft_strcpy(new_dyn_str->str, old_dyn_str->str);
	new_dyn_str->len = old_dyn_str->len;
	new_dyn_str->capacity = old_dyn_str->capacity;
	return (new_dyn_str);
}
