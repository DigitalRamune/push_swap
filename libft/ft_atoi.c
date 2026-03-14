/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:36:51 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/11 16:42:38 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"

int	ft_atoi(const char *str)
{
	char	*tempstr;
	int		neg;
	int		i;
	int		res;

	res = 0;
	tempstr = (char *)str;
	i = 0;
	neg = 1;
	while ((tempstr[i] >= 8 && tempstr[i] <= 13) || tempstr[i] == 32)
		i++;
	if (tempstr[i] == '-' || tempstr[i] == '+')
	{
		if (tempstr[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (tempstr[i] >= '0' && tempstr[i] <= '9')
	{
		res = res * 10 + (tempstr[i] - '0');
		i++;
	}
	return (res * neg);
}

long	ft_atol(const char *str)
{
	char	*tempstr;
	int		neg;
	long	i;
	long	res;

	res = 0;
	tempstr = (char *)str;
	i = 0;
	neg = 1;
	while ((tempstr[i] >= 8 && tempstr[i] <= 13) || tempstr[i] == 32)
		i++;
	if (tempstr[i] == '-' || tempstr[i] == '+')
	{
		if (tempstr[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (tempstr[i] >= '0' && tempstr[i] <= '9')
	{
		res = res * 10 + (tempstr[i] - '0');
		i++;
	}
	return (res * neg);
}

// int main()
// {
// 	char x = '\f';
// 	char *str = " \\t\\v\\n\\r\\f123";
// 	printf("La valeur retournee par atoi est : %d\n", atoi(str));
// 	printf("La valeur retournee par atoi est : %d\n", ft_atoi(str));
// }