/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:47:46 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/17 14:43:32 by inaciri          ###   ########.fr       */
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

static int	sum(t_para **param)
{
	int	i;

	i = (*param)->simple + (*param)->medium;
	i += (*param)->complex +(*param)->adaptiv;
	return (i);
}

int	ft_detect(int argc, char **argv, t_para **param)
{
	int	i;
	int	alg_nbr;

	i = 0;
	while (++i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (strcmp(argv[i], "--bench") == 0)
			(*param)->bench += 1;
		else if (strcmp(argv[i], "--simple") == 0)
			(*param)->simple = 1;
		else if (strcmp(argv[i], "--medium") == 0)
			(*param)->medium = 1;
		else if (strcmp(argv[i], "--complex") == 0)
			(*param)->complex = 1;
		else if (strcmp(argv[i], "--adaptive") == 0)
			(*param)->adaptiv = 1;
		else
			return (0);
	}
	alg_nbr = sum(param);
	if ((alg_nbr > 1) || (*param)->bench > 1)
		return (0);
	if (alg_nbr == 0)
		(*param)->adaptiv = 2;
	return (i);
}
