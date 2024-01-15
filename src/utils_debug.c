/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:39:37 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/15 16:24:01 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void debug_print_stack(t_stack *head, char c)
{
    t_stack *current;
	
	current = head;
	ft_printf("Stack %c\n", c);
    while (current != NULL)
	{
        ft_printf("%d\n", current->nbr);
        // ft_printf("%d index %d\n", current->nbr, current->index);
        current = current->next;
    }
}

void    debug_print_next_operations(t_workflow *workflow)
{
	ft_printf("[DEBUG] Moving forward, we will carry the following operations with this number from a %d\n", workflow->next_nbr);
    ft_printf("[DEBUG] workflow->ss = %d\n", workflow->ss);
    ft_printf("[DEBUG] workflow->sa = %d\n", workflow->sa);
    ft_printf("[DEBUG] workflow->sb = %d\n", workflow->sb);

    ft_printf("[DEBUG] workflow->rr = %d\n", workflow->rr);
    ft_printf("[DEBUG] workflow->ra = %d\n", workflow->ra);
    ft_printf("[DEBUG] workflow->rb = %d\n", workflow->rb);

    ft_printf("[DEBUG] workflow->rrr = %d\n", workflow->rrr);
    ft_printf("[DEBUG] workflow->rra = %d\n", workflow->rra);
    ft_printf("[DEBUG] workflow->rrb = %d\n", workflow->rrb);
    ft_printf("[DEBUG] workflow->pa = %d\n", workflow->pa);
    ft_printf("[DEBUG] workflow->pb = %d\n", workflow->pb);
    ft_printf("[DEBUG] workflow->next_nbr = %d\n", workflow->next_nbr);

}

void		debug_print_b_position(int nbr, int pos)
{
	ft_printf("[DEBUG] %d element in stack A should be at pos %d in B\n", nbr, pos);
}

void    debug_print_rotations_costs(t_rotation_costs *costs, int a_nbr, int b_nbr)
{

    ft_printf("[DEBUG] for %d costs->ra = %d\n", a_nbr, costs->ra);
    ft_printf("[DEBUG] for %d costs->rra = %d\n", a_nbr, costs->rra);
    ft_printf("[DEBUG] for %d costs->rb = %d\n", b_nbr, costs->rb);
    ft_printf("[DEBUG] for %d costs->rrb = %d\n", b_nbr, costs->rrb);
}

void    debug_print_min_rotations_costs(int *cost)
{
    ft_printf("[DEBUG] ft_max(costs.ra, costs.rb) = %d\n", cost[0]);
    ft_printf("[DEBUG] ft_max(costs.rra, costs.rrb) = %d\n", cost[1]);
    ft_printf("[DEBUG] costs.ra + costs.rrb = %d\n", cost[2]);
    ft_printf("[DEBUG] costs.rra + costs.rb = %d\n", cost[3]);
}

void    debug_print_all_stack_elements(t_stack *stack)
{
    t_stack *current;
    
    printf("[DEBUG] debug_print_all_stack_elements\n");
    current = stack;
    while (current != NULL)
    {
        printf("[DEBUG] nbr: %ld\n", current->nbr);

        if (current->next != NULL) {
            printf("[DEBUG] next->nbr: %ld\n", current->next->nbr);
        } else {
            printf("[DEBUG] next: NULL\n");
        }

        if (current->prev != NULL) {
            printf("[DEBUG] prev->nbr: %ld\n", current->prev->nbr);
        } else {
            printf("[DEBUG] prev: NULL\n");
        }

        // printf("\n"); // Adds a newline for better readability between elements
        current = current->next;
    }
}