/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:59:15 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/12 11:55:56 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_bench(p_list **param, t_list **stack_a, t_oper **op, float disorder)
{
	int		total_ops;
	(void)	stack_a;

	total_ops = (*op)->pa + (*op)->pb + (*op)->ra + (*op)-> rb;
	total_ops += (*op)->rr + (*op)->rra + (*op)->rrb + (*op)->rrr;
	printf("[bench] disorder : %.1f%%\n[bench] strategy : %s \n[bench] total_ops : %d\n", disorder, (*param)->choice, total_ops);
	printf("[bench] sa : %d sb : %d ss : %d pa : %d pb : %d \n", (*op)->sa, (*op)->sb, (*op)->ss, (*op)->pa, (*op)->pb);
	printf("[bench] ra : %d rb : %d rr : %d rra : %d rrb : %d rrr : %d \n", (*op)->ra, (*op)->rb, (*op)->rr, (*op)->rra, (*op)->rrb, (*op)->rrr);
}

void	ft_bench(t_oper **op, p_list **param, t_list **stack_a, t_list **stack_b)
{
	float disorder;
	
	(*op)->print = 1;
	(*param)->bench = 0;
	ft_adaptive(param, stack_a);
	disorder = compute_disorder(stack_a);
	set_alg(param, stack_a, stack_b, op);
	print_bench(param, stack_a, op, disorder);
}

void	set_alg(p_list **param, t_list **stack_a, t_list **stack_b, t_oper **op)
{
	if ((*param)->complex == 1)
	{
		set_base_rank(stack_a);
		set_all_rank(stack_a);
		ft_radix(stack_a, stack_b, op);
	}
	else if ((*param)->medium == 1)
		ft_medium_alg(stack_a, stack_b, op);
	else if ((*param)->simple == 1)
		ft_simple_alg(stack_a, stack_b, op);
	else if ((*param)->bench == 1 || (*param)->adaptiv == 1)
	{
		if ((*param)->bench == 1)
		{
			ft_bench(op, param, stack_a, stack_b);
		}
		else
		{
			ft_adaptive(param, stack_a);
			set_alg(param, stack_a, stack_b, op);
		}
	}
}

