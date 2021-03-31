/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:01:18 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/31 19:13:43 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void		print_env(t_vector *env, t_bool print_exported_only)
{
	t_var	*env_vars;
	size_t	i;

	i = 0;
	env_vars = env->array;
	while (i < env->length)
	{
		if (print_exported_only == FALSE || env_vars[i].is_exported == TRUE)
			ft_printf(1, "%s=\"%s\"", env_vars[i].key, env_vars[i].value);
		++i;
	}
}

t_bool		is_valid_identifier(char *name)
{
	size_t	i;

	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (FALSE);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		++i;
	}
	return (TRUE);
}
