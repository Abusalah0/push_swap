/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:20:37 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/05 21:20:53 by abdsalah         ###   ########.fr       */
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