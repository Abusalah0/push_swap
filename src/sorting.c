/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:13:27 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/07 14:36:17 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_item **a_stack, t_item **b_stack)
{
	if (!is_sorted(*a_stack))
	{
		if (get_size(*a_stack) == 2)
			sa(a_stack, true);
		else if (get_size(*a_stack) == 3)
			sort_three(a_stack);
		else
			turk_sort(a_stack, b_stack);
	}
}

void	min_on_top(t_item **a_stack)
{
	while ((*a_stack)->val != get_min(*a_stack)->val)
	{
		if (get_min(*a_stack)->above_median)
			ra(a_stack, true);
		else
			rra(a_stack, true);
	}
}


void	move_a_to_b(t_item **a_stack, t_item **b_stack)
{
	t_item	*cheapest;

	cheapest = get_cheapest(*a_stack);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		rotate_both(a_stack, b_stack, cheapest);
	}
	else if (!cheapest->above_median && !cheapest->target->above_median)
	{
		rev_rotate_both(a_stack, b_stack, cheapest);
	}
	prep_for_push(a_stack, cheapest, 'a');
	prep_for_push(b_stack, cheapest->target, 'b');
	pb(a_stack, b_stack, true);
}

void	sort_three(t_item **stack)
{
	t_item	*max;

	max = get_max(*stack);
	if (max == *stack)
	{
		ra(stack, true);
	}
	else if (max == (*stack)->next)
	{
		rra(stack, true);
	}
	if ((*stack)->val > (*stack)->next->val)
	{
		sa(stack, true);
	}
}

void	turk_sort(t_item **a_stack, t_item **b_stack)
{
	int	size;

	size = get_size(*a_stack);
	if (size > 3)
		pb(a_stack, b_stack, true);
	if (--size > 3 && !is_sorted(*a_stack))
		pb(a_stack, b_stack, true);
	while (--size > 3 && !is_sorted(*a_stack))
	{
		update_nodes_a(*a_stack, *b_stack);
		move_a_to_b(a_stack, b_stack);
	}
	sort_three(a_stack);
	while (*b_stack)
	{
		update_nodes_b(*a_stack, *b_stack);
		move_b_to_a(a_stack, b_stack);
	}
	current_index(*a_stack);
	min_on_top(a_stack);
}
