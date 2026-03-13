/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeder <ffeder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:20:05 by ffeder            #+#    #+#             */
/*   Updated: 2025/11/25 12:57:48 by ffeder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	else if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
		i++;
	}
	if (n > 9)
		i = i + ft_putnbr((n / 10));
	i = i + ft_putchar(((n % 10) + '0'));
	return (i);
}

size_t	ft_putnbrunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i = i + ft_putnbr((n / 10));
	i = i + ft_putchar(((n % 10) + '0'));
	return (i);
}

size_t	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_printhexa(unsigned long long p, int secure)
{
	int	resultat;

	resultat = ft_hexcount(p);
	if (!secure)
		return (0);
	if (secure == 1)
	{
		if (p <= 15)
			return (ft_putchar("0123456789abcdef"[p]));
		ft_printhexa(p / 16, 1);
		ft_printhexa(p % 16, 1);
		return (resultat);
	}
	if (secure == 2)
	{
		if (p <= 15)
			return (ft_putchar("0123456789ABCDEF"[p]));
		ft_printhexa(p / 16, 2);
		ft_printhexa(p % 16, 2);
		return (resultat);
	}
	return (0);
}
