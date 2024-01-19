/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:39:37 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 15:18:12 by vitenner         ###   ########.fr       */
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

static void	debug_print_stacks_h(void)
{
	ft_printf("-\t-\n");
	ft_printf("A\tB\n");
	ft_printf("-\t-\n");
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
