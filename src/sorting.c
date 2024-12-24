/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:51:35 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/23 23:45:11 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_three(t_item **stack)
{
    t_item *max;
    
    max = get_max(*stack);
    if (max == *stack)
    {
        ra(stack);
    }
    else if (max == (*stack)->next)
    {
        rra(stack);
    }
    if ((*stack)->val > (*stack)->next->val)
        sa(stack);
}

void    update_a(t_item *a_stack, t_item *b_stack)
{
    set_node_index(a_stack);
    set_node_index(b_stack);
    set_target_node(a_stack, b_stack);
    cost_analysis(a_stack, b_stack);
    set_cheapest(a_stack);
}

void    set_target_node_b(t_item *a_stack, t_item *b_stack)
{
    t_item *cursor;
    t_item *target;
    int closest_max;

    while (b_stack)
    {
        closest_max = INT_MAX;
        cursor = a_stack;
        while (cursor)
        {
        if (cursor->val > b_stack->val && cursor->val < closest_max)
        {
            closest_max = cursor->val;
            target = cursor;
        }
            cursor = cursor->next;
        }
        if (closest_max == INT_MAX)
            b_stack->target = get_min(a_stack);
        else
            b_stack->target = target;
        b_stack = b_stack->next;
    }
}
void    update_b(t_item *a_stack, t_item *b_stack)
{
    set_node_index(a_stack);
    set_node_index(b_stack);
    set_target_node_b(a_stack, b_stack);
}
void move_a_to_b(t_item **a_stack, t_item **b_stack)
{
    t_item *cheapest;

    cheapest = get_cheapest(*a_stack);
    if (cheapest->above_median && cheapest->target->above_median)
        rotate_both(a_stack, b_stack, cheapest);
    else if (!cheapest->above_median && !cheapest->target->above_median)
        rev_rotate_both(a_stack,b_stack,cheapest);
    prep_for_push(a_stack, cheapest, 'a');
    prep_for_push(b_stack, cheapest, 'b');
    pb(a_stack, b_stack);
}
void    move_b_to_a(t_item **a_stack, t_item **b_stack)
{
    prep_for_push(a_stack, (*b_stack)->target, 'a');
    pa(a_stack, b_stack);
}
void    turk_sort(t_item **a_stack, t_item **b_stack)
{
    int stack_size;

    stack_size = get_size(*a_stack);
    if (stack_size > 3 && !is_sorted(*a_stack))
        pb(a_stack, b_stack);
    if (--stack_size > 3 && !is_sorted(*a_stack))
        pb(a_stack, b_stack);
    while (--stack_size > 3 && !is_sorted(*a_stack))
    {
        update_a(*a_stack, *b_stack);
        move_a_to_b(a_stack, b_stack);
    }
    sort_three(a_stack);
    while (*b_stack)
    {
        update_b(*a_stack, *b_stack);
        move_b_to_a(a_stack, b_stack);
    }
    set_node_index(*a_stack);
    min_on_top(a_stack);
}