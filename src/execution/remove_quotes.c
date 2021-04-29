/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:11:49 by hmzah             #+#    #+#             */
/*   Updated: 2021/04/29 10:14:51 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	handle_quotes(char c, int *balance)
{
	if (c == '\"' && *balance == 0)
		*balance = 2;
	else if (c == '\'' && *balance == 0)
		*balance = 1;
	else if (c == '\"' && *balance == 2)
		*balance = 0;
	else if (c == '\'' && *balance == 1)
		*balance = 0;
}

void	remove_quotes(char **str)
{
	int		i;
	int		len;
	int		b;
	int		j;

	i = 0;
	len = ft_strlen((*str));
	b = 0;
	while (i < len)
	{
		if ((*str)[i] == '\'' || (*str)[i] == '"')
			handle_quotes((*str)[i], &b);
		if (((*str)[i] == '"' && (b == 0 || b == 2))
			|| ((*str)[i] == '\'' && (b == 0 || b == 1)))
		{
			j = i - 1;
			while (++j < len)
				(*str)[j] = (*str)[1 + j];
			len--;
			i--;
		}
		i++;
	}
}
