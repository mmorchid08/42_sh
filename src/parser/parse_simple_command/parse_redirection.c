/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:52:38 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/24 16:58:04 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

int		parse_redirection(t_simple *sim)
{
	t_redirection redirect;

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
	redirect.righ_fd = sim->current_token.data;
	vector_push(sim->cmd->redirections, &redirect);
	return (EXIT_SUCCESS);
}