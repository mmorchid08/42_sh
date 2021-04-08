/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_print_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 08:55:27 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/08 09:50:30 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

char	*g_tokens_to_string[] = {
	[START] = "START",
	[WORD] = "WORD",
	[ASSIGNMENT] = "ASSIGNMENT",
	[IO_NUMBER] = "IO_NUMBER",
	[GREAT] = "GREAT",
	[ANDGREAT] = "ANDGREAT",
	[DGREAT] = "DGREAT",
	[ANDDGREAT] = "ANDDGREAT",
	[LESS] = "LESS",
	[DLESS] = "DLESS",
	[GREATAND] = "GREATAND",
	[LESSAND] = "LESSAND",
	[GREATANDDASH] = "GREATANDDASH",
	[LESSANDDASH] = "LESSANDDASH",
	[PIPE] = "PIPE",
	[OROR] = "OROR",
	[ANDAND] = "ANDAND",
	[SEMI] = "SEMI",
	[AMPERSAND] = "AMPERSAND",
	[NEWLINE] = "NEWLINE"
};

char	*g_tokens_to_symbol[] = {
	[START] = "START",
	[WORD] = "WORD",
	[ASSIGNMENT] = "ASSIGNMENT",
	[IO_NUMBER] = "IO_NUMBER",
	[GREAT] = ">",
	[ANDGREAT] = "&>",
	[DGREAT] = ">>",
	[ANDDGREAT] = "&>>",
	[LESS] = "<",
	[DLESS] = "<<",
	[GREATAND] = ">&",
	[LESSAND] = "<&",
	[GREATANDDASH] = ">&-",
	[LESSANDDASH] = "<&-",
	[PIPE] = "|",
	[OROR] = "||",
	[ANDAND] = "&&",
	[SEMI] = ";",
	[AMPERSAND] = "&",
	[NEWLINE] = "NEWLINE"
};

void	lexer_print_tokens(t_vector *tokens_vec)
{
	t_token	*tokens;
	t_token	tk;
	size_t	tokens_len;
	size_t	i;

	tokens = (t_token *)tokens_vec->array;
	tokens_len = tokens_vec->length;
	i = 0;
	while (i < tokens_len)
	{
		tk = tokens[i];
		ft_printf(1, g_tokens_to_string[tk.type]);
		if (tk.type == WORD || tk.type == IO_NUMBER)
			ft_printf(1, " %s", tk.data);
		ft_printf(1, "\n");
		++i;
	}
}
