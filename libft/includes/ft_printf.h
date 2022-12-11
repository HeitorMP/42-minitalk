/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:50:39 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/11/15 13:52:00 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

int			ft_printf(const char *str, ...);
int			ft_get_digits(long long int nb);
int			ft_get_hexlen(unsigned	int num);
int			ft_get_hexlen(unsigned int num);
int			ft_ptr_len(unsigned long long num);
int			call_char(va_list args);
int			call_string(va_list args);
int			call_int(va_list args);
int			call_hex(va_list args, char next);
int			put_pointer(unsigned long long np);
int			call_ptr(va_list args);
int			call_unsigned(va_list args);
void		ft_putunsigned(unsigned int n);
void		put_hex(long int np, char x);
#endif
