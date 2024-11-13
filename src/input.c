/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:10:52 by estettle          #+#    #+#             */
/*   Updated: 2024/11/12 17:55:52 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

// Function to check for non-numbers
//
// Function to check for dupes
//
// Function to check for number size
//
// Driver function to check the input, calling the other three

void	check_chars(int argc, char **argv)
{
	int	i;
	int	j;
	int	is_empty;
	int	invalid_char;
	
	i = 1;
	is_empty = 0;
	invalid_char = 0;
	while (i < argc)
	{
		is_empty = 1;
		j = 0;
		while (argv[i][j])
		{
			if (is_empty && ft_isprint(argv[i][j]))
				is_empty = 0;
			if (argv[i][j] != ' ' && argv[i][j] != '-' &&
					!ft_isdigit(argv[i][j]))
				invalid_char = 1;
			j++;
		}
		if (is_empty || invalid_char)
			ft_kill(NULL, NULL, -1);
		i++;
	}
}

/**
 * @brief Takes the raw input from push swap and parses it into a chained list
 * of integers.
 *
 * @details The idea is to parse both strings containing a single int and ones
 * containing multiple (think the input for the program could be
 * `./push_swap 1 2 "3" "4 5"` and so forth).
 *
 * @param argc The number of elements in argv.
 * @param argv The input from the program taken directly from the main() func.
 * @return A t_slab chained list with each element representing an integer.
 */
t_slab	**parse_input(int argc, char **argv)
{
	int		i;
	t_slab	**integers;

	i = 1;
	check_chars(argc, argv);
	integers = malloc(sizeof(t_slab *));
	while (i < argc)
	{
		slab_add_back(integers, slab_new(ft_atoi(argv[i])));
		while (*argv[i])
		{
			if (*argv[i] == ' ')
				slab_add_back(integers, slab_new(ft_atoi(++argv[i])));
			argv[i]++;
		}
		i++;
	}
	return (integers);
}
