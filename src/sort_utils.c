/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:21:23 by estettle          #+#    #+#             */
/*   Updated: 2024/11/19 13:21:38 by estettle         ###   ########.fr       */
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

/**
 * @brief Looks through a list and returns a pointer to the list element that 
 * has the lowest number amongst the elements that don't have an index yet.
 *
 * @param lst A pointer to the first element of the list to look through.
 */
t_slab	*get_min_unindexed(t_slab *lst)
{
	t_slab	*slab;

	if (!lst)
		return (NULL);
	slab = NULL;
	while (!slab && lst)
	{
		if (!lst->index)
			slab = lst;
		lst = lst->next;
	}
	while (lst)
	{
		if (!lst->index && lst->number < slab->number)
			slab = lst;
		lst = lst->next;
	}
	return (slab);
}

void	index_stack(t_slab *lst)
{
	t_slab		*slab;
	uint16_t	i;

	slab = get_min_unindexed(lst);
	i = 0;
	while (slab)
	{
		slab->index = i++;
		slab = get_min_unindexed(lst);
	}
}
