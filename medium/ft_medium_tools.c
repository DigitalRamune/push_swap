/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:16:55 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/13 16:58:58 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	find_score(t_list **stack_a, int index_score, int size, int *temp_min_data)
{
	t_list	*current;
	int		max_data;

	max_data = find_max(stack_a);
	current = *stack_a;
	if (!ft_lstsize(*stack_a))
		return (0);
	while (current != NULL)
	{
		if (ft_bucket_no(current->data, size, max_data) == index_score)
		{
			*temp_min_data = current->data;
			return (1);
		}
		current = current->next;
	}
	return (0);
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

void	find_max2(t_list **st, t_oper **op, t_para **param)
{
	int		max;
	int		index;
	t_list	*stack;

	index = 0;
	stack = *st;
	max = stack->data;
	while (stack->next != NULL)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	if (stack->data > max)
		max = stack->data;
	stack = *st;
	while (stack->data != max)
	{
		index++;
		stack = stack->next;
	}
	if ((*op)->print == -1)
		ft_print_choice(2, param);
	place_max_at_top(st, index, op);
}

void	place_max_at_top(t_list **next_p, int index, t_oper **operation)
{
	int	i;

	i = 0;
	if (index <= ft_lstsize(*next_p) / 2)
	{
		while (i < index)
		{
			ft_rotate(next_p, operation, 1);
			i++;
		}
	}
	else
	{
		while (i < (ft_lstsize(*next_p) - index))
		{
			ft_reverserotate(next_p, operation, 1);
			i++;
		}
	}
}

void	place_min_at_top(t_list **next_p, int index, t_oper **operation)
{
	int	i;

	i = 0;
	if (index <= ft_lstsize(*next_p) / 2)
	{
		while (i < index)
		{
			ft_rotate(next_p, operation, 0);
			i++;
		}
	}
	else
	{
		while (i < (ft_lstsize(*next_p) - index))
		{
			ft_reverserotate(next_p, operation, 0);
			i++;
		}
	}
}
