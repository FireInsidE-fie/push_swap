/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:21:23 by estettle          #+#    #+#             */
/*   Updated: 2025/01/06 15:12:51 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	while (slab && lst)
	{
		if (!lst->index && lst->number < slab->number)
			slab = lst;
		lst = lst->next;
	}
	return (slab);
}

/**
 * @brief Looks through a list and returns a pointer to the list element that
 * has the lowest number amongst the elements that don't have a final position
 * yet.
 *
 * @param lst A pointer to the first element of the list to look through.
 */
t_slab	*get_min_funindexed(t_slab *lst)
{
	t_slab	*slab;

	if (!lst)
		return (NULL);
	slab = NULL;
	while (!slab && lst)
	{
		if (!lst->final_position)
			slab = lst;
		lst = lst->next;
	}
	while (slab && lst)
	{
		if (!lst->final_position && lst->number < slab->number)
			slab = lst;
		lst = lst->next;
	}
	return (slab);
}

/**
 * @brief Indexes a linked list of slabs, specifically its "index" elements,
 * in ascending order of the "number" element.
 *
 * @param lst A pointer to the first element of the linked list to index.
 */
void	index_stack(t_slab *lst)
{
	t_slab		*slab;
	t_slab		*tmp;
	int32_t		i;

	tmp = lst;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	slab = get_min_unindexed(lst);
	i = 0;
	while (slab)
	{
		slab->index = i++;
		slab = get_min_unindexed(lst);
	}
}

/**
 * @brief Indexes a linked list of slabs, specifically its "final_position"
 * elements, in ascending order of the "number" element.
 *
 * @param lst A pointer to the first element of the linked list to index.
 */
void	findex_stack(t_slab *lst)
{
	t_slab		*slab;
	t_slab		*tmp;
	int32_t		i;

	tmp = lst;
	while (tmp)
	{
		tmp->final_position = 0;
		tmp = tmp->next;
	}
	slab = get_min_funindexed(lst);
	i = 0;
	while (slab)
	{
		slab->final_position = i++;
		slab = get_min_funindexed(lst);
	}
}
