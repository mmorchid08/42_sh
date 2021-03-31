/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_logic_seq.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:42:48 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/30 16:50:25 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	execute_logic_seq_background(t_logic_sequence logic_seq)
{
	pid_t	pid;
	t_job	job;

	job = new_job(TRUE);
	pid = fork();
	if (pid == 0)
	{
		logic_seq_executor(logic_seq, TRUE, FALSE);
	}
	else if (pid < 0)
	{
		// TODO handle fork error
	}
	else
	{

	}
}
