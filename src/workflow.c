/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:47:55 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/15 14:58:02 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef void	(*t_operation_func)(t_stack **, t_stack **);

typedef struct s_operation {
	t_operation_func		op;
	t_stack					**arg1;
	t_stack					**arg2;
	int						count;
}	t_operation;

// operations

void	op_ss(t_stack **a, t_stack **b, int j)
{
	op_sa(a, b, j + 1);
	op_sb(a, b, j + 1);
	write(1, "ss\n", 3);
}

void	op_rr(t_stack **a, t_stack **b, int j)
{
	op_ra(a, b, j + 1);
	op_rb(a, b, j + 1);
	write(1, "rr\n", 3);
}

void	op_rrr(t_stack **a, t_stack **b, int j)
{
	op_rra(a, b, j + 1);
	op_rrb(a, b, j + 1);
	write(1, "rrr\n", 4);
}

void	op_ra(t_stack **a, t_stack **b, int j)
{
    t_stack *tmp;

    if (!*a || !(*a)->next)
        return ;
    tmp = *a;                  // Save the current head of the list
    *a = ft_lstlast(*a);       // Move *a to the last element
    (*a)->next = tmp;          // The next of the last element is now the old head
    tmp->prev = *a;            // Update prev of the old head
    *a = tmp->next;            // *a now points to the second element
    (*a)->prev = NULL;         // The new head's prev is NULL
    tmp->next = NULL;          // The old head's next is now NULL
	if (j == 0)
		write(1, "ra\n", 3);
	(void)b;
}

void	op_rb(t_stack **a, t_stack **b, int j)
{
    t_stack *tmp;

	ft_printf("oprb\n");
	debug_print_all_stack_elements(*b);
    if (!*b || !(*b)->next)
        return ;
    tmp = *b;                  // Save the current head of the list
    *b = ft_lstlast(*b);       // Move *b to the last element
    (*b)->next = tmp;          // The next of the last element is now the old head
    tmp->prev = *b;            // Update prev of the old head
    *b = tmp->next;            // *b now points to the second element
    (*b)->prev = NULL;         // The new head's prev is NULL
    tmp->next = NULL;          // The old head's next is now NULL
	if (j == 0)
		write(1, "rb\n", 3);
	(void)a;
}


void	op_sa(t_stack **a, t_stack **b, int j)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return; // No swap needed if the list is empty or has only one element

	t_stack *first = *a;
	t_stack *second = first->next;
	t_stack *third = second->next;

	// Swapping process
	second->prev = first->prev; // In this case, first->prev is NULL
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;

	*a = second; // Update the a of the list
	if (j == 0)
		write(1, "sa\n", 3);
	(void)b;
}

void	op_sb(t_stack **a, t_stack **b, int j)
{
	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return; // No swap needed if the list is empty or has only one element

	t_stack *first = *b;
	t_stack *second = first->next;
	t_stack *third = second->next;

	// Swapping process
	second->prev = first->prev; // In this case, first->prev is NULL
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;

	*b = second; // Update the a of the list
	if (j == 0)
		write(1, "sb\n", 3);
	(void)a;
}

void	op_rra(t_stack **a, t_stack **b, int j)
{
	t_stack *tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = *a;
	(*a)->prev = tmp;
	*a = tmp;
	if (j == 0)
		write(1, "rra\n", 4);
	(void)b;
}

void	op_rrb(t_stack **a, t_stack **b, int j)
{
	t_stack *tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = *b;
	(*b)->prev = tmp;
	*b = tmp;
	if (j == 0)
		write(1, "rrb\n", 4);
	(void)a;
}

void	op_pa(t_stack **a, t_stack **b, int j)
{
    t_stack *tmp;

    if (!*b)
        return ;

    tmp = *b;
    *b = tmp->next;
    if (*b)
        (*b)->prev = NULL;

    tmp->next = *a;
    if (*a)
        (*a)->prev = tmp;
    *a = tmp;
	write(1, "pa\n", 3);
	j += 0;
}

void op_pb(t_stack **a, t_stack **b, int j)
{
    t_stack *tmp;

    if (!*a)
        return;

    tmp = *a;
    *a = tmp->next;
    if (*a)
        (*a)->prev = NULL;
    tmp->next = *b;
    if (*b)
        (*b)->prev = tmp;
    *b = tmp;
    write(1, "pb\n", 3);
	j += 0;
}

