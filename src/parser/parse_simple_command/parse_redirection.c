/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:52:38 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/25 18:21:09 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

int		parse_redirection(t_simple *sim)
{
	t_redirection	redirect;
	int				here_doc_fd;

	if (sim->current_token.type == IO_NUMBER)
	{
		redirect.left_fd = ft_atoi(sim->current_token.data);
		simple_advance(sim);
	}
	else
		redirect.left_fd = -1;
	redirect.type = sim->current_token.type;
	simple_advance(sim);
	if (sim->current_token.type != WORD)
		return (EXIT_FAILURE);
	if (redirect.type == DLESS)
	{
		here_doc_fd = parse_here_doc(sim->current_token.data);
		if (here_doc_fd == -1)
			return (EXIT_FAILURE);
		redirect.righ_fd = ft_itoa(here_doc_fd);
	}
	redirect.righ_fd = sim->current_token.data;
	vector_push(sim->cmd->redirections, &redirect);
	return (EXIT_SUCCESS);
}