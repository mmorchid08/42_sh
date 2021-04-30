/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:17:20 by hmzah             #+#    #+#             */
/*   Updated: 2021/04/30 13:17:20 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

char	*ft_strnjoin(char **strings, int n)
{
	char	*concat;
	size_t	size;
	int		i;
	int		lenghts[n];

	size = 0;
	i = -1;
	while (++i < n)
	{
		if (!strings[i])
			return (NULL);
		lenghts[i] = ft_strlen(strings[i]);
		size += lenghts[i];
	}
	if ((concat = ft_strnew(size)))
	{
		i = -1;
		size = 0;
		while (++i < n)
		{
			ft_strcat(concat + size, strings[i]);
			size += lenghts[i];
		}
	}
	return (concat);
}

int		ft_isinstr(char c, const char *s)
{
	while (s && *s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

static int	empty(int n)
{
	(void)n;
	return (0);
}

char		*ft_skip_unitl_char(const char *str, const char *compare,
																int (*f)(int))
{
	if (!f)
		f = empty;
	while (str && *str && !ft_isinstr(*str, compare) && !f(*str))
		str++;
	return ((char *)str);
}
