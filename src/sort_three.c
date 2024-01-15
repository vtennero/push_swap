/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:50:26 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/15 16:09:08 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deal_with_last_three(t_stack **a, t_workflow *workflow)
{
	ft_printf("deal_with_last_three\n");
	debug_print_stack(*a, 'a');
	debug_print_stack(*a, 'b');
    if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
        return;

    // Swap first two elements if needed
    if ((*a)->nbr > (*a)->next->nbr)
		op_sa(a, NULL, 0);
        // workflow->sa += 1;

    // Push the smallest element to the end if it's at the front
    // and if the third element is not the smallest
    if ((*a)->nbr < (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
		op_ra(a, NULL, 0);
        // workflow->ra += 1;

    // Swap first two elements again if needed
    if ((*a)->nbr > (*a)->next->nbr)
        // workflow->sa += 1;
		op_sa(a, NULL, 0);

    // Push the smallest element back to the front only if it's not already there
    if ((*a)->nbr > (*a)->next->nbr || (*a)->nbr > (*a)->next->next->nbr)
		op_rra(a, NULL, 0);
        // push_last_to_front(a);
	(void)workflow;
}