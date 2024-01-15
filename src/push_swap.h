/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:32:10 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/15 16:22:42 by vitenner         ###   ########.fr       */
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


/*
** ------------------------- STACK MANAGEMENT -------------------------
*/

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack			*ft_lstlast(t_stack *lst);
int				ft_lstsize(t_stack *lst);
t_stack			*create_new_node(long nbr);
// t_stack			*create_new_node(long nbr, int index);
void			append_to_list(t_stack **head, long nbr);
void			free_stack(t_stack *head);
// void 			stack_reallocate_index(t_stack *stack);

/*
** ------------------------- INPUT CHECKS -------------------------
*/
int				parse_args(int argc, char **argv);

/*
** ------------------------- SOLVER -------------------------
*/

typedef struct s_workflow {
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	int op_cost;
	int next_nbr;
} t_workflow;

typedef struct s_rotation_costs {
	int ra;
	int rra;
	int rb;
	int rrb;
} t_rotation_costs;


void 		init_push(t_stack **a, t_stack **b);
void		find_cheapest_number(t_stack *a, t_stack *b, t_workflow *workflow);
t_workflow*	init_workflow_struct();
void		deal_with_last_three(t_stack **a, t_workflow *workflow);


/*
** ------------------------- OPERATIONS -------------------------
*/
void	op_ra(t_stack **a, t_stack **b, int j);
void	op_rb(t_stack **b, t_stack **a, int j);
void	op_rr(t_stack **a, t_stack **b, int j);
void	op_sa(t_stack **a, t_stack **b, int j);
void	op_sb(t_stack **a, t_stack **b, int j);
void	op_ss(t_stack **a, t_stack **b, int j);
void	op_rra(t_stack **a, t_stack **b, int j);
void	op_rrb(t_stack **a, t_stack **b, int j);
void	op_rrr(t_stack **a, t_stack **b, int j);
void	op_pa(t_stack **a, t_stack **b, int j);
void	op_pb(t_stack **a, t_stack **b, int j);

// void	w_op_swap(t_stack **a, t_stack **b, int j);
// void	w_op_rotate(t_stack **a, t_stack **b, int j);
// void	w_op_rev_rotate(t_stack **a, t_stack **b, int j);
// void	w_op_push(t_stack **a, t_stack **b, int j);
// void	op_swap_list(t_stack **head);
// void	op_rotate_list(t_stack **head);
// void	op_reverse_rotate_list(t_stack **head);
// void	op_push_to_list(t_stack **a, t_stack **b);


/*
** ------------------------- EXECUTE WORKFLOW/SOLVER -------------------------
*/

void execute_workflow(t_workflow *workflow, t_stack **a, t_stack **b);
void optimize_workflow(t_workflow *workflow);


/*
** ------------------------- DEBUG -------------------------
*/

void	debug_print_stack(t_stack *head, char c);
void    debug_print_next_operations(t_workflow *workflow);
void    debug_print_rotations_costs(t_rotation_costs *costs, int a_nbr, int b_nbr);
void    debug_print_min_rotations_costs(int *cost);
void    debug_print_all_stack_elements(t_stack *stack);

#endif