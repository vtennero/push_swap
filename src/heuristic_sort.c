/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:11:23 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/16 14:13:09 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_workflow* init_workflow_struct()
{
    t_workflow *new_struct;
    
    new_struct = (t_workflow*)ft_calloc(1, sizeof(t_workflow));
    if (new_struct)
	    new_struct->op_cost = -1;
    return (new_struct);
}

int			calc_rotation_cost(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack != NULL)
    {
        if (stack->nbr == nbr)
            return (i);
        stack = stack->next;
		i++;
    }
    return -1;
}

int			calc_r_rotation_cost(t_stack *stack, int nbr)
{
	t_stack *last;
		
	last = ft_lstlast(stack);
    int i;
	
	i = 1;
    while (last != NULL)
    {
        if (last->nbr == nbr)
            return i;
        last = last->prev;
        i++;
    }
    return -1;
}


int			find_nbr_position_in_b(t_stack *stack, int n)
{
t_stack *current = stack;
    int max = INT_MIN;
    int min = INT_MAX;
    int closest = INT_MIN;

    // Iterate through the stack
    while (current != NULL)
    {
        if (current->nbr > max)
            max = current->nbr;
        if (current->nbr < min)
            min = current->nbr;
        if (current->nbr < n && current->nbr > closest)
            closest = current->nbr;
        current = current->next;
    }
    if (n > max)
        // Case 1: n is the new maximum
        return max;
    else if (n < min)
        // Case 2: n is the new minimum
        return max;
    else
        // Case 3: n is neither new maximum nor minimum
        return closest;
}

int find_minimum(int arr[4], int size) {
    int min;
    int i;
    
    min = arr[0];
    i = 1;
    while (i < size)
    {
        if (arr[i] < min)
            min = arr[i];
        i++;
    }
    return min;
}

// CHATGPT TEST01

void calculate_rotation_costs(t_stack *a, t_stack *b, int nbr, t_rotation_costs *costs)
{
    int b_closest_number;

    costs->ra = calc_rotation_cost(a, nbr);
    costs->rra = calc_r_rotation_cost(a, nbr);
    b_closest_number = find_nbr_position_in_b(b, nbr);
    costs->rb = calc_rotation_cost(b, b_closest_number);
    costs->rrb = calc_r_rotation_cost(b, b_closest_number);
}

// Function for finding the best combination
int find_best_combination(t_rotation_costs costs)
{
    int cost[4];
    
    cost[0] = ft_max(costs.ra, costs.rb);
    cost[1] = ft_max(costs.rra, costs.rrb);
    cost[2] = costs.ra + costs.rrb;
    cost[3] = costs.rra + costs.rb;
    return (find_minimum(cost, 4));
}

int determine_min_cost_combination(t_rotation_costs costs, int minCost)
{
    int combinations[4];
    int i;
    
    combinations[0] = ft_max(costs.ra, costs.rb);
    combinations[1] = ft_max(costs.rra, costs.rrb);
    combinations[2] = costs.ra + costs.rrb;
    combinations[3] = costs.rra + costs.rb;
    i = 0;
    
    while (i < 4)
    {
        if (combinations[i] == minCost)
            return i;
        i++;
    }
    return -1;
}

void update_workflow(t_workflow *workflow, int min_cost, int nbr, t_rotation_costs costs)
{
    int combination;
    
    // ft_printf("update_workflow\n");
    combination = determine_min_cost_combination(costs, min_cost);
    if (workflow->op_cost == -1 || min_cost < workflow->op_cost)
    {
        workflow->op_cost = min_cost;
        workflow->next_nbr = nbr;
        workflow->ra = 0;
        workflow->rb = 0;

        // Use if-else statements instead of switch-case
        if (combination == 0) { // ft_max(ra, rb)
            workflow->ra = costs.ra;
            workflow->rb = costs.rb;
        } else if (combination == 1) { // ft_max(rra, rrb)
            // Update for rra and rrb if necessary
			workflow->rra = costs.rra;
            workflow->rrb = costs.rrb;
        } else if (combination == 2) { // ra + rrb
            workflow->ra = costs.ra;
            workflow->rrb = costs.rrb;
            // Update for rrb if necessary
        } else if (combination == 3) { // rra + rb
            // Update for rra and rb if necessary
			workflow->rra = costs.rra;
            workflow->rb = costs.rb;
        }
        // Add more else-if statements if there are other combinations
    }
}



int calc_min_cost_for_number(t_stack *a, t_stack *b, int nbr, t_workflow *workflow)
{
    t_rotation_costs costs;
    int min_cost;

    calculate_rotation_costs(a, b, nbr, &costs);
    min_cost = find_best_combination(costs);
    update_workflow(workflow, min_cost, nbr, costs);

    return 0;
}

void find_cheapest_number(t_stack **a, t_stack **b, t_workflow *workflow)
{
    t_stack *current;

    current = *a;
    workflow->next_nbr = current->nbr;
    while (ft_lstsize(*a) > 3)
    {
        while (current != NULL)
        {
            calc_min_cost_for_number(*a, *b, current->nbr, workflow);
            current = current->next;
        }
        workflow->pb = 1;
        optimize_workflow(workflow);
        execute_workflow(workflow, a, b);
        current = *a;
    }
    // ft_printf("------------\n");
    // ft_printf("find_cheapest_number\n");
    // debug_print_stack(*a, 'a');
    // debug_print_stack(*b, 'b');
    // ft_printf("------------\n");
}
