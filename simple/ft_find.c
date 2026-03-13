/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeder <ffeder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:23:14 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/12 15:28:51 by ffeder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	find_min(t_list **next_p, t_oper **operation)
{
	int		min;
	int		index;
	t_list	*stack;

	index = 0;
	stack = *next_p;
	min = stack->data;
	while (stack->next != NULL)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	if (stack->data < min)
		min = stack->data;
	stack = *next_p;
	while (stack->data != min)
	{
		index++;
		stack = stack->next;
	}
	place_min_at_top(next_p, index, operation);
}

int	find_index_of_max(t_list **stack_a)
{
	int		max;
	int		index;
	t_list	*current;

	current = *stack_a;
	max = current->data;
	index = 1;
	while (current->next != NULL)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	if (current->data > max)
		max = current->data;
	current = *stack_a;
	while (current->data != max)
	{
		index++;
		current = current->next;
	}
	return (index);
}
