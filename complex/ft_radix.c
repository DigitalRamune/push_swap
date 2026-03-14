/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:53:54 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/13 15:56:05 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	find_min_radix(t_list **stack, int list_size)
{
	t_list	*first_l;
	int		i;
	int		min;

	first_l = *stack;
	i = 0;
	while (first_l->rank != -1)
		first_l = first_l->next;
	min = first_l->data;
	first_l = *stack;
	while (i < list_size)
	{
		if (min > first_l->data && first_l->rank == -1)
			min = first_l->data;
		first_l = first_l->next;
		i++;
	}
	return (min);
}

int	ft_bits_num(int list_size)
{
	int	i;
	int	size;

	i = 0;
	size = list_size - 1;
	while (size != 0)
	{
		i++;
		size = size >> 1;
	}
	return (i);
}

void	ft_push_back_all(t_list **st_b, t_list **st_a, int count, t_oper **op)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_push(st_b, st_a, op, 0);
		i++;
	}
}

void	ft_radix_loop(t_list **st_a, t_list **st_b, t_oper **op, int maxbits)
{
	int	i;
	int	size;
	int	bits;

	bits = 0;
	size = ft_lstsize(*st_a);
	while (bits < maxbits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*st_a)->rank >> bits) & 1) == 0)
			{
				ft_push(st_a, st_b, op, 1);
			}
			else
				ft_rotate(st_a, op, 0);
			i++;
		}
		ft_push_back_all(st_b, st_a, ft_lstsize(*st_b), op);
		bits++;
	}
}

void	ft_radix(t_list **st_a, t_list **st_b, t_oper **op, t_para **param)
{
	int	size;
	int	maxbits;

	size = ft_lstsize(*st_a);
	maxbits = ft_bits_num(size);
	ft_radix_loop(st_a, st_b, op, maxbits);
	if ((*op)->print == -1)
		ft_print_choice(3, param);
}
