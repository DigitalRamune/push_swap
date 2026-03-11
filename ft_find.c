/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:23:14 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/06 13:59:26 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	find_min(t_list **next_p, int which, t_oper **operation)
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
	place_min_at_top(next_p, index, which, operation);
}

int	find_score(t_list **stack_a, int index_score, int size)
{
	t_list	*current;
	// int		temp_min_data;
	// int		sec;
	int		max_data;

	max_data = find_max(stack_a);
	current = *stack_a;
	// sec = 0;
	// temp_min_data = current->data;
	if (!ft_lstsize(*stack_a))
		return (-1);
	while (current != NULL)
	{
		// temp_min_data = current->data;
		if 			(ft_bucket_no(current->data, size, max_data) == index_score)
		{
			return (current->data);
		}
		current = current->next;
	}
	return (-1);
}

int	find_min_score(t_list **stack_a, int index_score, int max_data, int size)
{
	t_list	*current;
	int		temp_min_data;
	int		sec;

	current = *stack_a;
	sec = 0;
	temp_min_data = max_data;
	if (!ft_lstsize(*stack_a))
		return (-1);
	while (current != NULL)
	{
		if (ft_bucket_no(current->data, size, max_data) == index_score)
		{
			if (temp_min_data >= current->data)
			{
				temp_min_data = current->data;
				sec = 1;
			}
		}
		current = current->next;
	}
	if (sec == 1)
		return (temp_min_data);
	else
		return (-1);
}

int	find_max(t_list **stack_a)
{
	int		max;
	t_list	*current;

	current = *stack_a;
	max = current->data;
	while (current->next != NULL)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	if (current->data > max)
		max = current->data;
	return (max);
}

void	find_max2(t_list **next_p, int which, t_oper **operation)
{
	int		max;
	int		index;
	t_list	*stack;

	index = 0;
	stack = *next_p;
	max = stack->data;
	while (stack->next != NULL)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	if (stack->data > max)
		max = stack->data;
	stack = *next_p;
	while (stack->data != max)
	{
		index++;
		stack = stack->next;
	}
	place_max_at_top(next_p, index, which, operation);
	
}
