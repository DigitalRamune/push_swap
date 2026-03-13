/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeder <ffeder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:15:11 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/12 15:29:32 by ffeder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_simple_alg(t_list **stack_a, t_list **stack_b, t_oper **operation)
{
	int		index;
	int		size;
	float	disorder;

	size = ft_lstsize(*stack_a);
	disorder = compute_disorder(stack_a);
	if (disorder == 100.00 && size == 2)
	{
		ft_swap(stack_a, operation, 0);
		return;
	}
	index = 0;
	while (index < size - 1)
	{
		find_min(stack_a, operation);
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
