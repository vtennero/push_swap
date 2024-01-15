/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:11:23 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/15 16:21:56 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// struct logic

t_workflow* init_workflow_struct()
{
    t_workflow *new_struct;
    
    new_struct = (t_workflow*)ft_calloc(1, sizeof(t_workflow));
    if (new_struct == NULL) {
        // Handle memory allocation failure
        perror("Failed to allocate memory for struct");
        exit(EXIT_FAILURE);
    }
	new_struct->op_cost = -1;
    return (new_struct);
}


// struct logic end


int			calc_rotation_cost(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	// ft_printf("calc_rotation_cost: for %d\n", nbr);
	while (stack != NULL)
    {
        if (stack->nbr == nbr)
            return (i);
        stack = stack->next;
		i++;
    }
	// ft_printf("calc_rotation_cost: %d not found in list\n", nbr);
    return -1; // Number not found
}

int			calc_r_rotation_cost(t_stack *stack, int nbr)
{
	// ft_printf("calc_r_rotation_cost: for %d\n", nbr);
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
	// ft_printf("calc_r_rotation_cost: %d not found in list\n", nbr);
    return -1; // Number not found
}


int			find_nbr_position_in_b(t_stack *stack, long n)
{
t_stack *current = stack;
    long max = LONG_MIN;
    long min = LONG_MAX;
    long closest = LONG_MIN;

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

int			ft_min_four(int a, int b, int c, int d)
{
	int min = a; // Assume a is the minimum initially

    if (b < min && b >= 0) {
        min = b; // Update min if b is smaller
    }
    if (c < min && c >= 0) {
        min = c; // Update min if c is smaller
    }
    if (d < min && d >= 0) {
        min = d; // Update min if d is smaller
    }

    return min;
}

int findMinimum(int arr[], int size) {
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
    // ft_printf("findMinimum: min is %d\n", min);
    return min;
}

// CHATGPT TEST01

// typedef struct s_rotation_costs {
//     int ra;
//     int rra;
//     int rb;
//     int rrb;
// } t_rotation_costs;

// Function for calculating rotation costs
void calculate_rotation_costs(t_stack *a, t_stack *b, long nbr, t_rotation_costs *costs)
{
    int b_closest_number;

    costs->ra = calc_rotation_cost(a, nbr);
    costs->rra = calc_r_rotation_cost(a, nbr);
    b_closest_number = find_nbr_position_in_b(b, nbr);
    costs->rb = calc_rotation_cost(b, b_closest_number);
    costs->rrb = calc_r_rotation_cost(b, b_closest_number);
    // debug_print_rotations_costs(costs, nbr, b_closest_number);
}

// Function for finding the best combination
int find_best_combination(t_rotation_costs costs)
{
    int cost[4];
    
    cost[0] = ft_max(costs.ra, costs.rb);
    cost[1] = ft_max(costs.rra, costs.rrb);
    cost[2] = costs.ra + costs.rrb;
    cost[3] = costs.rra + costs.rb;
    // debug_print_min_rotations_costs(cost);
    return (findMinimum(cost, 4));
}

int determine_min_cost_combination(t_rotation_costs costs, int minCost) {
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
            return i; // Returns the index of the minimum cost combination
        i++;
    }
    return -1; // In case of an error or no match
}

void update_workflow(t_workflow *workflow, int minCost, long nbr, t_rotation_costs costs)
{
    int combination;
    
    // ft_printf("update_workflow\n");
    combination = determine_min_cost_combination(costs, minCost);
    if (workflow->op_cost == -1 || minCost < workflow->op_cost)
    {
        // ft_printf("update_workflow: workflow->op_cost == -1 || minCost < workflow->op_cost\n");
        workflow->op_cost = minCost;
        workflow->next_nbr = nbr;

        // Reset operation counts
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



// Refactored calc_min_cost_for_number function
int calc_min_cost_for_number(t_stack *a, t_stack *b, long nbr, t_workflow *workflow) {
    t_rotation_costs costs;
    int minCost;

    calculate_rotation_costs(a, b, nbr, &costs);
    minCost = find_best_combination(costs);
    update_workflow(workflow, minCost, nbr, costs);

    return 0;
}
// CHATGPT TEST01 end

// CHATGPT TEST02

// CHATGPT TEST02 end


void		find_cheapest_number(t_stack *a, t_stack *b, t_workflow *workflow)
{
	t_stack *current;
	// int		cheapest_number;
	// int		tmp;

	current = a;
	workflow->next_nbr = current->nbr;
	// loop through each element of a
    while (ft_lstsize(a) > 3)
    // while (current != NULL && ft_lstsize(current) > 3)
    {
        // ft_printf("find_cheapest_number: lstsize = %d current->nbr = %d\n", ft_lstsize(a), current->nbr);
		while (current != NULL)
		{
            // ft_printf("find_cheapest_number: current != NULL\n");
			calc_min_cost_for_number(a, b, current->nbr, workflow);
        	current = current->next;
		}
        // ft_printf("find_cheapest_number: Cheapest Number is %d w a cost of %d\n", workflow->next_nbr, workflow->op_cost);
		workflow->pb = 1;
	    optimize_workflow(workflow);
	    execute_workflow(workflow, &a, &b);
	    // debug_print_stack(a, 'a');
	    // debug_print_stack(b, 'b');
        // debug_print_all_stack_elements(b);
        current = a;
        // current = current->next;
    }

	// manually add a push b
	// workflow->pb = 1;
	// execute operations
	// debug_print_next_operations(workflow);
	// execute_workflow(workflow, &a, &b);


	// print to see if it worked


}