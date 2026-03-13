/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilscount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeder <ffeder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:26:54 by ffeder            #+#    #+#             */
/*   Updated: 2025/11/23 15:42:55 by ffeder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_printadress(void *p)
{
	if (!p)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_printhexa((unsigned long long)p, 1) + 2);
}

size_t	ft_hexcount(unsigned long long hex)
{
	int	i;

	i = 1;
	while (hex >= 16)
	{
		hex = hex / 16;
		i++;
	}
	return (i);
}

int	ft_printfloat(double n)
{
	long long	int_p;
	int			len;
	int			prec;
	char		c;

	len = 0;
	prec = 2;
	if (n < 0.0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	n += 0.005;
	int_p = (long long)n;
	len += ft_putnbr(int_p);
	len += write(1, ".", 1);
	n -= (double)int_p;
	while (prec-- > 0)
	{
		n *= 10.0;
		c = (int)n + '0';
		len += write(1, &c, 1);
		n -= (int)n;
	}
	return (len);
}
