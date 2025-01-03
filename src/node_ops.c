/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:32:18 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/03 21:04:41 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    set_cheapest(t_item *stack)
{
    t_item *cheapest;
    int     value;

    if (!stack)
        return ;
    value = INT_MAX;
    while(stack)
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

void    cost_analysis_a(t_item *a_stack, t_item *b_stack)
{
    int a_size;
    int b_size;

    a_size = get_size(a_stack);
    b_size = get_size(b_stack);
    while (a_stack)
    {
        a_stack->push_cost = a_size - a_stack->index;
        if (!a_stack->above_median)
            a_stack->push_cost = a_size - a_stack->index;
        if (a_stack->target->above_median)
            a_stack->push_cost += a_stack->target->index;
        else
            a_stack->push_cost += b_size - (a_stack->target->index);
        a_stack = a_stack->next;
    }
}

void    current_index(t_item *stack)
{
    int index;
    int median;
    
    if (!stack)
        return ;
    index = 0;
    median = get_size(stack) / 2;
    while (stack)
    {
        stack->index = index++;
        stack->above_median = stack->index < median;
        stack = stack->next;
    }
}

void    set_target_node_a(t_item *a_stack, t_item *b_stack)
{
    t_item *curser;
    t_item *target;
    int     closest_match;
    
    while (a_stack)
    {
        closest_match = INT_MIN;
        curser = b_stack;
        while (curser)
        {
            if (curser->val > a_stack->val && curser->val > closest_match)
            {
                closest_match = curser->val;
                target = curser;
            }
            curser = curser->next;
        }
        if(closest_match == INT_MIN)
            a_stack->target = get_max(b_stack);
        else
            a_stack->target = target;
        a_stack = a_stack->next;
    }
}

void    update_nodes_a(t_item *a_stack, t_item *b_stack)
{
    current_index(a_stack);
    current_index(b_stack);
    set_target_node_a(a_stack,b_stack);
    cost_analysis_a(a_stack, b_stack);
    set_cheapest(a_stack);
}