/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:11:23 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/11 15:57:03 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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



int			cost_to_rotate(t_stack *stack, int nbr)
{
	ft_printf("cost_to_rotate: for %d\n", nbr);
}

int			cost_to_reverse_rotate(t_stack *stack, int nbr)
{
	ft_printf("cost_to_reverse_rotate: for %d\n", nbr);

}

int			update_cheapest_number(t_stack *a, t_stack *b)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	ra = cost_to_rotate(a, a->nbr);
	rb = cost_to_rotate(b, b->nbr);
	rra = cost_to_reverse_rotate(a, a->nbr);
	rrb = cost_to_reverse_rotate(b, b->nbr);

	//  MyStruct myStruct = {ra, rb, rra, rrb, 0, 0, 0, 0, 0};

 // Calculate the four possible costs
 int cost[] = {max(ra, rb), max(rra, rrb), ra + rrb, rra + rb};
 int numCosts = sizeof(cost)/sizeof(cost[0]);

 // Find the index of the minimum cost
 int minCostIndex = 0;
 for(int i = 1; i < numCosts; ++i) {
   if(cost[i] < cost[minCostIndex]) {
     minCostIndex = i;
   }
 }
	ft_printf("mincost is %d", minCostIndex);
}

void		find_cheapest_number(t_stack *a, t_stack *b)
{
	t_stack *current;
	int		pos;
	int		cheapest_number;
	
	current = a;
	// loop through each element of a
	cheapest_number = current->nbr;
    while (current != NULL)
    {
		cheapest_number = update_cheapest_number(a, b);
        current = current->next;

		// ft_printf("find_cheapest_number: while (current != NULL)\n");
		// pos = find_b_position(b, current->nbr);
     	// print return
		// debug_print_b_position(current->nbr, pos);
		// Move to the next element in the stack
    }
	ft_printf("Cheapest Number is %d\n", cheapest_number);


}