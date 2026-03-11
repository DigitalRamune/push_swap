/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:54:41 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/11 16:45:40 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <bsd/bsd.h>
#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	ptr = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	char	*str = "Hello tout le monde";

// 	printf(" Ma premiere phrase = %s\n", str);
// 	printf(" la copie de ma phrase = %s", ft_strdup(str));
// }