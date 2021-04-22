/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:52:38 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/22 11:03:14 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	handle_syntax_error(t_parse_simple *sim)
{
	if (sim->current_token.type == NA)
	{
		g_errno = ESYNTAX;
		return ;
	}
	unexpected_token(sim->current_token.type);
}

int		parse_redirection(t_parse_simple *sim)
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
	{
		handle_syntax_error(sim);
		return (EXIT_FAILURE);
	}
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
