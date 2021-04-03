/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:27:09 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/02 18:27:20 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

char		**env_to_envp(t_vector *env)
{
	t_var	*vars;
	char	**envp;
	size_t	i;

	i = 0;
	envp = (char **)ft_malloc((env->length + 1) * sizeof(char *));
	vars = env->array;
	while (i < env->length)
	{
		envp[i] = ft_strglue(vars[i].key, '=', vars[i].value);
		++i;
	}
	envp[i] = NULL;
	return (envp);
}
