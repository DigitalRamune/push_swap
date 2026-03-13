/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeder <ffeder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:29:54 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/12 15:20:10 by ffeder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_reverserotate(t_list **stack_a, t_oper **operation, int which)
{
	t_list	*last_one;
	t_list	*new_last;

	if (stack_a && *stack_a && (*stack_a)->next != NULL)
	{
		new_last = *stack_a;
		while (new_last->next->next != NULL)
			new_last = new_last->next;
		last_one = new_last->next;
		new_last->next = NULL;
		last_one->next = *stack_a;
		*stack_a = last_one;
	}
	if (which == 0)
	{
		(*operation)->rra += 1;
		if ((*operation)->print == 0)
			printf("rra\n");
	}
	else if (which == 1)
	{
		(*operation)->rrb += 1;
		if ((*operation)->print == 0)
			printf("rrb\n");
	}
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, t_oper **operation)
{
	ft_reverserotate(stack_a, operation, 3);
	ft_reverserotate(stack_b, operation, 3);
	if ((*operation)->print == 0)
		printf("rrr\n");
}

void	ft_rotate(t_list **stack_a, t_oper **operation, int which)
{
	t_list	*first_node;
	t_list	*last_node;

	if (stack_a && *stack_a && (*stack_a)->next != NULL)
	{
		first_node = *stack_a;
		*stack_a = first_node->next;
		last_node = *stack_a;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = first_node;
		first_node->next = NULL;
	}
	if (which == 0)
	{
		(*operation)->ra += 1;
		if ((*operation)->print == 0)
			printf("ra\n");
	}
	else if (which == 1)
	{
		(*operation)->rb += 1;
		if ((*operation)->print == 0)
			printf("rb\n");
	}
}

void	ft_rr(t_list **stack_a, t_list **stack_b, t_oper **operation)
{
	ft_rotate(stack_a, operation, 3);
	ft_rotate(stack_b, operation, 3);
	if ((*operation)->print == 0)
		printf("rr\n");
}
