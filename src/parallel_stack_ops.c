/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_stack_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:14:24 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/23 18:52:45 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



int	ss(t_item **stack_a, t_item **stack_b)
{
	int	a;
	int	b;

	a = sa(stack_a);
	b = sb(stack_b);
	if (a && b)
		return (1);
	return (0);
}

int rr(t_item **stack_a, t_item **stack_b)
{
    int a;
    int b;
    
    a = ra(stack_a);
    b = rb(stack_b);
    if (a && b)
        return (1);
    return (0);
}

int rrr(t_item **stack_a, t_item **stack_b)
{
    int a;
    int b;
    
    a = rra(stack_a);
    b = rrb(stack_b);
    if (a && b)
        return (1);
    return (0);
}