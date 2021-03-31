/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:37:39 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/31 18:25:31 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_vector	*g_internal_vars;
t_vector	*g_shell_env;

int		set_var(t_vector *env, char *key, char *value)
{
	t_var	var;

	if (env == NULL || key == NULL || value == NULL)
		return (EXIT_FAILURE);
	var.key = ft_strdup(key);
	var.value = ft_strdup(value);
	unset_var(env, key);
	vector_push(env, &var);
	return (EXIT_SUCCESS);
}

int		unset_var(t_vector *env, char *key)
{
	t_var	*vars;
	size_t	i;

	if (env == NULL || key == NULL)
		return (EXIT_FAILURE);
	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
		{
			vector_remove(env, i);
			break ;
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int		set_shell_env_var()