/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic_sort copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:11:23 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/15 09:48:36 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// struct logic



t_workflow* init_struct() {
    t_workflow *newStruct = (t_workflow*)ft_calloc(1, sizeof(t_workflow));
    if (newStruct == NULL) {
        // Handle memory allocation failure
        perror("Failed to allocate memory for struct");
        exit(EXIT_FAILURE);
    }
	newStruct->op_cost = -1;
    return newStruct;
}


// struct logic end


int		find_b_position(t_stack *b, int nbr)
{
	// ft_printf("find_b_position for %d\n", nbr);
    int index = 0;
    t_stack *current = b;
    while (current != NULL)
    {
        // Compare nbr with the current element's nbr
        if (nbr <= current->nbr)
        {
            // If nbr is less than or equal to the current element, return the current element's index
            return index;
        }

        // Move to the next element in the stack
        current = current->next;
        index++;
    }

    // If nbr is greater than all elements in the stack, return the index of the last element + 1
    return index;
}

void		debug_print_b_position(int nbr, int pos)
{
	ft_printf("[DEBUG] %d element in stack A should be at pos %d in B\n", nbr, pos);
}



int			calc_rotation_cost(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	ft_printf("calc_rotation_cost: for %d\n", nbr);
	while (stack != NULL)
    {
        if (stack->nbr == nbr)
            return (i);
        stack = stack->next;
		i++;
    }
    return -1; // Number not found
}

int nbr_exists(t_stack *head, long target_nbr)
{
	t_stack *current = head;
	while (current != NULL)
	{
		if (current->nbr == target_nbr)
		{
			return 1; // Number found
		}
		current = current->next;
	}
	return 0; // Number not found
}

int			calc_r_rotation_cost(t_stack *stack, int nbr)
{
	ft_printf("calc_r_rotation_cost: for %d\n", nbr);
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
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int			calc_min_cost_for_number2(t_stack *a, t_stack *b, long nbr, t_workflow *workflow)
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int		b_closest_number;

	// ft_printf("calc_min_cost_for_number %d: START\n", nbr);
	// (void)a;
	// calc cost to rotate A
	ra = calc_rotation_cost(a, nbr);
	// calc cost to reverse rotate A
	rra = calc_r_rotation_cost(a, nbr);
	// rb = -1;
	// rrb = -1;
	// find location of nbr inside B
	b_closest_number = find_nbr_position_in_b(b, nbr);
	// ft_printf("calc_min_cost_for_number: nbr %d should be above %d\n", nbr, b_closest_number);
	// calc cost to rotate B to push subsidiary number on top
	// calc cost to reverse rotate B to push subsidiary number on top
	// if (nbr_exists(b, b_closest_number))
	// {
		// ft_printf("calc_min_cost_for_number: nbr found\n");
	rb = calc_rotation_cost(b, b_closest_number);
	rrb = calc_r_rotation_cost(b, b_closest_number);
	// }
	// ft_printf("calc_min_cost_for_number: ra calc_rotation_cost %d is %d\n", nbr,ra);
	// ft_printf("calc_min_cost_for_number: rra calc_r_rotation_cost %d is %d\n", nbr,rra);
	// ft_printf("calc_min_cost_for_number: rb calc_rotation_cost %d is %d\n", b_closest_number,rb);
	// ft_printf("calc_min_cost_for_number: rrb calc_r_rotation_cost %d is %d\n", b_closest_number,rrb);
	// calc minimum cost
	// ft_printf("ra +rb %d\n", ft_max(ra, rb));
	// ft_printf("rra +rrb %d\n", ft_max(rra, rrb));
	// ft_printf("ra +rrb %d\n", ra + rrb);
	// ft_printf("rra +rb %d\n", rra + rb);

	// update/remove
 int cost[] = {ft_max(ra, rb), ft_max(rra, rrb), ra + rrb, rra + rb};

 // Find the index of the minimum cost
    int minCost = findMinimum(cost, 4);

	ft_printf("calc_min_cost_for_number %d: mincost is %d\n", nbr, minCost);
	if (workflow->op_cost == -1 || minCost < workflow->op_cost)
	{
		workflow->op_cost = minCost;
		workflow->next_nbr = nbr;
		// update structure accordingly with # of operations
	}
	// return (ft_min_four(ft_max(ra, rb), ft_max(rra, rrb), ra + rrb, rra + rb));
	return (0);
}

// CHATGPT TEST01

typedef struct s_rotation_costs {
    int ra;
    int rra;
    int rb;
    int rrb;
} t_rotation_costs;

// Function for calculating rotation costs
void calculate_rotation_costs(t_stack *a, t_stack *b, long nbr, t_rotation_costs *costs) {
    costs->ra = calc_rotation_cost(a, nbr);
    costs->rra = calc_r_rotation_cost(a, nbr);
    int b_closest_number = find_nbr_position_in_b(b, nbr);
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
    return (findMinimum(cost, 4));
}

int determine_min_cost_combination(t_rotation_costs costs, int minCost) {
    int combinations[4] = {ft_max(costs.ra, costs.rb), ft_max(costs.rra, costs.rrb), costs.ra + costs.rrb, costs.rra + costs.rb};
    for (int i = 0; i < 4; i++) {
        if (combinations[i] == minCost) {
            return i; // Returns the index of the minimum cost combination
        }
    }
    return -1; // In case of an error or no match
}

void update_workflow(t_workflow *workflow, int minCost, long nbr, t_rotation_costs costs) {
    int combination = determine_min_cost_combination(costs, minCost);
    if (workflow->op_cost == -1 || minCost < workflow->op_cost) {
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

    calculate_rotation_costs(a, b, nbr, &costs);
    int minCost = find_best_combination(costs);
    update_workflow(workflow, minCost, nbr, costs);

    return 0;
}
// CHATGPT TEST01 end

// CHATGPT TEST02

// CHATGPT TEST02 end


void		find_cheapest_number(t_stack *a, t_stack *b)
{
	t_stack *current;
	// int		cheapest_number;
	// int		tmp;
	t_workflow *workflow = init_struct();

	current = a;
	workflow->next_nbr = current->nbr;
	// loop through each element of a
    while (ft_lstsize(a) > 3)
    // while (current != NULL && ft_lstsize(current) > 3)
    {
        ft_printf("find_cheapest_number: lstsize = %d\n", ft_lstsize(a));
		while (current != NULL)
		{
			calc_min_cost_for_number(a, b, current->nbr, workflow);
        	current = current->next;
		}
        ft_printf("find_cheapest_number: Cheapest Number is %d w a cost of %d\n", workflow->next_nbr, workflow->op_cost);
		workflow->pb = 1;
	    debug_print_next_operations(workflow);
	    execute_workflow(workflow, &a, &b);
	    print_stack(a, 'a');
	    print_stack(b, 'b');
    }

	// manually add a push b
	// workflow->pb = 1;
	// execute operations
	// debug_print_next_operations(workflow);
	// execute_workflow(workflow, &a, &b);


	// print to see if it worked


}