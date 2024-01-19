/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:47:55 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 16:27:30 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef void	(*t_op_func)(t_stack **a, t_stack **b, int j);

t_workflow	*init_workflow_struct(void)
{
	t_workflow	*new_struct;

	new_struct = (t_workflow *)ft_calloc(1, sizeof(t_workflow));
	if (new_struct)
		new_struct->op_cost = -1;
	return (new_struct);
}

void	update_workflow(t_workflow *w, int m_cost, int nbr, t_rot_costs *c)
{
	int	combination;

	combination = determine_min_cost_combination(c, m_cost);
	if (w->op_cost == -1 || m_cost < w->op_cost)
	{
		reset_workflow(w);
		w->op_cost = m_cost;
		w->next_nbr = nbr;
		set_workflow_zero(combination, w, c);
		set_workflow_one(combination, w, c);
		set_workflow_two(combination, w, c);
		set_workflow_three(combination, w, c);
	}
}

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

void	run_workflow_for_one(t_op_func op, t_stack **a, t_stack **b, int *count)
{
	int	ops;

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
	run_workflow_for_one(op_ss, a, b, &(workflow->ss));
	run_workflow_for_one(op_sa, a, b, &(workflow->sa));
	run_workflow_for_one(op_sb, a, b, &(workflow->sb));
	run_workflow_for_one(op_rr, a, b, &(workflow->rr));
	run_workflow_for_one(op_ra, a, b, &(workflow->ra));
	run_workflow_for_one(op_rb, a, b, &(workflow->rb));
	run_workflow_for_one(op_rrr, a, b, &(workflow->rrr));
	run_workflow_for_one(op_rra, a, b, &(workflow->rra));
	run_workflow_for_one(op_rrb, b, b, &(workflow->rrb));
	run_workflow_for_one(op_pa, a, b, &(workflow->pa));
	run_workflow_for_one(op_pb, a, b, &(workflow->pb));
	reset_workflow(workflow);
}
