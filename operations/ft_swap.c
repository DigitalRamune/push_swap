/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:29:43 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/11 16:44:29 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_swap(t_list *stack_a, int which)
{
	int	top;
	int	bottom;

	top = stack_a->data;
	bottom = stack_a->next->data;
	stack_a->next->data = top;
	stack_a->data = bottom;
	if (which == 1)
		write(1, "sb\n", 3);
	else if (which == 0)
		write(1, "sa\n", 3);
	return ;
}

