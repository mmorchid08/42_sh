/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:28:34 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/02 18:36:38 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	env_set(t_vector *env, char *key, char *value)
{
	t_var	*vars;
	t_var	new_var;
	char	*tmp;
	size_t	i;

	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
		{
			tmp = vars[i].value;
			vars[i].value = ft_strdup(value);
			free(tmp);
			return ;
		}
		++i;
	}
	new_var.key = ft_strdup(key);
	new_var.value = ft_strdup(value);
	vector_push(env, &new_var);
}

void	env_unset(t_vector *env, char *key)
{
	t_var	*vars;
	size_t	i;

	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
		{
			vector_remove(env, i);
			return ;
		}
		++i;
	}
}

void	env_set_is_exported(t_vector *env, char *key, t_bool is_exported)
{
	t_var	*vars;
	size_t	i;

	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
		{
			vars[i].is_exported = is_exported;
			return ;
		}
		++i;
	}
}
