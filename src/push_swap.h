/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:32:10 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/10 16:22:46 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"


/*
** ------------------------- STACK MANAGEMENT -------------------------
*/

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack			*ft_lstlast(t_stack *lst);
int				ft_lstsize(t_stack *lst);
t_stack			*create_new_node(long nbr, int index);
void			append_to_list(t_stack **head, long nbr);
void			print_stack(t_stack *head, char c);
void			free_stack(t_stack *head);

/*
** ------------------------- INPUT CHECKS -------------------------
*/
int				parse_args(int argc, char **argv);

/*
** ------------------------- SOLVER -------------------------
*/
void	init_push(t_stack *a, t_stack *b);


/*
** ------------------------- OPERATIONS -------------------------
*/
void	op_ra(t_stack **a, int j);
void	op_rb(t_stack **b, int j);
void	op_rr(t_stack **a, t_stack **b);
void	op_sa(t_stack **head, int j);
void	op_sb(t_stack **head, int j);
void	op_ss(t_stack **a, t_stack **b);
void	op_rra(t_stack **a, int j);
void	op_rrb(t_stack **a, int j);
void	op_pa(t_stack **a, t_stack **b);
void	op_pb(t_stack **a, t_stack **b);



/*
** ------------------------- DEBUG -------------------------
*/

#endif