/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:01:18 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/02 18:28:18 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_vector	*env_init(char **envp)
{
	t_vector	*env;
	t_var		var;
	size_t		equal_index;

	env = vector_init(sizeof(t_var), del_var);
	while (*envp)
	{
		equal_index = ft_strichr(*envp, '=');
		if (equal_index == -1)
			continue ;
		var.key = ft_strsub(*envp, 0, equal_index);
		if (ft_strequ(var.key, "SHELL"))
			var.value = ft_strdup("42sh");
		else
			var.value = ft_strdup(*envp + equal_index + 1);
		var.is_exported = TRUE;
		vector_push(env, &var);
		++envp;
	}
	return (env);
}
