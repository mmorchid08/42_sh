/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluation_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 02:53:57 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/02 00:27:26 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

long long	do_op(long long *op1, int oparator, long op2, int ret)
{
	if (oparator == 13)
		*op1 *= op2;
	else if (oparator == 12 && (assign_i(&ret, ((op2 == 0) * 2)) || 1))
		ter_i(ret, 0, (*op1 /= op2));
	else if (oparator == 11 && (assign_i(&ret, ((op2 == 0) * 2)) || 1))
		ter_i(ret, 0, (*op1 %= op2));
	else if (oparator == 10)
		*op1 += op2;
	else if (oparator == 9)
		*op1 -= op2;
	else if (oparator == 8)
		*op1 = *op1 <= op2;
	else if (oparator == 7)
		*op1 = *op1 >= op2;
	else if (oparator == 6)
		*op1 = *op1 < op2;
	else if (oparator == 5)
		*op1 = *op1 > op2;
	else if (oparator == 4)
		*op1 = *op1 == op2;
	else if (oparator == 3)
		*op1 = *op1 != op2;
	return (ret);
}

int	do_logical_op(t_list **token, long long *result, int operator)
{
	int	bracket;

	bracket = 1;
	*result = !!*result;
	if ((operator == 1 && !*result) || (operator == 2 && *result))
	{
		if (eval_expr(token, result))
			return (1);
		*result = !!*result;
		return (0);
	}
	while (*token && bracket)
	{
		if (ft_strequ((*token)->content, ")"))
		{
			bracket--;
			if (bracket == 0)
				break ;
		}
		else if (ft_strequ((*token)->content, "("))
			bracket++;
		*token = (*token)->next;
	}
	return (0);
}

int	get_precedence(int operator)
{
	if (ft_between(operator, 11, 13))
		return (5);
	if (ft_between(operator, 9, 10))
		return (4);
	if (ft_between(operator, 5, 8))
		return (3);
	if (ft_between(operator, 3, 4))
		return (2);
	if (ft_between(operator, 1, 2))
		return (1);
	return (0);
}

int	operator_have_precedence(t_list **token, int operator1)
{
	int		operator2;
	t_list	*tmp;
	int		bracket;

	bracket = 0;
	tmp = ter_p(*token, (*token)->next, NULL);
	if (*token && ft_strequ((*token)->content, "("))
		bracket = 1;
	while (tmp && bracket)
	{
		if (ft_strequ(tmp->content, "("))
			bracket++;
		else if (ft_strequ(tmp->content, ")"))
			bracket--;
		tmp = tmp->next;
	}
	if (tmp && !convert_operator(&tmp, &operator2, 0))
		return (get_precedence(operator1) >= get_precedence(operator2));
	return (1);
}

void	ar_edit_var(char *key, long long val, int prefix)
{
	char	*tmp;

	if (prefix)
	{
		if (!assign_p(&tmp, ft_itoa(val)))
			return ;
		edit_add_var(key, tmp, 0, 1);
		free(tmp);
	}
}
