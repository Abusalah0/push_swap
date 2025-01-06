/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:23:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/06 14:59:21 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

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
void				sa(t_item **stack, bool print);
void				sb(t_item **stack, bool print);
void				ss(t_item **stack_a, t_item **stack_b, bool print);
void				pa(t_item **a_stack, t_item **b_stack, bool print);
void				pb(t_item **a_stack, t_item **b_stack, bool print);
void				ra(t_item **stack, bool print);
void				rb(t_item **stack, bool print);
void				rr(t_item **stack_a, t_item **b_stack, bool print);
void				rra(t_item **stack, bool print);
void				rrb(t_item **stack, bool print);
void				rrr(t_item **stack_a, t_item **b_stack, bool print);
void				rev_rotate_both(t_item **a, t_item **b,
						t_item *cheapest_node);
void				rotate_both(t_item **a_stack, t_item **b_stack,
						t_item *cheapest);

// // Sorting operations
void				sort_three(t_item **stack);
void				update_nodes_a(t_item *a_stack, t_item *b_stack);
void				update_nodes_b(t_item *a_stack, t_item *b_stack);
void				move_a_to_b(t_item **a_stack, t_item **b_stack);
void				move_b_to_a(t_item **a_stack, t_item **b_stack);
void				turk_sort(t_item **a_stack, t_item **b_stack);
void				sort(t_item **a_stack, t_item **b_stack);
// // Stack helpers
void				pop(t_item **stack);
void				push(t_item **dst, t_item **src);
void				print_stack(t_item *stack);
t_item				*setup_node(int *values, bool, bool cheapest,
						t_item *target);
void				fill_stack(t_item **stack, int *numbers, int size);

// Search operations
t_item				*get_max(t_item *stack);
t_item				*get_min(t_item *stack);
t_item				*top(t_item *stack);
int					get_size(t_item *stack);
t_item				*get_cheapest(t_item *stack);

// Parallel operations
void				min_on_top(t_item **a_stack);
void				prep_for_push(t_item **stack, t_item *cheapest, char name);

// // Node operations
void				current_index(t_item *stack);
void				set_target_node_a(t_item *a_stack, t_item *b_stack);
void				set_target_b(t_item *a_stack, t_item *b_stack);
void				cost_analysis(t_item *a_stack, t_item *b_stack);
void				set_cheapest(t_item *stack);

// Error handling
void				error_exit(char *str, void **allocated_mem, int count);
void				free_split(char **split);
void				free_stack(t_item *stack);

// Input parsing
int					*check_input(int argc, char **argv);
bool				is_sorted(t_item *stack);
#endif