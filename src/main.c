/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:39:06 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/11 13:38:58 by abdsalah         ###   ########.fr       */
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
	num = ft_check_input(argc, argv);
	if (!num)
		ft_error_exit();
	ft_fill_stack(&a_stack, num, argc - 1);
	free(num);
	ft_sort(&a_stack, &b_stack);
	ft_free_stack(a_stack);
	ft_free_stack(b_stack);
	return (0);
}
