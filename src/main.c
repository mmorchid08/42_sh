/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:15:48 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/16 17:19:54 by hmzah            ###   ########.fr       */
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
	char *cmd;

	(void)envp;
	(void)av;
	(void)ac;
	g_term_fd = open("/dev/tty", O_RDWR);
	if (g_term_fd == -1)
		ft_strerror(EOPENFILE,"open", NULL, TRUE);
	init_jobs(void)
	return (0);
}
