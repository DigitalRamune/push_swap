/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:10:21 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/16 14:15:44 by inaciri          ###   ########.fr       */
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

void	order_alg(int temp_min_data, t_list **st_a, t_list **st_b, t_oper **op)
{
	t_list	*current;
	int		index;

	index = 0;
	current = *st_a;
	while (current != NULL && current->data != temp_min_data)
	{
		index++;
		current = current->next;
	}
	place_min_at_top(st_a, index, op);
	ft_push(st_a, st_b, op, 1);
}

void	sort_to_b(t_list **st_a, t_list **st_b, int max_score, t_oper **op)
{
	int		index_score;
	int		temp_min_data;
	int		size;

	size = ft_lstsize(*st_a);
	index_score = 0;
	while (index_score <= max_score)
	{
		if (!ft_lstsize(*st_a))
			return ;
		if (find_score(st_a, index_score, size, &temp_min_data))
			order_alg(temp_min_data, st_a, st_b, op);
		else
			index_score += 1;
	}
}

void	ft_medium_alg(t_list **st_a, t_list **st_b, t_oper **op, t_para **param)
{
	t_list	*current;
	int		max_score;
	int		size;
	int		maxdata;
	int		bucket;

	current = *st_a;
	size = ft_lstsize(*st_a);
	maxdata = find_max(st_a);
	max_score = 0;
	while (current != NULL)
	{
		bucket = ft_bucket_no(current->data, size, maxdata);
		if (max_score < bucket)
			max_score = bucket;
		current = current->next;
	}
	sort_to_b(st_a, st_b, max_score, op);
	while (ft_lstsize(*st_a) > 0)
		ft_push(st_a, st_b, op, 1);
	while (ft_lstsize(*st_b) > 0)
	{
		find_max2(st_b, op, param);
		ft_push(st_b, st_a, op, 0);
	}
}
