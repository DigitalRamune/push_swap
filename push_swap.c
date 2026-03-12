/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:28:05 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/12 11:33:26 by inaciri          ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int		i;
	int		z;
	int		result;
	t_list	*stack_a;
	t_list	*stack_b;
	t_oper	*operations;
	p_list	*param;

	stack_a = NULL;
	stack_b = NULL;
	ft_lstadd_front_op(&operations, ft_lstnew_op(0));
	ft_lstadd_front_param(&param,ft_lstnew_param(0));
	result = ft_check_all(argv, &param);
	z = 1;
	if (result == -1)
	{
		printf("Error");
		return 0;
	}
	else if (result == 1)
		z = 2;
	i = argc;
	if (argc <= 1)
		printf("Error\n");
	while (--i >= z)
		ft_split(argv[i], ' ', &stack_a);
	i = argc - 1;
	if (!stack_a)
	{
		while (i >= z)
		{
			ft_lstadd_front(&stack_a, ft_lstnew(ft_atoi(argv[i])));
			i--;
		}
	}
	printf("STACK A BEFORE: \n\n");
	printlist(stack_a);
	set_alg(&param, &stack_a, &stack_b, &operations);
	printf("STACK A : \n\n");
	printlist(stack_a);
}
