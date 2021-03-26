/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:56:32 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/26 09:20:44 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_bool	lexer_is_redirection(t_token_type type)
{
	return (type == IO_NUMBER ||
		type == GREAT ||
		type == ANDGREAT ||
		type == DGREAT ||
		type == ANDDGREAT ||
		type == LESS ||
		type == DLESS ||
		type == GREATAND ||
		type == LESSAND ||
		type == GREATANDDASH ||
		type == LESSANDDASH);
}

t_bool	lexer_is_separator(t_token_type type)
{
	return (type == SEMI || type == AMPERSAND || type == NEWLINE);
}
t_bool	lexer_is_and_or(t_token_type type)
{
	return (type == ANDAND || type == OROR);
}
