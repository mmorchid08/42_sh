/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:15:48 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/30 12:55:19 by ylagtab          ###   ########.fr       */
=======
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:15:48 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 17:47:06 by mel-idri         ###   ########.fr       */
>>>>>>> origin/job_control
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

<<<<<<< HEAD
int			main(int ac, char *av[], char *envp[])
=======
int
g_exit_status;

int
g_term_fd;

int	main(int ac, char **av, char **envp)
>>>>>>> origin/job_control
{
	char *cmd;

	(void)envp;
<<<<<<< HEAD
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
=======
	g_term_fd = open("/dev/tty", O_RDWR);
	if (g_term_fd == -1)
		ft_strerror(EOPENFILE,"open", NULL, TRUE);
	init_jobs(void)
>>>>>>> origin/job_control
	return (0);
}
