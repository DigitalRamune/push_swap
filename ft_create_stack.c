/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:25:48 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/12 12:35:20 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_create_stack(t_list **stack_a, char **argv, int i, int z)
{
	if (!stack_a)
	{
		while (i >= z)
		{
			ft_lstadd_front(stack_a, ft_lstnew(ft_atoi(argv[i])));
			i--;
		}
	}
}
