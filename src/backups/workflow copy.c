/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:47:55 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/15 11:28:30 by vitenner         ###   ########.fr       */
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
    workflow->op_cost = -1;
}

void    optimize_s(t_workflow *workflow)
{
    int min_value;

    // Determine the minimum of sa and sb
    if (workflow->sa< workflow->sb)
    {
        min_value = workflow->sa;
    } else {
        min_value = workflow->sb;
    }

    // Assign the minimum value to ss
    workflow->ss = min_value;

    // Subtract the minimum value from both sa and sb
    workflow->sa-= min_value;
    workflow->sb -= min_value;
}

void    optimize_r(t_workflow *workflow)
{
    int min_value;

    // Determine the minimum of ra and rb
    if (workflow->ra< workflow->rb)
    {
        min_value = workflow->ra;
    } else {
        min_value = workflow->rb;
    }

    // Assign the minimum value to ss
    workflow->rr = min_value;

    // Subtract the minimum value from both ra and rb
    workflow->ra-= min_value;
    workflow->rb -= min_value;
}

void    optimize_rr(t_workflow *workflow)
{
    int min_value;

    // Determine the minimum of rra and rrb
    if (workflow->rra< workflow->rrb)
    {
        min_value = workflow->rra;
    } else {
        min_value = workflow->rrb;
    }

    // Assign the minimum value to ss
    workflow->rrr = min_value;

    // Subtract the minimum value from both rra and rrb
    workflow->rra-= min_value;
    workflow->rrb -= min_value;
}

void optimize_workflow(t_workflow *workflow)
{
    optimize_s(workflow);
    optimize_r(workflow);
    optimize_rr(workflow);
}

// void execute_workflow(t_workflow *workflow, t_stack **a, t_stack **b) {
//     int i;

//     for (i = 0; i < workflow->sa; ++i) {
//         op_sa(a, 0);
//     }
//     for (i = 0; i < workflow->sb; ++i) {
//         op_sb(b, 0);
//     }
//     for (i = 0; i < workflow->ss; ++i) {
//         op_ss(a, b);
//     }
//     for (i = 0; i < workflow->ra; ++i) {
//         op_ra(a, 0);
//     }
//     for (i = 0; i < workflow->rb; ++i) {
//         op_rb(b, 0);
//     }
//     for (i = 0; i < workflow->rr; ++i) {
//         op_rr(a, b);
//     }
//     for (i = 0; i < workflow->rra; ++i) {
//         op_rra(a, 0);
//     }
//     for (i = 0; i < workflow->rrb; ++i) {
//         op_rrb(b, 0);
//     }
//     for (i = 0; i < workflow->rrr; ++i) {
//         op_rrr(a, b);
//     }
//     for (i = 0; i < workflow->pa; ++i) {
//         op_pa(a, b);
//     }
//     for (i = 0; i < workflow->pb; ++i) {
//         op_pb(a, b);
//     }
//     reset_workflow(workflow);
// }


typedef void (*operation_func)(t_stack **, t_stack **);

// Define the operation struct
typedef struct {
    operation_func op;
    t_stack **arg1;
    t_stack **arg2;
    int count;
} operation;

void execute_workflow(t_workflow *workflow, t_stack **a, t_stack **b)
{
    operation operations[] = {
        {op_sa, a, 0, workflow->sa},  // op_sa expects an int as the second argument, using 0
        {op_sb, b, 0, workflow->sb},  // Similar to op_sa
        {op_ss, a, b, workflow->ss},
        {op_ra, a, 0, workflow->ra},  // Similar to op_sa
        {op_rb, b, 0, workflow->rb},  // Similar to op_sa
        {op_rr, a, b, workflow->rr},
        {op_rra, a, 0, workflow->rra},  // Similar to op_sa
        {op_rrb, b, 0, workflow->rrb},  // Similar to op_sa
        {op_rrr, a, b, workflow->rrr},
        {op_pa, a, b, workflow->pa},
        {op_pb, a, b, workflow->pb}
    };

    int num_operations = sizeof(operations) / sizeof(operation);
    int i;

    // Execute the operations
    for (i = 0; i < num_operations; ++i) {
        for (int j = 0; j < operations[i].count; ++j) {
            operations[i].op(operations[i].arg1, operations[i].arg2);
        }
    }
    reset_workflow(workflow);
}


