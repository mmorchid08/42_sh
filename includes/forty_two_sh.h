/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forty_two_sh.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:17:07 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/24 16:48:02 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORTY_TWO_SH_H
# define FORTY_TWO_SH_H

# include "../libft/libft.h"
# include "constants.h"
# include "typedefs.h"
# include "../src/errors/errors.h"
# include "../src/parser/parser.h"

void	del_token(void *element);
void	del_redirection(void *element);
void	del_var(void *element);

#endif
