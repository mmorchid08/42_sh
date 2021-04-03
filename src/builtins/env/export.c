/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:28:27 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/03 11:26:49 by ylagtab          ###   ########.fr       */
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

int		parse_options(char **args, t_bool *option_n, t_bool *option_p)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (ft_strequ(args[i], "--"))
			return (i + 1);
		if (args[i][0] == '-')
		{
			if (parse_opt(args[i], option_n, option_p) == EXIT_FAILURE)
				return (-1);
		}
		else
			break ;
		++i;
	}
	return (i);
}

int		export_option_n(char **args)
{

}

int		export(char **args)
{
	t_bool	option_n;
	t_bool	option_p;
	int		args_index;

	args_index = parse_options(args, &option_n, &option_p);
	if (args_index == -1)
		return (EXIT_FAILURE);
	if (args[args_index] == NULL)
		print_env(g_shell_env, TRUE);
	if (option_n == TRUE)
	{
		if (export_option_n(args) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
