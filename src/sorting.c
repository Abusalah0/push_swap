/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:13:27 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/05 21:21:30 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	min_on_top(t_item **a_stack)
{
	while ((*a_stack)->val != get_min(*a_stack)->val)
	{
		if (get_min(*a_stack)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			ra(a_stack, true);
		else
			rra(a_stack, true);
	}
}


void prep_for_push(t_item **stack, t_item *top, char stack_name)
{
    while (*stack != top)
    {
        if (stack_name == 'a')
        {
            if (top->above_median)
                ra(stack, true);
            else
                rra(stack, true);
        }
        else if (stack_name == 'b')
        {
            if (top->above_median)
                rb(stack, true);
            else
                rrb(stack, true);
        }
    }
}
   
void move_a_to_b(t_item **a_stack, t_item **b_stack)
{
    t_item *cheapest;
    
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


void sort_three(t_item **stack)
{
    t_item *max;

    max = get_max(*stack);
    if(max == *stack)
    {
        ra(stack, true);
    }
    else if (max == (*stack)->next)
    {
        rra(stack, true);
    }
    if ((*stack)->val > (*stack)->next->val)
        sa(stack, true);
}

void    turk_sort(t_item **a_stack, t_item **b_stack)
{
    int size;

    size = get_size(*a_stack);
    if (size > 3)
        pb(a_stack, b_stack, true);
    if(--size > 3 && !is_sorted(*a_stack))
        pb(a_stack, b_stack, true);
    while(--size > 3 && !is_sorted(*a_stack))
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