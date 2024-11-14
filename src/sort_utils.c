/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:21:23 by estettle          #+#    #+#             */
/*   Updated: 2024/11/14 16:35:45 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Checks a stack and returns 1 if it is sorted in ascending order.
 *
 * @return 1 if sorted correctly, 0 otherwise.
*/
short	is_sorted(t_slab *lst)
{
	while (lst && lst->next)
	{
		if (lst->number < (lst->next)->number)
			return (0);
		lst = lst->next;
	}
	return (1);
}