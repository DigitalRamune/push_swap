/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:28:05 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/13 17:41:58 by inaciri          ###   ########.fr       */
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

int	ft_is_sorted(t_list *st_a)
{
	t_list	*check;
	
	if (!st_a)
		return (1);
	check = st_a;
	while (check->next)
	{
		if (check->data > check->next->data)
			return (0);
		check = check->next;
	}
	return (1);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b, t_oper **op, p_list **param)
{
	if (ft_lstsize(*stack_a) <= 1 || ft_is_sorted(*stack_a))
	{
		ft_lstclear_all(stack_a, stack_b, param, op);
		return ;
	}
	// printf("AVANT set_alg - Stack A:\n");
    // printlist(*stack_a);
	set_alg(param, stack_a, stack_b, op);
	// printf("APRES set_alg - Stack A:\n");
    // printlist(*stack_a);
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
	if (argc < 2)
		return (0);
	ft_init_lists(&operations, &param);
	z = ft_detect(argv[1], &param) + 1;
	if (z == 1)
		param->adaptiv = 1;
	// z = ft_result_after_check(argv, &param);
	// if (z == 0)
	// 	return (ft_lstclear_all(&stack_a, &stack_b, &param, &operations), 0);
	i = argc;
	while (--i >= z)
	{
		if (ft_split(argv[i], ' ', &stack_a) == NULL)
		{
			write(2, "Error\n", 6);
			return (ft_lstclear_all(&stack_a, &stack_b, &param, &operations), 0);
		}
	}
	ft_push_swap(&stack_a, &stack_b, &operations, &param);
}
