/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:18:21 by jislim            #+#    #+#             */
/*   Updated: 2022/04/05 14:07:19 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "limits.h"
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		print_usnbr(unsigned int us_nbr);
int		print_str(char *str);
int		print_hexa(unsigned int hexa, char conv);
int		print_nbr(int nbr);
int		print_char(int ch);
int		print_hexa_ptr(unsigned long hexa);
char	*printf_hexa(void *v_ptr);

#endif
