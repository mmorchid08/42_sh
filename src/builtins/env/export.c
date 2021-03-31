/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:28:27 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/31 19:58:01 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

int		parse_opt(char *arg, t_bool *option_n, t_bool *option_p)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'n')
			*option_n = TRUE;
		else if (arg[i] == 'p')
			*option_p = TRUE;
		else
		{
			ft_printf(2, "21sh: export: -%c: invalid option\n", arg[i]);
			ft_printf(2, "export: usage: export -[np] [name[=value] ...]\n");
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

size_t	parse_options(char **a

int		export(char **args)
{
	t_bool	option_n;
	t_bool	option_p;
	size_t	args_index;

	args_index = parse_options(args, &option_n, &option_p);
	if (args_index == -1)
		return (EXIT_FAILURE);
	if (args[args_index] == NULL)
		print_env(g_shell_env, TRUE);
	if (option_n == TRUE)
	{
		if (export_option_n() == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
