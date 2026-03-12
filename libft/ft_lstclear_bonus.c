/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:24:58 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/12 16:21:19 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (lst != NULL)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
		free(*lst);
		*lst = NULL;
	}
	return ;
}

void	ft_lstclear_op(t_oper **lst)
{
	t_oper	*temp;

	if (lst != NULL)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
		free(*lst);
		*lst = NULL;
	}
	return ;
}

void	ft_lstclear_param(p_list **lst)
{
	p_list	*temp;

	if (lst != NULL)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
		free(*lst);
		*lst = NULL;
	}
	return ;
}
