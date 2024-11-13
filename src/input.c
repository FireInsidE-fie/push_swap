/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:10:52 by estettle          #+#    #+#             */
/*   Updated: 2024/11/13 15:06:21 by estettle         ###   ########.fr       */
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
 * @param argc The number of elements in argv.
 * @param argv The input from the program taken directly from the main() func.
 * @return A t_slab chained list with each element representing an integer.
 */
t_slab	**parse_input(int argc, char **argv)
{
	int		i;
	t_slab	*slab;
	t_slab	**integers;

	i = 1;
	check_chars(argc, argv);
	integers = malloc(sizeof(t_slab *));
	if (!integers)
		ft_kill(NULL, NULL, -1);
	while (i < argc)
	{
		slab = slab_new(ft_atoi(argv[i]));
		if (!slab)
			ft_kill(integers, NULL, -1);
		slab_add_back(integers, slab);
		while (*argv[i])
		{
			if (*argv[i] == ' ')
			{
				slab = slab_new(ft_atoi(++argv[i]));
				if (!slab)
					ft_kill(integers, NULL, -1);
				slab_add_back(integers, slab);
			}
			argv[i]++;
		}
		i++;
	}
	return (integers);
}
