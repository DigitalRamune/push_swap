/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:29:43 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/11 16:44:29 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_swap(t_list **stack_a, int which)
{
	t_list	*second;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return ;
	second = (*stack_a)->next;
	(*stack_a)->next = second->next;
	second->next = (*stack_a);
	*stack_a = second;
	if (which == 1)
		write(1, "sb\n", 3);
	else if (which == 0)
		write(1, "sa\n", 3);
	return ;
}

