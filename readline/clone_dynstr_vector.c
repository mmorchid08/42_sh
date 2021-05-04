/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_dynstr_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:50:41 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:22:34 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

t_dynstr_vector	*clone_dynstr_vector(t_dynstr_vector *orig_dynstr_vector)
{
	t_dynstr_vector	*vec;
	size_t			i;

	if (orig_dynstr_vector == NULL)
		return (NULL);
	i = 0;
	vec = (t_dynstr_vector *)safe_malloc(sizeof(t_vector));
	*vec = *orig_dynstr_vector;
	vec->array = (t_dyn_str *)safe_malloc(vec->capacity * sizeof(t_dyn_str));
	while (i < vec->length)
	{
		dyn_str_clone(vec->array + i, orig_dynstr_vector->array + i);
		i++;
	}
	return (vec);
}
