/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:15:48 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/30 12:55:19 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int			main(int ac, char *av[], char *envp[])
{
	char *cmd;

	(void)envp;
	signal(SIGTSTP, SIG_IGN);
	if (ac == 3 && ft_strcmp(av[1], "-c") == 0)
		(void)parser(av[2]);
	else if (ac == 1)
	{
		if (get_next_line(STDIN_FILENO, &cmd) != -1)
			(void)parser(cmd);
	}
	else
		ft_printf(2, "Error\nusage: ./21sh [-c command]\n");
	return (0);
}
