/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:42:15 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/11 16:42:47 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
}

void	ft_lstadd_front_op(t_oper **lst, t_oper *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
}

void	ft_lstadd_front_param(p_list **lst, p_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
}
