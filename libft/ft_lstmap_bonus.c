/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:54:54 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/11 16:45:55 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*elem1;

	if (!lst || !f || !del)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		elem1 = ft_lstnew(f(lst->data));
		if (elem1 == NULL)
		{
			del(elem1);
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&ptr, elem1);
	}
	return (ptr);
}
