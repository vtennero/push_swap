/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:55:38 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/16 15:57:19 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solver(t_stack *a, t_stack *b)
{
	t_workflow	*workflow;
	int			stack_size;

	if (a)
	{
		stack_size = ft_lstsize(a);
		if (stack_size == 2)
			sort_two(&a);
		else if (stack_size == 3)
			sort_three(&a);
		else
		{
			workflow = init_workflow_struct();
			if (!workflow)
				return (0);
			debug_print_stacks(a, b);
			init_push(&a, &b);
			debug_print_stacks(a, b);
			find_cheapest_number(&a, &b, workflow);
			debug_print_stacks(a, b);
			sort_three(&a);
			debug_print_stacks(a, b);
			push_back_to_stack_a(&a, &b);
			debug_print_stacks(a, b);
			free(workflow);
			workflow = NULL;
		}
		debug_print_stacks(a, b);
	}
	return (1);
}

static void	run_program(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		if (append_to_list(&stack_a, ft_atoi(argv[i])) == NULL)
		{
			free_stack(stack_a);
			free_stack(stack_b);
			break ;
		}
		i++;
	}
	solver(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	if (!parse_args(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	run_program(argc, argv);
	return (0);
}
