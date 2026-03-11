/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:53:54 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/11 16:42:14 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	find_min_radix(t_list **stack, int list_size)
{
	t_list	*first_l;
	int		i;
	int		min;

	first_l = *stack;
	i = 0;
	while (first_l->rank != -1)
		first_l = first_l->next;
	min = first_l->data;
	first_l = *stack;
	while (i < list_size)
	{
		if (min > first_l->data && first_l->rank == -1)
			min = first_l->data;
		first_l = first_l->next;
		i++;
	}
	return (min);
}
void	set_base_rank(t_list **stack_a)
{
	t_list	*list;

	list = *stack_a;
	while (list->next)
	{
		list->rank = -1;
		list = list->next;
	}
	list->rank = -1;
}

void	set_min_rank(t_list **stack, int rank, int list_size)
{
	int		min;
	int		i;
	t_list	*first_l;

	first_l = *stack;
	i = 0;
	min = find_min_radix(&first_l, list_size);
	while (i < list_size)
	{
		if (first_l->data == min && first_l->rank == -1)
		{
			first_l->rank = rank;
			break ;
		}
		first_l = first_l->next;
	}
}

void	set_all_rank(t_list **stack)
{
	int		list_size;
	int		rank;
	t_list	*first_l;

	rank = 0;
	list_size = ft_lstsize(*stack);
	// printf("La taille de la liste est : %d\n\n", list_size);
	first_l = *stack;
	while (rank < list_size)
	{
		set_min_rank(&first_l, rank, list_size);
		rank++;
	}
}

int	ft_bits_num(int list_size)
{
	int	i;
	int	size;

	i = 0;
	size = list_size - 1;
	while (size != 0)
	{
		i++;
		size = size >> 1;
	}
	return (i);
}

void	ft_push_back_all(t_list **stack_b, t_list **stack_a, int count, t_oper **operations)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_push(stack_b, stack_a, operations, 1);
		i++;
	}
}

void	ft_radix(t_list **stack_a, t_list **stack_b, t_oper **operation)
{
	int	i;
	int	bits;
	int	size;
	int	maxbits;
	int	push_count;
	int	total_coups;

	i = 0;
	bits = 0;
	push_count = 0;
	total_coups = 0;
	size = ft_lstsize(*stack_a);
	maxbits = ft_bits_num(size - 1);
	while (bits < maxbits)
	{
		while (i < size)
		{
			if ((((*stack_a)->rank >> bits) & 1) == 0)
			{
				ft_push(stack_a, stack_b, operation, 0);
				push_count += 1;
			}
			else
				ft_rotate(stack_a, operation, 0);
			i++;
			total_coups += 1;
		}
		ft_push_back_all(stack_b, stack_a, push_count, operation);
		push_count = 0;
		i = 0;
		bits++;
	}
}
