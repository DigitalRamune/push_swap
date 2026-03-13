/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:41:26 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/12 13:19:32 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	compute_disorder(t_list **stack_a)
{
	int		mistakes;
	int		total_pairs;
	int		i;
	int		size;
	int		j;
	t_list	*list_i;
	t_list	*list_j;

	list_i = *stack_a;
	list_j = list_i->next;
	size = ft_lstsize(*stack_a);
	i = 0;
	j = 1;
	mistakes = 0;
	total_pairs = 0;
	while (i < size)
	{
		list_j = list_i->next;
        j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if (list_i->data > list_j->data)
				mistakes += 1;
			if (list_j->next)
				list_j = list_j->next;
			j++;
		}
		if (list_i->next)
			list_i = list_i->next;
		i++;
	}
	return (((float)mistakes / (float)total_pairs) * 100);
}

int	ft_adaptive(p_list **param, t_list **stack_a)
{
	float	disorder;
	int		size;

	(void)param;
	size = ft_lstsize(*stack_a);
	disorder = compute_disorder(stack_a);
	(*param)->adaptiv = 0;
	if ((disorder < 20 && size <= 50) || (size <= 10))
	{
		(*param)->choice = ft_strdup("Simple / O(n^2)");
		(*param)->simple = 1;
	}
	else if (disorder <= 50 && size <= 200)
	{
		(*param)->choice = ft_strdup("Medium / O(n√n)");
		(*param)->medium = 1;
	}
	else
	{
		(*param)->choice = ft_strdup("Complex / O(n log n)");
		(*param)->complex = 1;
	}
	return (0);
}
