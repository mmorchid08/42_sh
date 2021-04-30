/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 00:11:22 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/28 00:25:38 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

int	unset(char **av)
{
	size_t	i;
	int		ret_status;

	i = 0;
	ret_status = EXIT_SUCCESS;
	while (av[i])
	{
		if (!is_valid_identifier(av[i]))
		{
			ft_printf(1, "42sh: unset: `%s\': not a valid identifier", av[i]);
			ret_status = EXIT_FAILURE;
			continue ;
		}
		env_unset(g_shell_env, av[i]);
		++i;
	}
	return (ret_status);
}