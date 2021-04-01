/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_seq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:58:09 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/06 13:02:17 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	execute_pipe_seq(t_pipe_sequence *pipe_seq, t_bool is_background,
			t_bool is_interactive)
{
	pid_t	pid;
	t_job	*job;
	int 	i;

	i = 0;
	if (is_interactive)
			job = new_job(is_background);
	while (i < pipe_seq->commands->length)
	{
		// TODO pipe prep
		if ((pid = fork()) == 0)
			;// hmzah_child_code
		else if (pid < 0)
		{
			// TODO handle fork error
			// TODO free job and kill all processes
			return (-1);
		}
		// hmzah parent code 
		if (is_interactive)
			add_process_to_job(job, pid);
	}
	if (is_interactive == FALSE)
		return (wait_children(pid));
	job->ret_pid = pid;
	if (is_background)
		return (wait_job(job));
	return (0);
}
// TODO fix norme