// operations end

void	reset_workflow(t_workflow *workflow)
{
	workflow->sa = 0;
	workflow->sb = 0;
	workflow->ss = 0;
	workflow->pa = 0;
	workflow->pb = 0;
	workflow->ra = 0;
	workflow->rb = 0;
	workflow->rr = 0;
	workflow->rra = 0;
	workflow->rrb = 0;
	workflow->rrr = 0;
	workflow->op_cost = -1;
}

void	optimize_s(t_workflow *workflow)
{
	int	min_value;

	if (workflow->sa < workflow->sb)
		min_value = workflow->sa;
	else
		min_value = workflow->sb;
	workflow->ss = min_value;
	workflow->sa -= min_value;
	workflow->sb -= min_value;
}

void	optimize_r(t_workflow *workflow)
{
	int	min_value;

	if (workflow->ra < workflow->rb)
		min_value = workflow->ra;
	else
		min_value = workflow->rb;
	workflow->rr = min_value;
	workflow->ra -= min_value;
	workflow->rb -= min_value;
}

void	optimize_rr(t_workflow *workflow)
{
	int	min_value;

	if (workflow->rra < workflow->rrb)
		min_value = workflow->rra;
	else
		min_value = workflow->rrb;
	workflow->rrr = min_value;
	workflow->rra -= min_value;
	workflow->rrb -= min_value;
}

void	optimize_workflow(t_workflow *workflow)
{
	optimize_s(workflow);
	optimize_r(workflow);
	optimize_rr(workflow);
}

typedef void	(*t_op_func)(t_stack **a, t_stack **b, int j);

void	run_workflow_for_one(t_op_func op, t_stack **a, t_stack **b, int *count)
{
	int	ops;

ft_printf("run_workflow_for_one\n");
	ops = *count;
	if (ops)
	{
		while (ops > 0)
		{
			op(a, b, 0);
			ops--;
		}
	}
}



void	execute_workflow(t_workflow *workflow, t_stack **a, t_stack **b)
{
	debug_print_next_operations(workflow);
	debug_print_all_stack_elements(*a);
	debug_print_all_stack_elements(*b);
	// run_workflow_for_one(op_ss, a, b, &(workflow->ss));
	// run_workflow_for_one(op_sa, a, NULL, &(workflow->sa));
	// run_workflow_for_one(op_sb, b, NULL, &(workflow->sb));

	// run_workflow_for_one(op_rr, a, b, &(workflow->rr));
	// run_workflow_for_one(op_ra, a, NULL, &(workflow->ra));
	// run_workflow_for_one(op_rb, a, NULL, &(workflow->rb));

	// run_workflow_for_one(op_rrr, a, b, &(workflow->rrr));
	// run_workflow_for_one(op_ra, a, NULL, &(workflow->ra));
	// run_workflow_for_one(op_rb, b, NULL, &(workflow->rb));

	// run_workflow_for_one(op_pa, a, b, &(workflow->pa));
	// run_workflow_for_one(op_pb, a, b, &(workflow->pb));

	// run_workflow_for_one(w_op_swap, a, b, &(workflow->sa));
	// run_workflow_for_one(w_op_swap, a, b, &(workflow->sb));
	// run_workflow_for_one(w_op_swap, a, b, &(workflow->ss));
	// run_workflow_for_one(w_op_rotate, a, b, &(workflow->ra));
	// run_workflow_for_one(w_op_rotate, a, b, &(workflow->rb));
	// run_workflow_for_one(w_op_rotate, a, b, &(workflow->rr));
	// run_workflow_for_one(w_op_rev_rotate, a, b, &(workflow->rra));
	// run_workflow_for_one(w_op_rev_rotate, a, b, &(workflow->rrb));
	// run_workflow_for_one(w_op_rev_rotate, a, b, &(workflow->rrr));
	// run_workflow_for_one(w_op_push, a, b, &(workflow->pa));
	run_workflow_for_one(w_op_push, a, b, &(workflow->pb));
	reset_workflow(workflow);
}
