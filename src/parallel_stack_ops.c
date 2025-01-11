/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_stack_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:43:02 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/11 13:31:40 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ss(t_item **a_stack, t_item **b_stack, bool print)
{
	ft_sa(a_stack, false);
	ft_sb(b_stack, false);
	if (print)
	{
		ft_putstr_fd("ss\n", 1);
	}
}

void	ft_rr(t_item **a_stack, t_item **b_stack, bool print)
{
	ft_ra(a_stack, false);
	ft_rb(b_stack, false);
	if (print)
	{
		ft_putstr_fd("rr\n", 1);
	}
}

void	ft_rrr(t_item **a_stack, t_item **b_stack, bool print)
{
	ft_rra(a_stack, false);
	ft_rrb(b_stack, false);
	if (print)
	{
		ft_putstr_fd("rrr\n", 1);
	}
}

void	ft_rotate(t_item **a_stack, t_item **b_stack, t_item *cheapest)
{
	while (*b_stack != cheapest->target && *a_stack != cheapest)
	{
		ft_rr(a_stack, b_stack, true);
	}
	ft_update_node_index(*a_stack);
	ft_update_node_index(*b_stack);
}

void	ft_rrotate(t_item **a, t_item **b, t_item *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		ft_rrr(a, b, true);
	ft_update_node_index(*a);
	ft_update_node_index(*b);
}
