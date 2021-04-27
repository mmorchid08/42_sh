/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:52:38 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/27 12:51:57 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static int	syntax_error(t_parse_simple *sim)
{
	if (sim->current_token.type == NA)
		g_errno = ESYNTAX;
	else
		unexpected_token(sim->current_token.type);
	return (EXIT_FAILURE);
}

int	parse_redirection(t_parse_simple *sim)
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
	if (sim->current_token.type != WORD || sim->current_token.type == NA)
		return (syntax_error(sim));
	if (redirect.type == DLESS)
	{
		here_doc_fd = parse_here_doc(sim->current_token.data);
		if (here_doc_fd == -1)
			return (EXIT_FAILURE);
		redirect.righ_fd = ft_itoa(here_doc_fd);
	}
	else
		redirect.righ_fd = ft_strdup(sim->current_token.data);
	vector_push(sim->cmd->redirections, &redirect);
	return (EXIT_SUCCESS);
}
