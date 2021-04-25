/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 06:50:05 by mel-idri          #+#    #+#             */
/*   Updated: 2020/05/10 15:48:24 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*skip_chars(char *str, char *skipped_chars)
{
	int i;

	if (!str || !skipped_chars)
		return (NULL);
	while (*str)
	{
		i = 0;
		while (skipped_chars[i] && *str != skipped_chars[i])
			i++;
		if (*str == skipped_chars[i])
			str++;
		else
			break ;
	}
	return (str);
}
