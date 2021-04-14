/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tokens_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:42:53 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/12 15:26:11 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void		and_or_push_cmd_token(t_parse_and_or *parser)
{
	vector_push(parser->cmd_tokens, &(parser->current_token));
	if (parser->current_token.type == PIPE)
		parser->cmd_type = PIPE_SEQ;
}
