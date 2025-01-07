/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:39:06 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/07 14:35:57 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	{
		printf("Error\n");
		return (1);
	}
	fill_stack(&a_stack, num, argc - 1);
	sort(&a_stack, &b_stack);
	free(num);
	return (0);
}
