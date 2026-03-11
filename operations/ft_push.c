/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:28:10 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/11 16:46:31 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_push(t_list **stack_a, t_list **stack_b, t_oper **operation, int	which)
{
	t_list	*elem_to_remove;

	if (stack_a && *stack_a)
	{
		elem_to_remove = *stack_a;
		*stack_a = (*stack_a)->next;
		elem_to_remove->next = *stack_b;
		*stack_b = elem_to_remove;
	}
	if (which == 0)
	{
		(*operation)->pa += 1;
		if ((*operation)->print == 0)
			printf("pa\n");
	}
	else
	{
		(*operation)->pb += 1;
		if ((*operation)->print == 0)
			printf("pb\n");
	}
}
