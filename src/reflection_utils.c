/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:46:42 by estettle          #+#    #+#             */
/*   Updated: 2025/01/11 23:30:20 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Checks if the stack has a cache element (an element at its very
 * end that is unsorted).
 *
 * @param stack A pointer to the first element of a stack.
 * @return If a cache exists, return a pointer to the cache
 * slab, otherwise, return NULL.
 */
t_slab	*has_cache(t_slab *stack)
{
	t_slab	*tmp;

	if (!stack || !(stack->next) || !stack->next->next)
		return (NULL);
	tmp = stack;
	while (tmp->next->next)
		tmp = tmp->next;
	if (tmp->number > tmp->next->number)
		return (tmp->next);
	return (NULL);
}
