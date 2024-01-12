/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:47:55 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/12 16:56:47 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void  reset_workflow(t_workflow *workflow)
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
}

void execute_workflow(t_workflow *workflow, t_stack **a, t_stack **b) {
    int i;

    ft_printf("Executing workflow...\n");
    for (i = 0; i < workflow->sa; ++i) {
        op_sa(a, 0);
    }
    for (i = 0; i < workflow->sb; ++i) {
        op_sb(b, 0);
    }
    for (i = 0; i < workflow->ss; ++i) {
        op_sa(a, 0);
        op_sb(b, 0);
    }
    for (i = 0; i < workflow->pa; ++i) {
        op_pa(a, b);
    }
    for (i = 0; i < workflow->pb; ++i) {
        op_pb(a, b);
    }
    for (i = 0; i < workflow->ra; ++i) {
        op_ra(a, 0);
    }
    for (i = 0; i < workflow->rb; ++i) {
        op_rb(b, 0);
    }
    for (i = 0; i < workflow->rr; ++i) {
        op_ra(a, 0);
        op_rb(b, 0);
    }
    for (i = 0; i < workflow->rra; ++i) {
        op_rra(a, 0);
    }
    for (i = 0; i < workflow->rrb; ++i) {
        op_rrb(b, 0);
    }
    for (i = 0; i < workflow->rrr; ++i) {
        op_rra(a, 0);
        op_rrb(b, 0);
    }
    reset_workflow(workflow);
}
