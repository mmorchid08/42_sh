/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 04:41:04 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/02 02:34:16 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static long	matched_len(char *str, char *patrn, long val, long (*f)(long, long))
{
	t_list				*ret;
	t_list				*ends;
	t_list				*tmp;
	t_matched_strings	*ptr;

	if (!assign_p(&ret, reg_match(str, patrn)))
		return (0);
	while (ret)
	{
		ptr = (t_matched_strings *)ret->content;
		ends = ((t_matched_strings *)ret->content)->ends;
		while (ends)
		{
			val = f((char *)ends->content - ptr->start, val);
			tmp = ends;
			ends = ends->next;
			free(tmp);
		}
		tmp = ret;
		ret = ret->next;
		free(tmp->content);
		free(tmp);
	}
	return (val);
}

char	*expand_rem_pre(char *var_name, char *expr, long val,
														long (*f)(long, long))
{
	char		*ret;
	char		*tmp;
	long		cut_len;
	t_variables	*var;

	ret = NULL;
	if (!assign_p(&var, get_var(var_name)))
		return (ft_strdup(""));
	if (assign_p(&tmp, expand(ft_strjoin("^", ft_skip_chars(expr, "#", NULL)),
				NULL)))
	{
		cut_len = matched_len(var->value, tmp, val, f);
		free(tmp);
		return (ft_strsub(var->value, cut_len, ft_strlen(var->value)));
	}
	return (ret);
}

char	*expand_rem_suf(char *var_name, char *expr, long val,
														long (*f)(long, long))
{
	char		*ret;
	char		*tmp;
	long		cut_len;
	t_variables	*var;

	ret = NULL;
	if (!assign_p(&var, get_var(var_name)))
		return (ft_strdup(""));
	if (assign_p(&tmp, expand(ft_strjoin(ft_skip_chars(expr, "%", NULL), "$"),
				NULL)))
	{
		cut_len = matched_len(var->value, tmp, val, f);
		free(tmp);
		return (ft_strsub(var->value, 0, ft_strlen(var->value) - cut_len));
	}
	return (ret);
}
