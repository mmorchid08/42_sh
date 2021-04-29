/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 00:01:00 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/29 14:04:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	set(char **av)
{
	size_t	i;
	t_var	*vars;

	if (ft_strings_array_length(av) > 0)
	{
		ft_printf(2, "42sh: set: wrong number of arguments");
		return (EXIT_FAILURE);
	}
	i = 0;
	vars = g_shell_env->array;
	while (i < g_shell_env->length)
	{
		if (vars[i].is_exported == FALSE)
			ft_printf(1, "%s=%s\n", vars[i].key, vars[i].value);
		++i;
	}
	return (EXIT_SUCCESS);
}
