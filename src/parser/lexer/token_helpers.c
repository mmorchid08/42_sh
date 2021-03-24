/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:56:32 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/24 16:57:22 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_bool	is_redirection_op(t_token_type type)
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

t_bool	is_separator(t_token_type type)
{
	return (type == SEMI || type == SEMI || type == NEWLINE);
}