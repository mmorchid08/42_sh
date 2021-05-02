/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 04:40:19 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/02 02:40:01 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*expand_defaul_val(char *var_name, char *expression)
{
	t_variables	*var;

	if (assign_p(&var, get_var(var_name)) && !ft_strequ(var->value, ""))
		return (ft_strdup(var->value));
	return (expand(ft_strdup(expression + 2), NULL));
}

char	*expand_alternative_val(char *var_name, char *expression)
{
	t_variables	*var;

	if (assign_p(&var, get_var(var_name)) && !ft_strequ(var->value, ""))
		return (expand(ft_strdup(expression + 2), NULL));
	return (ft_strdup(""));
}

char	*assign_default_val(char *var_name, char *expression)
{
	char		*val;
	t_variables	*var;

	if (!assign_p(&var, get_var(var_name)) || ft_strequ(var->value, ""))
	{
		if (!assign_p(&val, expand(ft_strdup(expression + 2), NULL)))
			return (NULL);
		edit_add_var(var_name, val, 0, 0);
		free(val);
	}
	if (assign_p(&var, get_var(var_name)))
		return (ft_strdup(var->value));
	return (NULL);
}

char	*indicate_error(char *var_name, char *expression)
{
	char		*val;
	t_variables	*var;

	if (assign_p(&var, get_var(var_name)) && !ft_strequ(var->value, ""))
		return (ft_strdup(var->value));
	else
		val = expand(ft_strdup(expression + 2), NULL);
	ft_printf_fd(2, "42sh: %s: %s\n", var_name, ter_p(val != NULL, val, ""));
	free(val);
	return (NULL);
}
