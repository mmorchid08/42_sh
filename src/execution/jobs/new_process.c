/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:48:32 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/31 13:50:44 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_process	new_process(pid_t pid)
{
	t_process	proc;

	proc.state = RUNNING;
	proc.wait_status = 0;
	proc.pid = pid;
	return (proc);
}
