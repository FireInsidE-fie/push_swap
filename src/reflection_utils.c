/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:46:42 by estettle          #+#    #+#             */
/*   Updated: 2025/01/13 15:00:34 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Time for some theory crafting
 * Imagine if on stack1, I had a tiny stack of unordered elements that I can
 * just
 * get from stack2 and store at the very end of the first stack for future use.
 * It could be called something like cache and I could just fetch values from
 * it. For example, my stack 1 is currently 9 8 7, with 7 at the top. The next
 * number in stack2 is 5, so that won't do. I'll push it to stack1 but rotate it
 * into the "cache" for future use. Great news, next element in stack 2 is 6, so
 * I can directly push it. Now, where is 5 located? Oh right, in the cache! I
 * just have to reverse rotate to get it, and focus on getting the rest of the
 * stack2 in the same manner.
 * The idea would be to start with only a 1 number sized cache, and then maybe
 * try with bigger caches to see if the optimization would be substantial.
*/

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
