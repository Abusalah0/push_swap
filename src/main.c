/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:29:14 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/24 00:39:14 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool is_sorted(t_item *stack)
{
    t_item *tmp;

    if (!stack || !stack->next) // Empty or single-node list
        return (true);
    tmp = stack;
    while (tmp->next)
    {
        if (tmp->val > tmp->next->val)
		    return (false);
        tmp = tmp->next;
    }
    return (true);
}

int	main(int argc, char **argv)
{
	int *num;
	t_item *a_stack;
	t_item *b_stack;
	
	if (argc < 2)
		return (1);// error
	a_stack = NULL;
	b_stack = NULL;
	num = check_input(argc, argv);
	if (!num)
		return (1);//error
	fill_stack(&a_stack, num, argc - 1);
	if (!is_sorted(a_stack))
	{
		if(get_size(a_stack) == 2)
			sa(&a_stack);
		else if (get_size(a_stack) == 3)
			sort_three(&a_stack);
		else
			turk_sort(&a_stack, &b_stack);
	}
	return (0);
}
