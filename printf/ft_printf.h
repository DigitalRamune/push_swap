/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeder <ffeder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:23:43 by ffeder            #+#    #+#             */
/*   Updated: 2025/11/23 16:16:45 by ffeder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stddef.h>
# include <bsd/string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_printhexa(unsigned long long p, int secure);
size_t	ft_putstr(char *s);
size_t	ft_putnbrunsigned(unsigned int n);
size_t	ft_putnbr(int n);
size_t	ft_putchar(char c);
size_t	ft_strlen(char *str);
size_t	ft_printadress(void *p);
size_t	ft_hexcount(unsigned long long hex);
int     ft_print_float(double n);
int		ft_printf(const char *string, ...);

#endif