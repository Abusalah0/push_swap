/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:15:08 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/23 23:46:14 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    set_node_index(t_item *stack)
{
    int index;
    int median;

    index = 0;
    median = get_size(stack) / 2;
    while (stack)
    {
        stack->index = index++;
        if (index <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
    }
    
}

void    set_target_node(t_item *a_stack, t_item *b_stack)
{
    t_item *cursor;
    t_item *target;
    int closest_min;

    while (a_stack)
    {
        closest_min = INT_MIN;
        cursor = b_stack;
        while (cursor)
        {
            if (cursor->val < a_stack->val && cursor->val > closest_min)
            {
                closest_min = cursor->val;
                target = cursor;
            }
            cursor = cursor->next;
        }
        if (closest_min == INT_MIN)
            a_stack->target = get_max(b_stack);
        else
            a_stack->target = target;
        a_stack = a_stack->next;
    }
}

void cost_analysis(t_item *a_stack, t_item *b_stack)
{
    int a_size;
    int b_size;

    a_size = get_size(a_stack);
    b_size = get_size(b_stack);
    while (a_stack)
    {
        a_stack->push_cost = a_stack->index;
        if(!a_stack->above_median)
        {
            a_stack->push_cost = a_size - a_stack->index;
        }
        if(a_stack->target->above_median)
        {
            a_stack->push_cost += a_stack->target->index;
        }
        else
        {
            a_stack->push_cost += b_size - a_stack->target->index;
        }
        a_stack = a_stack->next;
    }
}

void    set_cheapest(t_item *stack)
{
    t_item  *cheapest;
    int value;

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
