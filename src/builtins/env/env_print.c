/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:27:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/02 18:27:52 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void		env_print(t_vector *env, t_bool print_exported_only)
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
