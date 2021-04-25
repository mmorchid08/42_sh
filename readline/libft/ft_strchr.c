/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:32:04 by mel-idri          #+#    #+#             */
/*   Updated: 2020/03/21 15:31:39 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;
	size_t len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		else
			i++;
	return (NULL);
}
