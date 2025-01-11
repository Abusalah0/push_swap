/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:13:27 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/11 13:39:50 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** 		sort()
** -----------------------
** Sorts the stack using the turk_sort algorithm.
** or the sort_three algorithm if the stack size is 3.
*/

void	ft_sort(t_item **a_stack, t_item **b_stack)
{
	if (!ft_is_sorted(*a_stack))
	{
		if (ft_get_size(*a_stack) == 2)
			ft_sa(a_stack, true);
		else if (ft_get_size(*a_stack) == 3)
			ft_sort_three(a_stack);
		else
			ft_turk_sort(a_stack, b_stack);
	}
}
/*
** 		move_min_to_top()
** -----------------------
** make sure the min is on top after sorting
*/

void	ft_move_min_to_top(t_item **a_stack)
{
	while ((*a_stack)->val != ft_get_min(*a_stack)->val)
	{
		if (ft_get_min(*a_stack)->above_median)
			ft_ra(a_stack, true);
		else
			ft_rra(a_stack, true);
	}
}

void	ft_move_a_to_b(t_item **a_stack, t_item **b_stack)
{
	t_item	*cheapest;

	cheapest = ft_get_cheapest(*a_stack);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		ft_rotate(a_stack, b_stack, cheapest);
	}
	else if (!cheapest->above_median && !cheapest->target->above_median)
	{
		ft_rrotate(a_stack, b_stack, cheapest);
	}
	ft_set_cheapest_on_top_a(a_stack, cheapest);
	ft_set_cheapest_on_top_b(b_stack, cheapest->target);
	ft_pb(a_stack, b_stack, true);
}

/*
** sort_three()
** -----------------------
** Sorts a stack of size 3.
*/
void	ft_sort_three(t_item **stack)
{
	t_item	*max;

	max = ft_get_max(*stack);
	if (max == *stack)
	{
		ft_ra(stack, true);
	}
	else if (max == (*stack)->next)
	{
		ft_rra(stack, true);
	}
	if ((*stack)->val > (*stack)->next->val)
	{
		ft_sa(stack, true);
	}
}
/*
** turk_sort()
** -----------------------
** Sorts a stack of size 4 or more.
** where the magic happens
*/

void	ft_turk_sort(t_item **a_stack, t_item **b_stack)
{
	int	size;

	size = ft_get_size(*a_stack);
	if (size > 3)
		ft_pb(a_stack, b_stack, true);
	if (--size > 3 && !ft_is_sorted(*a_stack))
		ft_pb(a_stack, b_stack, true);
	while (--size > 3 && !ft_is_sorted(*a_stack))
	{
		ft_update_nodes_a(*a_stack, *b_stack);
		ft_move_a_to_b(a_stack, b_stack);
	}
	ft_sort_three(a_stack);
	while (*b_stack)
	{
		ft_update_nodes_b(*a_stack, *b_stack);
		ft_move_b_to_a(a_stack, b_stack);
	}
	ft_update_node_index(*a_stack);
	ft_move_min_to_top(a_stack);
}
