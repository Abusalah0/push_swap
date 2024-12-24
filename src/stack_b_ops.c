/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:11:09 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/23 15:29:07 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int sb(t_item **stack)
{
    t_item *first, *second;

    if (!stack || get_size(*stack) < 2)
        return (0);
    first = top(*stack);
    second = first->prev;
    first->prev = second->prev;
    if (second->prev)
        second->prev->next = first;
    second->prev = first;
    second->next= NULL;
    first->next= second;
    printf("sb\n");
    return (1);
}

int pb(t_item **stack_a, t_item **stack_b)
{
    if (!stack_b || !*stack_b)
        return (0);
    if (!push(stack_a, top(*stack_b)->val))
    {
        free_stack(*stack_a);
        free_stack(*stack_b);
        exit(EXIT_FAILURE);
    }
    pop(stack_b);
    printf("pb\n");
    return (1);
}

int rrb(t_item **stack)
{
    t_item *first, *last;

    if (!stack || get_size(*stack) < 2)
        return (0);
    first = *stack;
    *stack = first->next;
    (*stack)->prev = NULL;
    last = first;
    while (last->next)
        last = last->next;
    last->next = first;
    first->prev = last;
    first->next = NULL;
    printf("rrb\n");
    return (1);
}

int rb(t_item **stack)
{
    t_item *last, *second_last;

    if (!stack || get_size(*stack) < 2)
        return (0);
    last = *stack;
    while (last->next)
        last = last->next;
    second_last = last->prev;
    second_last->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
    printf("rb\n");
    return (1);
}