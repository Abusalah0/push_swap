/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:10:34 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/11 13:27:11 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_item **stack, bool print)
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
	{
		ft_putstr_fd("sa\n", 1);
	}
}

void	ft_pa(t_item **a_stack, t_item **b_stack, bool print)
{
	ft_push(a_stack, b_stack);
	if (print)
	{
		ft_putstr_fd("pa\n", 1);
	}
}

void	ft_ra(t_item **stack, bool print)
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
	{
		ft_putstr_fd("ra\n", 1);
	}
}

void	ft_rra(t_item **stack, bool print)
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
	{
		ft_putstr_fd("rra\n", 1);
	}
}
