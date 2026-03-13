/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:42:15 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/12 17:05:27 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(int data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

t_oper	*ft_lstnew_op(int data)
{
	t_oper	*elem;

	elem = malloc(sizeof(t_oper));
	if (!elem)
		return (NULL);
	elem->pa = data;
	elem->pb = data;
	elem->sa = data;
	elem->sb = data;
	elem->ss = data;
	elem->ra = data;
	elem->rb = data;
	elem->rr = data;
	elem->rra = data;
	elem->rrb = data;
	elem->rrr = data;
	elem->print = data;
	elem->next = NULL;
	return (elem);
}

p_list	*ft_lstnew_param(int data)
{
	p_list	*elem;

	elem = malloc(sizeof(p_list));
	if (!elem)
		return (NULL);
	elem->adaptiv = data;
	elem->bench = data;
	elem->complex = data;
	elem->medium = data;
	elem->simple = data;
	elem->next = NULL;
	elem->choice = NULL;
	return (elem);
}
