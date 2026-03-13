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

void	ft_sort_three(t_list **st_a, t_oper **op)
{
	int		max_pos;

	if (!st_a || !*st_a || !(*st_a)->next)
        return ;
	max_pos = find_index_of_max(st_a);
	if (max_pos == 2)
		ft_reverserotate(st_a, op, 0);
	else if (max_pos == 1)
		ft_rotate(st_a, op, 0);
	if ((*st_a)->data > (*st_a)->next->data)
		ft_swap(st_a, op, 0);
	return ;
}

void	ft_sort_small(t_list **st_a, t_list **st_b, t_oper **op)
{
	int	push_count;

	push_count = 0;
	while (ft_lstsize(*st_a) > 3)
	{
		find_min(st_a, op);
		ft_push(st_a, st_b, op, 1);
		push_count++;
	}
	ft_sort_three(st_a, op);
	while (push_count != 0)
	{
		ft_push(st_b, st_a, op, 0);
		push_count--;
	}
	return ;
}

void	ft_simple_mini(t_list **st_a, t_list **st_b, t_oper **op)
{
	int	size;

	size = ft_lstsize(*st_a);
	if (size == 2)
		ft_swap(st_a, op, 0);
	else if (size == 3)
	{
		ft_sort_three(st_a, op);
	}
	else if (size <= 10)
		ft_sort_small(st_a, st_b, op);
}

void	ft_simple_alg(t_list **stack_a, t_list **stack_b, t_oper **operation)
{
	int		index;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size <= 10)
	{
		ft_simple_mini(stack_a, stack_b, operation);
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
