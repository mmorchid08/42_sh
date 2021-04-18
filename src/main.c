/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:15:48 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/18 07:46:41 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int
g_exit_status;

int
g_term_fd;

t_vector
*g_shell_env;

int	main(int ac, char **av, char **envp)
{
	char		*cmd;
	t_vector	*vec;

	(void)av;
	(void)ac;
	(void)envp;
	g_term_fd = open("/dev/tty", O_RDWR);
	if (g_term_fd == -1)
		ft_strerror(EOPENFILE,"open", NULL, TRUE);
	init_jobs();
	while (42)
	{
		write(1, "$> ", 3);
		get_next_line(0, &cmd);
		vec = parser(cmd);
		if (vec)
			execute_commands(vec);
		ft_strdel(&cmd);
	}
	return (0);
}
