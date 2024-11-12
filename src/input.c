/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:10:52 by estettle          #+#    #+#             */
/*   Updated: 2024/11/12 16:51:31 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Takes the raw input from push swap and parses it into a chained list
 * of integers.
 *
 * The idea is to parse both strings containing a single int and ones containing
 * multiple (think the input for the program could be ./push_swap 1 2 "3" "4 5"
 * and so forth).
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
	integers = malloc(sizeof(t_slab *));
	while (i < argc)
	{
		slab_add_back(integers, slab_new(ft_atoi(argv[i])));
		while (*(argv[i]))
		{
			if (*(argv[i]) == ' ')
				slab_add_back(integers, slab_new(ft_atoi(++argv[i])));
			argv[i]++;
		}
		i++;
	}
	return (integers);
}
