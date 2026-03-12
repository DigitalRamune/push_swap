/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:28:05 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/12 16:29:24 by inaciri          ###   ########.fr       */
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
	t_list	*stack_a;
	t_list	*stack_b;
	t_oper	*operations;
	p_list	*param;

	stack_a = NULL;
	stack_b = NULL;
	ft_init_lists(&operations, &param);
	z = ft_result_after_check(argv, &param);
	if (z == 0)
		return (0);
	i = argc;
	if (argc <= 1)
		printf("Error\n");
	while (--i >= z)
		ft_split(argv[i], ' ', &stack_a);
	i = argc - 1;
	ft_create_stack(&stack_a, argv, i, z);
	if (compute_disorder(&stack_a) == 0)
	{
		printf("La liste est dans l'ordre.\n");
		return 0;
	}
	printf("STACK A BEFORE: \n\n");
	printlist(stack_a);
	set_alg(&param, &stack_a, &stack_b, &operations);
	printf("STACK A : \n\n");
	printlist(stack_a);
	free(param->choice);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	ft_lstclear_op(&operations);
	ft_lstclear_param(&param);
}
