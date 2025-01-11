/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:23:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/11 13:38:54 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define EMPTY_SLOT LONG_MIN

typedef struct s_item
{
	int				val;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_item	*target;
	struct s_item	*next;
	struct s_item	*prev;
}					t_item;

// // Stack operations
void				ft_sa(t_item **stack, bool print);
void				ft_sb(t_item **stack, bool print);
void				ft_ss(t_item **stack_a, t_item **stack_b, bool print);
void				ft_pa(t_item **a_stack, t_item **b_stack, bool print);
void				ft_pb(t_item **a_stack, t_item **b_stack, bool print);
void				ft_ra(t_item **stack, bool print);
void				ft_rb(t_item **stack, bool print);
void				ft_rr(t_item **stack_a, t_item **b_stack, bool print);
void				ft_rra(t_item **stack, bool print);
void				ft_rrb(t_item **stack, bool print);
void				ft_rrr(t_item **stack_a, t_item **b_stack, bool print);
void				ft_rrotate(t_item **a, t_item **b, t_item *cheapest_node);
void				ft_rotate(t_item **a_stack, t_item **b_stack,
						t_item *cheapest);

// // Sorting operations
void				ft_sort_three(t_item **stack);
void				ft_update_nodes_a(t_item *a_stack, t_item *b_stack);
void				ft_update_nodes_b(t_item *a_stack, t_item *b_stack);
void				ft_move_a_to_b(t_item **a_stack, t_item **b_stack);
void				ft_move_b_to_a(t_item **a_stack, t_item **b_stack);
void				ft_turk_sort(t_item **a_stack, t_item **b_stack);
void				ft_sort(t_item **a_stack, t_item **b_stack);
// // Stack helpers
void				ft_pop(t_item **stack);
void				ft_push(t_item **dst, t_item **src);
t_item				*ft_setup_node(int *values, bool, bool cheapest,
						t_item *target);
void				ft_fill_stack(t_item **stack, int *numbers, int size);

// Search operations
t_item				*ft_get_max(t_item *stack);
t_item				*ft_get_min(t_item *stack);
t_item				*ft_top(t_item *stack);
int					ft_get_size(t_item *stack);
t_item				*ft_get_cheapest(t_item *stack);

// Parallel operations
void				ft_move_min_to_top(t_item **a_stack);
void				ft_set_cheapest_on_top_a(t_item **stack, t_item *top);
void				ft_set_cheapest_on_top_b(t_item **stack, t_item *top);

// // Node operations
void				ft_update_node_index(t_item *stack);
void				ft_set_target_node_a(t_item *a_stack, t_item *b_stack);
void				ft_set_target_node_b(t_item *a_stack, t_item *b_stack);
void				ft_set_cheapest(t_item *stack);
void				ft_set_cost(t_item *a_stack, t_item *b_stack);

// Error handling
void				ft_error_exit(void);
void				ft_free_stack(t_item *stack);

// Input parsing
int					*ft_check_input(int argc, char **argv);
bool				ft_is_sorted(t_item *stack);
bool				ft_check_for_dups(int *nums, int nums_size);
#endif