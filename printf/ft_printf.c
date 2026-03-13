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

static int	ft_option(char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(arg, int));
	if (c == 's')
		i += ft_putstr(va_arg(arg, char *));
	if (c == 'p')
		i += ft_printadress(va_arg(arg, void *));
	if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(arg, int));
	if (c == 'u')
		i += ft_putnbrunsigned(va_arg(arg, unsigned int));
	if (c == 'x')
		i += ft_printhexa(va_arg(arg, unsigned int), 1);
	if (c == 'X')
		i += ft_printhexa(va_arg(arg, unsigned int), 2);
	if (c == 'f')
		i += ft_printfloat(va_arg(arg, double));
	if (c == '%')
		return (ft_putchar('%'));
	return (i);
}

int	ft_printf(const char *string, ...)
{
	int	i;
	int	count;

	va_list(arg);
	count = 0;
	i = 0;
	if (!string || write(1, "", 0) == -1)
		return (-1);
	va_start(arg, string);
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			count += ft_option(string[i + 1], arg);
			i++;
		}
		else
			count += write(1, &string[i], 1);
		i++;
	}
	va_end(arg);
	if (count < 0)
		return (-1);
	return (count);
}
