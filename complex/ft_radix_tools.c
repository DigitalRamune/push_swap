/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 13:01:24 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/15 13:01:26 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
	first_l = *stack;
	while (rank < list_size)
	{
		set_min_rank(&first_l, rank, list_size);
		rank++;
	}
}
