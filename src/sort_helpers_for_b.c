/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers_for_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:32:18 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/05 21:28:02 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void move_b_to_a(t_item **a_stack, t_item **b_stack)
{
    prep_for_push(a_stack, (*b_stack)->target, 'a');
    pa(a_stack, b_stack, true);
}


void update_nodes_b(t_item *a_stack, t_item *b_stack)
{
    current_index(b_stack);
    current_index(a_stack);
    set_target_b(a_stack, b_stack);
}


void set_target_b (t_item *a_stack, t_item *b_stack)
{
    t_item *curser;
    t_item *target;
    int     closest_match;

    while (b_stack)
    {
        closest_match = INT_MAX;
        curser = a_stack;
        while (curser)
        {
            if (curser->val < closest_match && curser->val > b_stack->val)
            {
                closest_match = curser->val;
                target = curser;
            }
            curser = curser->next;
        }
        if (closest_match == INT_MAX)
            b_stack->target = get_min(a_stack);
        else
            b_stack->target = target;
        b_stack = b_stack->next;
    }
        
}