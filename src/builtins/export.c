/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:28:27 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/05 11:18:23 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

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

int		parse_options(char **av, t_bool *option_n, t_bool *option_p)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (ft_strequ(av[i], "--"))
			return (i + 1);
		if (av[i][0] == '-')
		{
			if (parse_opt(av[i], option_n, option_p) == EXIT_FAILURE)
				return (-1);
		}
		else
			break ;
		++i;
	}
	return (i);
}

int		export_args(char **av, t_bool option_n)
{
	t_var	*var;
	size_t	i;
	int		ret_status;

	i = 0;
	ret_status = EXIT_SUCCESS;
	while (av[i])
	{
		var = string_to_var(av[i]);
		if (!is_valid_identifier(var->key))
		{
			ft_printf(1, "42sh: export: `%s\': not a valid identifier", av[i]);
			ret_status = EXIT_FAILURE;
			continue ;
		}
		if (option_n || var->value == NULL)
			env_set_exported(g_shell_env, var->key, !option_n);
		else
			env_set(g_shell_env, var->key, var->value, TRUE);
		++i;
	}
	return (ret_status);
}

int		export(char **av)
{
	t_bool	option_n;
	t_bool	option_p;
	int		first_name_index;

	first_name_index = parse_options(av, &option_n, &option_p);
	if (first_name_index == -1)
		return (EXIT_FAILURE);
	if (av[first_name_index] == NULL)
		env_print(g_shell_env, TRUE);
	if (export_args(av, option_n) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
