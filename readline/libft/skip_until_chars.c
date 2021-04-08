/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_until_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 06:36:02 by mel-idri          #+#    #+#             */
/*   Updated: 2020/05/09 22:54:43 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*skip_until_chars(char *str, char *stop_chars)
{
	int i;

	if (!str || !stop_chars)
		return (NULL);
	while (*str)
	{
		i = 0;
		while (stop_chars[i] && *str != stop_chars[i])
			i++;
		if (*str == stop_chars[i])
			break ;
		str++;
	}
	return (str);
}
