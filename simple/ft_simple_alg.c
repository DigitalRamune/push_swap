/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:15:11 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/11 16:46:39 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_simple_alg(t_list **stack_a, t_list **stack_b, t_oper **operation)
{
	int	index;
	int	size;

	size = ft_lstsize(*stack_a);
	index = 0;
	while (index < size - 1)
	{
		find_min(stack_a, 0, operation);
		ft_push(stack_a, stack_b, operation, 0);
		index++;
	}
	index = 0;
	while (index < size - 1)
	{
		ft_push(stack_b, stack_a, operation, 1);
		index++;
	}
}
