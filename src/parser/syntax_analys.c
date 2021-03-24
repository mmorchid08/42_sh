/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 08:21:29 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/23 08:41:19 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static int	is_redirection(t_token_type type)
{
	return (type == DLESS ||
		type == LESS ||
		type == LESSAND ||
		type == ANDDGREAT ||
		type == ANDGREAT ||
		type == DGREAT ||
		type == GREATAND ||
		type == GREAT);
}

static int	simple_command_is_not_first_token(t_token_type type)
{
	return (type == SEMI || type == AMPERSAND || type == PIPE ||
		type == OROR || type == ANDAND);
}

int		syntax_analys(t_vector *tokens_vec)
{
	t_token			*tokens;
	t_token_type	old_token_type;
	size_t			i;

	i = 0;
	tokens = (t_token*)tokens_vec->array;
	old_token_type = START;
	while (i < tokens_vec->length)
	{
		if (old_token_type == START)
			;
		++i;
	}
	return (EXIT_SUCCESS);
}