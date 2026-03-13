/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:25:48 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/12 12:57:19 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_create_stack(t_list **stack_a, char **argv, int i, int z)
{
	int		f;
	t_list	*check;

	check = *stack_a;
	f = 0;
	if (!stack_a || stack_a == NULL)
	{
		printf("Je rentre dans la boucle 0\n");
		while (i >= z)
		{
			f = ft_atoi(argv[i]);
			printf("je rentre dans la boucle 1\n");
			while (check)
			{
				printf("je rentre dans la boucle 2\n");
				if (check->data == f)
					write(2, "Error\n", 6);
				check = check->next;
			}
			check = *stack_a;
			ft_lstadd_front(stack_a, ft_lstnew(ft_atoi(argv[i])));
			i--;
		}
	}
}

void	ft_init_lists(t_oper **operations, p_list **param)
{
	ft_lstadd_front_op(operations, ft_lstnew_op(0));
	ft_lstadd_front_param(param, ft_lstnew_param(0));
}

void	ft_init(t_list **st_a, t_list **st_b, t_oper **op, p_list **param)
{
	*st_a = NULL;
	*st_b = NULL;
	*op = NULL;
	*param = NULL;
	ft_init_lists(op, param);
}
