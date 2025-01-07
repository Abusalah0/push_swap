/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:12:31 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/07 14:35:38 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sb(t_item **stack, bool print)
{
	t_item	*tmp;

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

void	pb(t_item **a_stack, t_item **b_stack, bool print)
{
	push(b_stack, a_stack);
	if (print)
		printf("pb\n");
}

void	rb(t_item **stack, bool print)
{
	t_item	*tmp;
	t_item	*last;

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

void	rrb(t_item **stack, bool print)
{
	t_item	*tmp;
	t_item	*last;

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
