/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:28:10 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/13 17:36:04 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_push(t_list **st_a, t_list **st_b, t_oper **operation, int which)
{
	t_list	*elem_to_remove;

	if (st_a && *st_a)
	{
		elem_to_remove = *st_a;
		*st_a = (*st_a)->next;
		elem_to_remove->next = *st_b;
		*st_b = elem_to_remove;
	}
	if (which == 0)
	{
		(*operation)->pa += 1;
		write(1, "pa\n", 3);
	}
	else if (which == 1)
	{
		(*operation)->pb += 1;
		write(1, "pb\n", 3);
	}
}
