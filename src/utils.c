/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:16:48 by estettle          #+#    #+#             */
/*   Updated: 2024/12/13 14:33:02 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Converts a number as a string into its 64-bit integer representation.
 * This function accepts any number of white space (isspace(3)) as a suffix,
 * as well as one minus (-) or plus (-) sign.
 *
 * @param str The string to convert.
 * @return The converted string.
 */
int64_t	ft_atol(const char *str)
{
	int8_t			i;
	int8_t			sign;
	int64_t			converted;

	i = 0;
	sign = 1;
	converted = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = (int8_t)(-sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		converted += str[i++] - '0';
		if (str[i] >= '0' && str[i] <= '9')
			converted *= 10;
	}
	return (converted * sign);
}

/**
 * @brief This function goes through a slab stack and returns the highest number
 * contained within the number values.
 *
 * @param stack A pointer to the first element of a stack to go through.
 * @return The max number contained within the stack.
 */
int64_t	slab_max(t_slab **stack)
{
	int64_t	i;
	t_slab	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->number > i)
			i = tmp->number;
		tmp = tmp->next;
	}
	return (i);
}
