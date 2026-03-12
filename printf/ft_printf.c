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

#include "ft_printf.h"

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
	if (c == '%')
		return (ft_putchar('%'));
	return (i);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		count;

	va_list (arg);
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

// int	main(void)
// {
// 	// // TEST %U %D %I / NUMBER
// 	// int	x;
// 	// int	y;

// 	// x = printf("hello %d %i %u\n", 200, 600, 700);
// 	// y = ft_printf("hello %d %i %u\n", 200, 600, 700);
// 	// printf("\n%d\n", x);
// 	// printf("%d\n", y);

// 	// // TEST %C %S %% / STRING AND CHAR
// 	// int	x;
// 	// int	y;
// 	// char *str = NULL;

// 	// x = printf("hello %% %c %s\n", 'c', str);
// 	// y = ft_printf("hello %% %c %s\n", 'c', str);
// 	// printf("\n printfcount %d\n", x);
// 	// printf("ft_printfcount %d\n", y);

// 	// TEST %x %X %p / HEXADECIMAL
// 	int		x;
// 	int		y;
// 	void	*ptr;
// 	int		j;

// 	ptr = &j;
// 	x = printf("hello %p %x %X\n", ptr, 100, 200);
// 	y = ft_printf("hello %p %x %X\n", ptr, 100, 200);
// 	printf("\n printfcount %d\n", x);
// 	printf("ft_printfcount %d\n", y);
// }
