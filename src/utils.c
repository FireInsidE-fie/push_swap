/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:16:48 by estettle          #+#    #+#             */
/*   Updated: 2024/11/14 12:56:41 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Converts a string into its 64 bit integer representation.
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
			sign = -sign;
	while (str[i] >= '0' && str[i] <= '9')
	{
		converted += str[i++] - '0';
		if (str[i] >= '0' && str[i] <= '9')
			converted *= 10;
	}
	return (converted * sign);
}
