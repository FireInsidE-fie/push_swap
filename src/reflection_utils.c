/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:46:42 by estettle          #+#    #+#             */
/*   Updated: 2025/01/13 15:55:38 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Checks if the stack (usually stack1) has a cache element (an element
 * at its very end that is unsorted).
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

/**
 * @brief Checks if a cache element exists. If the element to be pushed to
 * stack1 isn't the right one, pushes and rotates it to effectively put it into
 * the "cache", an element at the bottom of stack1 than can be accessed when the
 * time comes.
 * If a cache exists and consists of the right slab (the index corresponds),
 * reverse rotates it to put it in its place.
 */
void	process_cache(t_slab **stack1, t_slab **stack2, int *index)
{
	if (has_cache(*stack1))
	{
		if (has_cache(*stack1)->final_position == *index)
		{
			ft_rra(stack1, stack2, FALSE);
			(*index)--;
		}
	}
	else if ((*stack2)->final_position != *index)
	{
		ft_pa(stack1, stack2);
		ft_ra(stack1, stack2, FALSE);
	}
}
