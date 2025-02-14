/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:19:39 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/11 13:38:00 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_item **dst, t_item **src)
{
	t_item	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	ft_pop(t_item **stack)
{
	t_item	*tmp;

	if (!*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

void	ft_fill_stack(t_item **stack, int *numbers, int size)
{
	int		i;
	t_item	*new_node;

	i = size - 1;
	while (i >= 0)
	{
		new_node = ft_setup_node((int []){numbers[i], 0, 0}, false, false, NULL);
		if (!new_node)
		{
			ft_free_stack(*stack);
			free(numbers);
			ft_error_exit();
		}
		ft_push(stack, &new_node);
		i--;
	}
}

t_item	*ft_setup_node(int *values, bool above_median,
		bool cheapest, t_item *target)
{
	t_item	*node;

	node = malloc(sizeof(t_item));
	if (!node)
		return (NULL);
	node->val = values[0];
	node->index = values[1];
	node->push_cost = values[2];
	node->above_median = above_median;
	node->cheapest = cheapest;
	node->target = target;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
