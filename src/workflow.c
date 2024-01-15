/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:47:55 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/15 15:46:53 by vitenner         ###   ########.fr       */
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
