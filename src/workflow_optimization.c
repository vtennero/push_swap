/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_optimization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:23:12 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 15:10:16 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
