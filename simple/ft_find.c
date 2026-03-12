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
