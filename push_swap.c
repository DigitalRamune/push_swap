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
		ft_printf(1, "%d\n", current_p->data);
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

void	ft_push_swap(t_list **st_a, t_list **st_b, t_oper **op, t_para **param)
{
	if (ft_lstsize(*st_a) <= 1 || ft_is_sorted(*st_a))
	{
		lstclear_all(st_a, st_b, param, op);
		return ;
	}
	set_alg(param, st_a, st_b, op);
	lstclear_all(st_a, st_b, param, op);
}

int	main(int argc, char *argv[])
{
	int		z;
	t_list	*st_a;
	t_list	*st_b;
	t_oper	*op;
	t_para	*param;

	st_a = NULL;
	st_b = NULL;
	op = NULL;
	param = NULL;
	if (argc < 2)
		return (0);
	ft_init(&st_a, &st_b, &op, &param);
	z = ft_detect(argc, argv, &param);
	while (--argc >= z)
	{
		if (ft_split(argv[argc], ' ', &st_a) == NULL)
		{
			write(2, "Error\n", 6);
			return (lstclear_all(&st_a, &st_b, &param, &op), 0);
		}
	}
	ft_push_swap(&st_a, &st_b, &op, &param);
}
