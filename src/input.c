/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:10:52 by estettle          #+#    #+#             */
/*   Updated: 2024/11/08 11:27:36 by estettle         ###   ########.fr       */
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
 * @param argv The input from the program taken directly from the main() func.
 * @return A t_slab chained list with each element representing an integer.
 */
t_slab	**ft_parse_input(char **argv)
{
	t_slab	**integers;

	while (*argv)
	{
		ft_atoi(*argv); // Need a version of atoi that stops if a space is found
		while (**argv)
		{
			if (**argv == ' ')
				ft_atoi(++(*argv));
			(*argv)++;
		}
	}
	return (integers);
}
