/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeder <ffeder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:22:22 by ffeder            #+#    #+#             */
/*   Updated: 2025/11/25 13:52:59 by ffeder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_option(int fd, char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(fd, va_arg(arg, int));
	if (c == 's')
		i += ft_putstr(fd, va_arg(arg, char *));
	if (c == 'p')
		i += ft_printadress(fd, va_arg(arg, void *));
	if (c == 'd' || c == 'i')
		i += ft_putnbr(fd, va_arg(arg, int));
	if (c == 'u')
		i += ft_putnbrunsigned(fd, va_arg(arg, unsigned int));
	if (c == 'x')
		i += ft_printhexa(fd, va_arg(arg, unsigned int), 1);
	if (c == 'X')
		i += ft_printhexa(fd, va_arg(arg, unsigned int), 2);
	if (c == 'f')
		i += ft_printfloat(fd, va_arg(arg, double));
	if (c == '%')
		return (ft_putchar(fd, '%'));
	return (i);
}

int	ft_printf(int fd, const char *string, ...)
{
	int	i;
	int	count;

	va_list(arg);
	count = 0;
	i = 0;
	if (!string || write(fd, "", 0) == -1)
		return (-1);
	va_start(arg, string);
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			count += ft_option(fd, string[i + 1], arg);
			i++;
		}
		else
			count += write(fd, &string[i], 1);
		i++;
	}
	va_end(arg);
	if (count < 0)
		return (-1);
	return (count);
}
