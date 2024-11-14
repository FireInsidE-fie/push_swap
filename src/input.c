/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:10:52 by estettle          #+#    #+#             */
/*   Updated: 2024/11/14 10:40:22 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"
#include <stdint.h>

// Function to check for dupes
//
// Function to check for number size
//
// Driver function to check the input, calling the other three

/**
 * @brief Checks all arguments inputted to the program for invalid characters.
 *
 * @details Specifically checks for digits, minus characters and spaces (in
 * the case multiple integers are contained in the same argument). Everything
 * else causes the program to ft_kill immediately.
 *
 * @see ft_kill()
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The arguments passed to the program.
 */
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
 * @note Malloc checks for slab_new() are performed by slab_add_back() ; to be
 * extremely clear : I hate this with all of my heart, but this is the best way
 * I found to do things and not pass over the 25 lines limit. Sorry future me,
 * hopefully you'll be able to find a better solution.
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
	if (!integers)
		ft_kill(NULL, NULL, -1);
	*integers = NULL;
	while (i < argc)
	{
		slab_add_back(integers, slab_new(ft_atol(argv[i])));
		while (*argv[i])
		{
			if (*argv[i] == ' ')
				slab_add_back(integers, slab_new(ft_atol(++argv[i])));
			argv[i]++;
		}
		i++;
	}
	return (integers);
}
