/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:54:06 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/11 16:45:32 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				minus;

	i = 0;
	minus = 0;
	if (n == 0)
		return (0);
	if (!s1 && !s2)
		return (0);
	if (ft_strlen(s2) != ft_strlen(s1))
		return (1);
	while ((s1[i] || s2[i]) && (i <= n - 1))
	{
		minus = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (minus != 0)
			break ;
		i++;
	}
	return (minus);
}

// int main() {
//     char s1[] = "";
//     char s2[] = "";

//     int result1 = strncmp(s1, s2, 1);
//     int result2 = ft_strncmp(s1, s2, 1);

//     if (result1 != result2) return 1;
//     if (result2 != 0) return 1;

//     return 0;}
