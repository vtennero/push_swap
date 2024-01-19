/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:27:21 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 16:28:37 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_workflow_zero(int combination, t_workflow *w, t_rot_costs *c)
{
	if (combination == 0)
	{
		w->ra = c->ra;
		w->rb = c->rb;
	}
}

void	set_workflow_one(int combination, t_workflow *w, t_rot_costs *c)
{
	if (combination == 1)
	{
		w->rra = c->rra;
		w->rrb = c->rrb;
	}
}

void	set_workflow_two(int combination, t_workflow *w, t_rot_costs *c)
{
	if (combination == 2)
	{
		w->ra = c->ra;
		w->rrb = c->rrb;
	}
}

void	set_workflow_three(int combination, t_workflow *w, t_rot_costs *c)
{
	if (combination == 3)
	{
		w->rra = c->rra;
		w->rb = c->rb;
	}
}
