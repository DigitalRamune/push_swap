/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:47:46 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/11 17:27:26 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_detect(char *argv, p_list **param)
{
	if (ft_strncmp(argv, "--simple", ft_strlen(argv)) == 0)
	{
		(*param)->simple += 1;
	}
	else if (ft_strncmp(argv, "--medium", ft_strlen(argv)) == 0)
	{
		(*param)->medium += 1;
	}
	else if (ft_strncmp(argv, "--complex", ft_strlen(argv)) == 0)
	{
		(*param)->complex += 1;
	}
	else if (ft_strncmp(argv, "--adaptiv", ft_strlen(argv)) == 0)
	{
		(*param)->adaptiv += 1;
	}
	else if (ft_strncmp(argv, "--bench", ft_strlen(argv)) == 0)
	{
		(*param)->bench += 1;
	}
	else
		return (0);
	return (1);
}

int	ft_check_all(char **argv, p_list **param)
{
	int	i;
	int	z;
	
	i = 1;
	z = 0;
	if (ft_detect(argv[i], param) == 0)
	{
		// if (argv[1][0] == '-' && (ft_atoi(argv[1]) == 0))
		// 	return (-1);
		if (argv[1][0] != '0' && (ft_atoi(argv[1]) == 0))
			return (-1);
		z = 1;
		(*param)->adaptiv = 1;
	}
	i++;
	while (argv[i])
	{
		if (ft_detect(argv[i], param) == 1 || (argv[i][0] == '-' && (ft_atoi(argv[i]) == 0)))
			return -1;
		i++;
	}
	return (1 + z);
}
