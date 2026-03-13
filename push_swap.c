/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:28:05 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/12 17:21:04 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printlist(t_list *next_p)
{
	t_list	*current_p;

	current_p = next_p;
	while (current_p != NULL)
	{
		printf("%d\n", current_p->data);
		current_p = current_p->next;
	}
	return ;
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b, t_oper **op, p_list **param)
{
	if (ft_lstsize(*stack_a) <= 1 || compute_disorder(stack_a) < 0.01)
	{
		ft_lstclear_all(stack_a, stack_b, param, op);
		write(2, "Error\n", 6);
		return ;
	}
	set_alg(param, stack_a, stack_b, op);
	ft_lstclear_all(stack_a, stack_b, param, op);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		z;
	t_list	*stack_a;
	t_list	*stack_b;
	t_oper	*operations;
	p_list	*param;

	stack_a = NULL;
	stack_b = NULL;
	operations = NULL;
	param = NULL;
	ft_init_lists(&operations, &param);
	z = ft_result_after_check(argv, &param);
	if (z == 0)
		return (ft_lstclear_all(&stack_a, &stack_b, &param, &operations), 0);
	i = argc;
	while (--i >= z)
	{
		if (ft_split(argv[i], ' ', &stack_a) == NULL)
			return (ft_lstclear_all(&stack_a, &stack_b, &param, &operations), 0);
	}
	ft_push_swap(&stack_a, &stack_b, &operations, &param);
}
