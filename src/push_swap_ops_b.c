/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:43:02 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/03 21:25:17 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sa(t_item **stack, bool print)
{
    t_item *tmp;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
    tmp->prev = *stack;
    (*stack)->prev = NULL;
    if (print)
        printf("sa\n");
}
void    sb(t_item **stack, bool print)
{
    t_item *tmp;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
    tmp->prev = *stack;
    (*stack)->prev = NULL;
    if (print)
        printf("sb\n");
}
void    ss(t_item **a_stack, t_item **b_stack)
{
    sa(a_stack, false);
    sb(b_stack, false);
    printf("ss\n");
}

void    pa(t_item **a_stack, t_item **b_stack, bool print)
{
    push(a_stack, b_stack);
    if (print)
        printf("pa\n");
}
void   pb(t_item **a_stack, t_item **b_stack, bool print)
{
    push(b_stack, a_stack);
    if (print)
        printf("pb\n");
}
void   ra(t_item **stack, bool print)
{
    t_item *tmp;
    t_item *last;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    last = *stack;
    while (last->next)
        last = last->next;
    *stack = (*stack)->next;
    last->next = tmp;
    tmp->next = NULL;
    tmp->prev = last;
    (*stack)->prev = NULL;
    if (print)
        printf("ra\n");
}

void  rb(t_item **stack,bool print)
{
    t_item *tmp;
    t_item *last;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    last = *stack;
    while (last->next)
        last = last->next;
    *stack = (*stack)->next;
    last->next = tmp;
    tmp->next = NULL;
    tmp->prev = last;
    (*stack)->prev = NULL;
    if (print)
        printf("rb\n");
}

void  rr(t_item **a_stack, t_item **b_stack)
{
    ra(a_stack, false);
    rb(b_stack, false);
    printf("rr\n");
}

void rra(t_item **stack, bool print)
{
    t_item *tmp;
    t_item *last;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    while (tmp->next->next)
        tmp = tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    last->next = *stack;
    *stack = last;
    tmp->prev = NULL;
    if (print)
        printf("rra\n");
}

void rrb(t_item **stack, bool print)
{
    t_item *tmp;
    t_item *last;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    while (tmp->next->next)
        tmp = tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    last->next = *stack;
    *stack = last;
    tmp->prev = NULL;
    if (print)
        printf("rrb\n");
}

void rrr(t_item **a_stack, t_item **b_stack)
{
    rra(a_stack, false);
    rrb(b_stack, false);
    printf("rrr\n");
}