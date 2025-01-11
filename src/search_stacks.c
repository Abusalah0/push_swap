/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:39:28 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/11 13:31:59 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_item	*ft_get_max(t_item *stack)
{
	int		max;
	t_item	*node_to_return;

	if (!stack)
		return (NULL);
	node_to_return = (NULL);
	max = -2147483648;
	while (stack)
	{
		if (stack->val > max)
		{
			node_to_return = stack;
			max = stack->val;
		}
		stack = stack->next;
	}
	return (node_to_return);
}

t_item	*ft_get_min(t_item *stack)
{
	int		min;
	t_item	*node_to_return;

	if (!stack)
		return (NULL);
	node_to_return = NULL;
	min = 2147483647;
	while (stack)
	{
		if (stack->val < min)
		{
			node_to_return = stack;
			min = stack->val;
		}
		stack = stack->next;
	}
	return (node_to_return);
}

int	ft_get_size(t_item *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_item	*ft_get_cheapest(t_item *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

bool	ft_is_sorted(t_item *stack)
{
	t_item	*tmp;

	if (!stack || !stack->next)
		return (true);
	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->val > tmp->next->val)
		{
			return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}
