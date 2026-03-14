/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:47:46 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/13 13:52:33 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_valid_number(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	nbr = ft_atol(str);
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

int	ft_detect(char *argv, t_para **param)
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

int	ft_check_all(char **argv, t_para **param)
{
	int	i;
	int	z;

	i = 1;
	z = (ft_detect(argv[1], param) == 0);
	if (z)
	{
		if (ft_is_valid_number(argv[1]) == 0)
			return (-1);
		(*param)->adaptiv = 1;
	}
	while (argv[i])
	{
		if (i > 1 && ft_detect(argv[i], param) == 1)
			return (-1);
		if (i > 1 && ft_is_valid_number(argv[i]) == 0)
			return (-1);
		i++;
	}
	return (1 + z);
}

int	ft_result_after_check(char **argv, t_para **param)
{
	int	result;

	result = ft_check_all(argv, param);
	if (result == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (result == 1)
		return (2);
	else
		return (1);
}
