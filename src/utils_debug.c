/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:39:37 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/16 12:14:41 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	debug_print_stacks_ms(int size_a, int size_b)
{
	if (size_a > size_b)
		return (size_a);
	else
		return (size_b);
}

static void	debug_print_stacks_h(void)
{
	ft_printf("-\t-\n");
	ft_printf("A\tB\n");
	ft_printf("-\t-\n");
}

static void	debug_print_stacks_el(t_stack *a, t_stack *b, int s_a, int s_b)
{
	int	current_index;

	current_index = 0;
	while (current_index < debug_print_stacks_ms(s_a, s_b))
	{
		if (current_index < s_a)
		{
			ft_printf("%d\t", a->nbr);
			a = a->next;
		}
		else
			ft_printf("\t");
		if (current_index < s_b)
		{
			ft_printf("%d\n", b->nbr);
			b = b->next;
		}
		else
			ft_printf("\n");
		current_index++;
	}
}

void	debug_print_stacks(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	debug_print_stacks_h();
	debug_print_stacks_el(a, b, size_a, size_b);
}

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

void	debug_print_next_operations(t_workflow *workflow)
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
/*void	debug_print_b_position(int n, int pos)
{
	ft_printf("[DEBUG] %d element in stack A should be at %d in B\n", n, pos);
}*/

void	debug_print_rotations_costs(t_rotation_costs *costs, int a_n, int b_n)
{
	ft_printf("[DEBUG] for %d costs->ra = %d\n", a_n, costs->ra);
	ft_printf("[DEBUG] for %d costs->rra = %d\n", a_n, costs->rra);
	ft_printf("[DEBUG] for %d costs->rb = %d\n", b_n, costs->rb);
	ft_printf("[DEBUG] for %d costs->rrb = %d\n", b_n, costs->rrb);
}

void	debug_print_min_rotations_costs(int *cost)
{
	ft_printf("[DEBUG] ft_max(costs.ra, costs.rb) = %d\n", cost[0]);
	ft_printf("[DEBUG] ft_max(costs.rra, costs.rrb) = %d\n", cost[1]);
	ft_printf("[DEBUG] costs.ra + costs.rrb = %d\n", cost[2]);
	ft_printf("[DEBUG] costs.rra + costs.rb = %d\n", cost[3]);
}

void	debug_print_all_stack_elements(t_stack *stack)
{
	t_stack	*current;

	ft_printf("[DEBUG] debug_print_all_stack_elements\n");
	current = stack;
	while (current != NULL)
	{
		ft_printf("[DEBUG] nbr: %d\n", current->nbr);
		if (current->next != NULL)
			ft_printf("[DEBUG] next->nbr: %d\n", current->next->nbr);
		else
			ft_printf("[DEBUG] next: NULL\n");
		if (current->prev != NULL)
			ft_printf("[DEBUG] prev->nbr: %d\n", current->prev->nbr);
		else
			ft_printf("[DEBUG] prev: NULL\n");
		current = current->next;
	}
}
