/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 13:01:47 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/15 13:01:50 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_check_duplicate(t_list **stack_a, int nb)
{
	t_list	*current;

	if (!stack_a || !*stack_a)
		return (1);
	current = *stack_a;
	while (current)
	{
		if (current->data == nb)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
