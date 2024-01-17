/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:46:38 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/17 15:09:26 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_no_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_arg(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && str[1] != '\0')
		i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atol(str) != ft_atoi(str))
		return (0);
	return (1);
}

int	only_numbers_in_list(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_arg(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(int argc, char **argv)
{
	if (!has_no_duplicates(argc, argv) \
	|| !only_numbers_in_list(argc, argv) || argc < 3)
		return (0);
	return (1);
}
