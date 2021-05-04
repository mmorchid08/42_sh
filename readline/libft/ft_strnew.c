/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:41:05 by mel-idri          #+#    #+#             */
/*   Updated: 2020/07/24 23:04:31 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *ptr;

	if ((ptr = (char*)safe_malloc(size + 1)) == NULL)
		return (NULL);
	ft_bzero(ptr, size + 1);
	return (ptr);
}
