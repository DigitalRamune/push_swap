/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:10:21 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/13 14:02:48 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_bucket_no(int data, int size, int max)
{
	float	normalize;
	float	bucket_no;
	int		bucket;

	if (!max)
		max = 1;
	normalize = ((float)(data) / (float)(max));
	bucket_no = (size * normalize);
	bucket = (int)bucket_no / 10;
	return (bucket);
}

void	order_b(t_list **stack_a, t_list **stack_b, t_oper **operations, int opt)
{
	int		size;
	int		temp;
	t_list	*current;

	current = *stack_b;
	size = ft_lstsize(*stack_b);
	(void)stack_a;
	if (opt == 1 && size)
	{
		temp = current->data;
		while (current != NULL)
		{
			temp = current->data;
			if (temp > current->data)
				ft_rotate(stack_b, operations, 1);
			temp = current->data;
			current = current->next;
		}
	}
}

void	order_alg(int temp_min_data, int index, t_list **stack_a, t_list **stack_b, t_oper **operation)
{
	t_list	*current;

	current = *stack_a;
	while (current->data != temp_min_data)
	{
		index++;
		current = current->next;
	}
	place_min_at_top(stack_a, index, operation);
	ft_push(stack_a, stack_b, operation, 1);
	order_b(stack_a, stack_b, operation, 1);
}

void	top_nb_min_in_score(t_list **stack_a, t_list **stack_b, int max_score, t_oper **operation)
{
	t_list	*current;
	int		index_score;
	int		temp_min_data;
	int		index;
	int		size;

	size = ft_lstsize(*stack_a);
	index_score = 0;
	index = 0;
	current = *stack_a;
	while (index_score <= max_score)
	{
		if (!ft_lstsize(*stack_a))
			return ;
		current = *stack_a;
		index = 0;
		if (find_score(stack_a, index_score, size, &temp_min_data))
			order_alg(temp_min_data, index, stack_a, stack_b, operation);
		else
			index_score += 1;
	}
	return ;
}

void	ft_medium_alg(t_list **stack_a, t_list **stack_b, t_oper **operation)
{
	t_list	*current;
	int		max_score;
	int		size;
	int		maxdata;
	int		bucket;

	current = *stack_a;
	size = ft_lstsize(*stack_a);
	maxdata = find_max(stack_a);
	max_score = 0;
	while (current != NULL)
	{
		bucket = ft_bucket_no(current->data, size, maxdata);
		if (max_score < bucket)
			max_score = bucket;
		current = current->next;
	}
	top_nb_min_in_score(stack_a, stack_b, max_score, operation);
	// while (size != 0)
	// {
	// 	find_max2(stack_b, operation);
	// 	ft_push(stack_b, stack_a, operation, 0);
	// 	size--;
	// }
	while (ft_lstsize(*stack_a) > 0)
		ft_push(stack_a, stack_b, operation, 1);
	while (ft_lstsize(*stack_b) > 0)
	{
		find_max2(stack_b, operation);
		ft_push(stack_b, stack_a, operation, 0);
	}
}
