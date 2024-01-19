/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:55:38 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 16:13:07 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solver(t_stack *a, t_stack *b)
{
	if (a)
	{
		if (ft_lstsize(a) == 2)
			sort_two(&a);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_big(&a, &b);
	}
	return (1);
}

static void	build_stacks_and_solve(int argc, char **argv)
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
			break ;
		}
		i++;
	}
	solver(stack_a, stack_b);
	free_stack(stack_a);
}

int	main(int argc, char **argv)
{
	if (!parse_args(argc, argv))
	{
		if (argc > 1)
			write(2, "Error\n", 6);
		return (0);
	}
	build_stacks_and_solve(argc, argv);
	return (0);
}
