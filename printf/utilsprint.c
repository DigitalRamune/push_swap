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

size_t	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

size_t	ft_putnbr(int fd, int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		return (write(fd, "-2147483648", 11));
	}
	else if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
		i++;
	}
	if (n > 9)
		i = i + ft_putnbr(fd, (n / 10));
	i = i + ft_putchar(fd, ((n % 10) + '0'));
	return (i);
}

size_t	ft_putnbrunsigned(int fd, unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i = i + ft_putnbr(fd, (n / 10));
	i = i + ft_putchar(fd, ((n % 10) + '0'));
	return (i);
}

size_t	ft_putstr(int fd, char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_putstr(fd, "(null)"));
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_printhexa(int fd, unsigned long long p, int secure)
{
	int	resultat;

	resultat = ft_hexcount(p);
	if (!secure)
		return (0);
	if (secure == 1)
	{
		if (p <= 15)
			return (ft_putchar(fd, "0123456789abcdef"[p]));
		ft_printhexa(fd, p / 16, 1);
		ft_printhexa(fd, p % 16, 1);
		return (resultat);
	}
	if (secure == 2)
	{
		if (p <= 15)
			return (ft_putchar(fd, "0123456789ABCDEF"[p]));
		ft_printhexa(fd, p / 16, 2);
		ft_printhexa(fd, p % 16, 2);
		return (resultat);
	}
	return (0);
}
