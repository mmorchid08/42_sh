/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:55:34 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/28 14:29:26 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum	e_error
{
	EACCES = 1,
	ENOCMD,
	ENOENT,
	ENOTDIR,
	ENAMETOOLONG,
	ENOHOME,
	ENOOLDPWD,
	EISDIR,
	EREDIRECT,
	EAMBREDIRECT,
	ESYNTAX,
	ETOOMANYPIPES,
	EFORK,
	EOPENFILE,
	ENOJOB,
	EUNK
}				t_error;

extern t_error	g_errno;

void			ft_perror(char *prefix, char *suffix, t_bool exit_on_error);
void			ft_strerror(t_error e, char *prefix, char *suffix,
					t_bool exit_on_error);

#endif
