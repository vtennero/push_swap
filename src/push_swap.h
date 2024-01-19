/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:32:10 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 16:29:04 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_workflow {
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	op_cost;
	int	next_nbr;
}	t_workflow;

typedef struct s_rot_costs {
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
}	t_rot_costs;

/*
** ------------------------- INPUT CHECKS -------------------------
*/
int				parse_args(int argc, char **argv);
/*
** ------------------------- SOLVER -------------------------
*/
int				sort_big(t_stack **a, t_stack **b);
void			sort_three(t_stack **a);
void			sort_two(t_stack **a);
/*
** ------------------------- STACK MANAGEMENT -------------------------
*/
t_stack			*ft_lstlast(t_stack *lst);
int				ft_lstsize(t_stack *lst);
t_stack			*append_to_list(t_stack **head, int nbr);
void			free_stack(t_stack *head);
int				find_stack_max(t_stack *stack);
int				find_stack_min(t_stack *stack);
int				find_nbr_index_in_stack(t_stack *a, int nbr);
int				stack_is_sorted_asc(t_stack *stack);
int				stack_is_sorted_desc(t_stack *stack);
/*
** ------------------------- WORKFLOW -------------------------
*/
t_workflow		*init_workflow_struct(void);
int				def_workflow_a_to_b(t_stack *a, t_stack *b, \
int nbr, t_workflow *w);
int				def_workflow_b_to_a(t_stack *a, t_stack *b, \
int nbr, t_workflow *w);
void			update_workflow(t_workflow *w, int m_cost, \
int nbr, t_rot_costs *c);
void			execute_workflow(t_workflow *workflow, t_stack **a, \
t_stack **b);
void			optimize_workflow(t_workflow *workflow);
void			reset_workflow(t_workflow *workflow);
void			set_workflow_zero(int combination, t_workflow *w, \
t_rot_costs *c);
void			set_workflow_one(int combination, t_workflow *w, \
t_rot_costs *c);
void			set_workflow_two(int combination, t_workflow *w, \
t_rot_costs *c);
void			set_workflow_three(int combination, t_workflow *w, \
t_rot_costs *c);

/*
** ------------------------- COST CALCULATION -------------------------
*/
int				calc_rotation_cost(t_stack *stack, int nbr);
int				calc_r_rotation_cost(t_stack *stack, int nbr);
int				find_best_combination(t_rot_costs *costs);
int				determine_min_cost_combination(t_rot_costs \
*costs, int min_cost);
/*
** ------------------------- OPERATIONS -------------------------
*/
void			op_ra(t_stack **a, t_stack **b, int j);
void			op_rb(t_stack **b, t_stack **a, int j);
void			op_rr(t_stack **a, t_stack **b, int j);
void			op_sa(t_stack **a, t_stack **b, int j);
void			op_sb(t_stack **a, t_stack **b, int j);
void			op_ss(t_stack **a, t_stack **b, int j);
void			op_rra(t_stack **a, t_stack **b, int j);
void			op_rrb(t_stack **a, t_stack **b, int j);
void			op_rrr(t_stack **a, t_stack **b, int j);
void			op_pa(t_stack **a, t_stack **b, int j);
void			op_pb(t_stack **a, t_stack **b, int j);
/*
** ------------------------- DEBUG -------------------------
*/
void			debug_print_stack(t_stack *head, char c);
void			debug_print_stacks(t_stack *a, t_stack *b);
void			debug_print_workflow(t_workflow *workflow);
void			debug_print_rotations_costs(t_rot_costs \
*costs, int a_nbr, int b_nbr);
void			debug_print_stack_dense(t_stack *head);

#endif