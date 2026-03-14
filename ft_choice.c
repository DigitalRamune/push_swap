/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:59:15 by inaciri           #+#    #+#             */
/*   Updated: 2026/03/12 11:58:55 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_bench(t_para **param, t_oper **op, float disorder)
{
	int		total_ops;

	total_ops = (*op)->pa + (*op)->pb + (*op)->ra + (*op)-> rb;
	total_ops += (*op)->rr + (*op)->rra + (*op)->rrb + (*op)->rrr;
	total_ops += (*op)->sa + (*op)->sb + (*op)->ss;
	ft_printf(2, "[bench] disorder : %f%%\n", disorder);
	ft_printf(2, "[bench] strategy : %s \n", (*param)->choice);
	ft_printf(2, "[bench] total_ops : %d\n", total_ops);
	ft_printf(2, "[bench] sa : %d sb : %d ", (*op)->sa, (*op)->sb);
	ft_printf(2, "ss : %d ", (*op)->ss);
	ft_printf(2, "pa : %d pb : %d \n", (*op)->pa, (*op)->pb);
	ft_printf(2, "[bench] ra : %d rb : %d ", (*op)->ra, (*op)->rb);
	ft_printf(2, "rr : %d ", (*op)->rr);
	ft_printf(2, "rra : %d rrb : %d ", (*op)->rra, (*op)->rrb);
	ft_printf(2, "rrr : %d \n", (*op)->rrr);
}

void	ft_bench(t_oper **op, t_para **param, t_list **st_a, t_list **st_b)
{
	float	disorder;
	int		alg_nbr;

	alg_nbr = (*param)->complex + (*param)->medium + (*param)->simple;
	(*param)->bench = 0;
	disorder = compute_disorder(st_a);
	if (alg_nbr == 1)
	{
		(*op)->print = -1;
		set_alg(param, st_a, st_b, op);
	}
	else
	{
		ft_adaptive(param, st_a);
		set_alg(param, st_a, st_b, op);
	}
	print_bench(param, op, disorder);
}

void	set_alg(t_para **param, t_list **stack_a, t_list **stack_b, t_oper **op)
{
	if ((*param)->bench == 1)
		ft_bench(op, param, stack_a, stack_b);
	else if ((*param)->complex == 1)
	{
		set_base_rank(stack_a);
		set_all_rank(stack_a);
		ft_radix(stack_a, stack_b, op, param);
	}
	else if ((*param)->medium == 1)
		ft_medium_alg(stack_a, stack_b, op);
	else if ((*param)->simple == 1)
		ft_simple_alg(stack_a, stack_b, op, param);
	else if ((*param)->adaptiv == 1)
	{
		ft_adaptive(param, stack_a);
		set_alg(param, stack_a, stack_b, op);
	}
}
