/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:39:06 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/05 21:40:10 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_sorted(t_item *stack)
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

int	main(int argc, char **argv)
{
	int		*num;
	t_item	*a_stack;
	t_item	*b_stack;

	if (argc < 2)
		return (1);
	a_stack = NULL;
	b_stack = NULL;
	num = check_input(argc, argv);
	if (!num)
		return (1);
	fill_stack(&a_stack, num, argc - 1);
	if (!is_sorted(a_stack))
	{
		if (get_size(a_stack) == 2)
			sa(&a_stack, true);
		else if (get_size(a_stack) == 3)
			sort_three(&a_stack);
		else
			turk_sort(&a_stack, &b_stack);
	}
	free(num);
	return (0);
}
