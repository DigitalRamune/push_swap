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

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
