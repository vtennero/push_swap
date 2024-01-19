/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:39:37 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 15:18:30 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print_stack(t_stack *head, char c)
{
	t_stack	*current;

	current = head;
	ft_printf("Stack %c\n", c);
	while (current != NULL)
	{
		ft_printf("%d\n", current->nbr);
		current = current->next;
	}
}

void	debug_print_stack_dense(t_stack *head)
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d ", current->nbr);
		current = current->next;
	}
	ft_printf("\n");
}

void	debug_print_workflow(t_workflow *workflow)
{
	ft_printf("[DEBUG] Moving forward, we will carry the\
	 following operations with this number from a %d\n", workflow->next_nbr);
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

void	debug_print_rotations_costs(t_rot_costs *costs, int a_n, int b_n)
{
	ft_printf("[DEBUG] for %d costs->ra = %d\n", a_n, costs->ra);
	ft_printf("[DEBUG] for %d costs->rra = %d\n", a_n, costs->rra);
	ft_printf("[DEBUG] for %d costs->rb = %d\n", b_n, costs->rb);
	ft_printf("[DEBUG] for %d costs->rrb = %d\n", b_n, costs->rrb);
}
