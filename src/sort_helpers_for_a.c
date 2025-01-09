/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers_for_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:17:32 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/09 03:54:06 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** cost_helper:
**--------------------------
** Set the push cost for each node in stack A
*/
static void cost_helper(t_item *a_stack, int a_size, int b_size)
{
	if (a_stack->above_median)
	{
		if (a_stack->index > a_stack->target->index)
			a_stack->push_cost = a_stack->index;
		else
			a_stack->push_cost = a_stack->target->index;
	}
	else
	{
		if (a_size - a_stack->index > b_size - a_stack->target->index)
			a_stack->push_cost = a_size - a_stack->index;
		else
			a_stack->push_cost = b_size - a_stack->target->index;
	}
}

void	set_cost(t_item *a_stack, t_item *b_stack)
{
	int	a_size;
	int	b_size;

	a_size = get_size(a_stack);
	b_size = get_size(b_stack);
	while (a_stack)
	{
		if (a_stack->above_median == a_stack->target->above_median)
		{
			cost_helper(a_stack, a_size, b_size);
		}
		else
		{
			if (a_stack->above_median)
				a_stack->push_cost = a_stack->index;
			else
				a_stack->push_cost = a_size - a_stack->index;
			if (a_stack->target->above_median)
				a_stack->push_cost += a_stack->target->index;
			else
				a_stack->push_cost += b_size - a_stack->target->index;
		}
		a_stack = a_stack->next;
	}
}

void	set_target_node_a(t_item *a_stack, t_item *b_stack)
{
	t_item	*curser;
	t_item	*target;
	long	closest_match;

	while (a_stack)
	{
		closest_match = LONG_MAX;
		curser = b_stack;
		while (curser)
		{
			if (curser->val < a_stack->val)
			{
				if (LONG_MAX == closest_match || curser->val > closest_match)
				{
					closest_match = curser->val;
					target = curser;
				}
			}
			curser = curser->next;
		}
		if (closest_match == LONG_MAX)
			a_stack->target = get_max(b_stack);
		else
			a_stack->target = target;
		a_stack = a_stack->next;
	}
}

void	update_nodes_a(t_item *a_stack, t_item *b_stack)
{
	update_node_index(a_stack);
	update_node_index(b_stack);
	set_target_node_a(a_stack, b_stack);
	set_cost(a_stack, b_stack);
	set_cheapest(a_stack);
}
