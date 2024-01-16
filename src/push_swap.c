/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:55:38 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/16 11:11:51 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver(t_stack *a, t_stack *b)
{

	t_workflow *workflow = init_workflow_struct();

	init_push(&a, &b);
	// ft_printf("solver: init push done\n");
	debug_print_stack(a, 'a');
	debug_print_stack(b, 'b');
	find_cheapest_number(a, b, workflow);
	debug_print_stack(a, 'a');
	debug_print_stack(b, 'b');
	deal_with_last_three(&a, workflow);
	debug_print_stack(a, 'a');
	debug_print_stack(b, 'b');
	// push_back_to_stack_a();
	// final_fixes();
	free(workflow);
	workflow = NULL;
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
	stack_a = NULL;
	stack_b = NULL;
    for (int i = 1; i < argc; i++)
	{
        long nbr = ft_atol(argv[i]); // Convert string to long
        append_to_list(&stack_a, nbr);
    }

    // debug_print_stack(stack_a, 'a');
    // debug_print_stack(stack_b, 'b');


	// solve
	solver(stack_a, stack_b);


	// free
    free_stack(stack_a);
    free_stack(stack_b);
	stack_a = NULL;
	stack_b = NULL;

	return(0);
}