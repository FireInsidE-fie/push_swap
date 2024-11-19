/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:21:23 by estettle          #+#    #+#             */
/*   Updated: 2024/11/19 12:49:02 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

uint8_t	slab_count(t_slab *lst)
{
	uint8_t	slab_count;
	
	slab_count = 0;
	while (lst)
	{
		slab_count++;
		lst = lst->next;
	}
	return (slab_count);
}

/**
 * @brief Checks if a stack is sorted in ascending order, the lowest number
 * at the top.
 *
 * @return TRUE if sorted correctly, FALSE otherwise.
*/
int8_t	is_sorted(t_slab *lst)
{
	while (lst && lst->next)
	{
		if (lst->number > (lst->next)->number)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}
