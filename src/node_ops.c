/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:20:37 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/11 13:31:12 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_set_cheapest(t_item *stack)
{
	t_item	*cheapest;
	int		value;

	if (!stack)
		return ;
	value = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < value)
		{
			value = stack->push_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = true;
}

void	ft_update_node_index(t_item *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = ft_get_size(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		index++;
	}
}

void	ft_set_cheapest_on_top_a(t_item **stack, t_item *top)
{
	while (*stack != top)
	{
		if (top->above_median)
		{
			ft_ra(stack, true);
		}
		else
		{
			ft_rra(stack, true);
		}
	}
}

void	ft_set_cheapest_on_top_b(t_item **stack, t_item *top)
{
	while (*stack != top)
	{
		if (top->above_median)
		{
			ft_rb(stack, true);
		}
		else
		{
			ft_rrb(stack, true);
		}
	}
}
