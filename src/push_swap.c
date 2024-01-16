/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:55:38 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/16 14:13:48 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_stack *a, t_stack *b)
{
	t_workflow *workflow;
	
	if (a)
	{
		workflow = init_workflow_struct();
		if (!workflow)
			return (0);
		debug_print_stacks(a, b);
		init_push(&a, &b);
		debug_print_stacks(a, b);
		find_cheapest_number(&a, &b, workflow);
		debug_print_stacks(a, b);
		deal_with_last_three(&a, workflow);
		debug_print_stacks(a, b);
		push_back_to_stack_a(&a, &b, workflow);
		debug_print_stacks(a, b);
		final_fixes(&a);
		debug_print_stacks(a, b);
		free(workflow);
		workflow = NULL;
	}
	return (1);
}

int	main(int argc, char **argv)
{

    t_stack *stack_a;
    t_stack *stack_b;

	// parse args, check for error
	if (!parse_args(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}

	// allocate memory, check for error
	// refactor to stack_a = build_stack_a
	stack_a = NULL;
	stack_b = NULL;
    for (int i = 1; i < argc; i++)
	{
        int nbr = ft_atoi(argv[i]); // Convert string to int
		if (append_to_list(&stack_a, nbr) == NULL)
		{
			free_stack(stack_a);
    		free_stack(stack_b);
			break ;
		}
    }



	// solve
	solver(stack_a, stack_b);


	// free
	// refactor to clear assets
    free_stack(stack_a);
    free_stack(stack_b);

	return(0);
}