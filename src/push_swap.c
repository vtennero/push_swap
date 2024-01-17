/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:55:38 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/17 15:53:22 by vitenner         ###   ########.fr       */
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
			// debug_print_stacks(a, b);
			init_push(&a, &b);
			// ft_printf("init_push DONE\n");
			// ft_printf("------\n");
			// debug_print_stacks(a, b);
			find_cheapest_number(&a, &b, workflow);
			// ft_printf("find_cheapest_number DONE\n");
			// ft_printf("------\n");
			// debug_print_stacks(a, b);
			sort_three(&a);
			// ft_printf("sort_three DONE\n");
			// ft_printf("------\n");
			// debug_print_stacks(a, b);
			push_back_to_stack_a(&a, &b);
			// ft_printf("push_back_to_stack_a DONE\n");
			// ft_printf("------\n");
			// debug_print_stacks(a, b);
			final_fixes(&a);
			// ft_printf("final_fixes DONE\n");
			// ft_printf("------\n");
			free(workflow);
			workflow = NULL;
		}
		// debug_print_stack_dense(a);
		// debug_print_stacks(a, b);
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
		write(2, "Error\n", 6);
		return (0);
	}
	run_program(argc, argv);
	return (0);
}
