/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:57:08 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/05 12:07:44 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static char		*escape_string(char *str)
{
	t_string	*escaped_str;
	size_t		i;

	escaped_str = string_new();
	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
			string_push(escaped_str, BACK_SLASH);
		string_push(escaped_str, str[i]);
		++i;
	}
	return (string_get_data(escaped_str));
}

char			*env_get(t_vector *env, char *key)
{
	t_var	*vars;
	size_t	i;

	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
			return (escape_string(vars[i].value));
		++i;
	}
	return (NULL);
}
