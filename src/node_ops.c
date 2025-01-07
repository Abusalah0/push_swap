/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:20:37 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/08 01:37:46 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_cheapest(t_item *stack)
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

void	update_node_index(t_item *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = get_size(stack) / 2;
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

void	set_cheapest_on_top_a(t_item **stack, t_item *top)
{
	while (*stack != top)
	{
		if (top->above_median)
		{
			ra(stack, true);
		}
		else
		{
			rra(stack, true);
		}
	}
}

void	set_cheapest_on_top_b(t_item **stack, t_item *top)
{
	while (*stack != top)
	{
		if (top->above_median)
		{
			rb(stack, true);
		}
		else
		{
			rrb(stack, true);
		}
	}
}
