/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:15:48 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/28 15:57:49 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_vector
*g_stopped_jobs;

int
g_exit_status;

int
g_term_fd;


int	shell_main(void)
{
	t_vector	*commands;
	char		*cmd_line;

	update_all_jobs();
	notify_job_state();
	cmd_line = read_cmd_multiline();
	if (cmd_line)
	{
		commands = parser(cmd_line);
		if (commands && commands->length > 0)
			execute_commands(commands);
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[], char *envp[])
{
	(void)av;
	g_shell_env = env_init(envp);
	g_term_fd = open("/dev/tty", O_RDWR);
	if (g_term_fd == -1)
		ft_strerror(EOPENFILE,"open", NULL, TRUE);
	init_jobs();
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	if (ac == 1)
	{
		while (1)
			(void)shell_main();
	}
	else
		ft_printf(2, "Error\nusage: ./21sh [-c command]\n");
	return (0);
}
