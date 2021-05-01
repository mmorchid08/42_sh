/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:17:20 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/01 14:44:42 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

char	*ft_strnjoin(char **strings, int n)
{
	char		*concat;
	size_t		size;
	int			i;
	int *const	lenghts = (int *)ft_memalloc(sizeof(int) * n);

	size = 0;
	i = -1;
	concat = NULL;
	while (++i < n)
	{
		if (!strings[i])
			break ;
		lenghts[i] = ft_strlen(strings[i]);
		size += lenghts[i];
	}
	if (i == n && assign_p((void **)&concat, ft_strnew(size)))
	{
		i = -1;
		size = 0;
		while (++i < n)
			ft_strcat(concat + assign_ul(&size, size + lenghts[i])
				- lenghts[i], strings[i]);
	}
	free(lenghts);
	return (ter_p(i != n, NULL, concat));
}

int	ft_isinstr(char c, const char *s)
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

char	*ft_skip_unitl_char(const char *str, const char *compare,
																int (*f)(int))
{
	if (!f)
		f = empty;
	while (str && *str && !ft_isinstr(*str, compare) && !f(*str))
		str++;
	return ((char *)str);
}
