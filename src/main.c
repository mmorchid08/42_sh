/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:15:48 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/24 15:06:26 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	shell_main(void)
{
	t_vector	*commands;
	char		*cmd_line;

	(void)commands;
	cmd_line = read_cmd_multiline();
	if (cmd_line)
		commands = parser(cmd_line);
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[], char *envp[])
{
	(void)envp;
	signal(SIGTSTP, SIG_IGN);
	if (ac == 3 && ft_strcmp(av[1], "-c") == 0)
		(void)parser(av[2]);
	else if (ac == 1)
	{
		while (1)
			(void)shell_main();
	}
	else
		ft_printf(2, "Error\nusage: ./21sh [-c command]\n");
	return (0);
}
