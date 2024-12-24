/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:05:59 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/23 19:13:06 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    min_on_top(t_item **a_stack)
{
    while ((*a_stack)->val != get_min(*a_stack)->val)
    {
        if (get_min(*a_stack)->above_median)
            ra(a_stack);
        else
            rra(a_stack);
    }
    
}

void    rotate_both(t_item **a_stack, t_item **b_stack, t_item *cheapest)
{
    while (*b_stack != cheapest->target && *a_stack != cheapest)
    {
        rr(a_stack, b_stack);
    }
    set_node_index(*a_stack);
    set_node_index(*b_stack);
}


void    rev_rotate_both(t_item **a_stack, t_item **b_stack, t_item *cheapest)
{
    while (*b_stack != cheapest->target && *a_stack != cheapest)
    {
        rrr(a_stack, b_stack);
    }
    set_node_index(*a_stack);
    set_node_index(*b_stack);
}

void    prep_for_push(t_item **stack, t_item *cheapest, char name)
{
    while (top(*stack) != cheapest)
    {
        if (name == 'a')
        {
            if (cheapest->above_median)
                ra(stack);
            else
                rra(stack);
        }
        else if (name == 'b')
        {
            if (cheapest->above_median)
                rb(stack);
            else
                rrb(stack);
        }
    }
}