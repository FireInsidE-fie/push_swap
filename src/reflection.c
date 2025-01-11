/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:26:22 by estettle          #+#    #+#             */
/*   Updated: 2025/01/11 14:48:55 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/push_swap.h"

#define SLICE_COUNT 2

static void	split_push(t_slab **stack1, t_slab **stack2)
{
	int	i;
	int	slabs_a;
	int	slice_size;
	int	index_limit;

	index_stack(*stack1);
	i = 0;
	slabs_a = slab_count(*stack1);
	slice_size = slabs_a / SLICE_COUNT;
	index_limit = slabs_a - slice_size;
	// ft_printf("%d\n\n", index_limit); // debug
	while (slab_count(*stack1) > 3 && i < slabs_a)
	{
		if ((*stack1)->index < index_limit)
		{
			ft_pb(stack1, stack2);
			if ((*stack2)->index > slice_size)
				ft_rb(stack1, stack2, FALSE);
			i++;
		}
		else
			ft_ra(stack1, stack2, FALSE);
		i++;
	}
}

/* Time for some theory crafting
 * Imagine if on stack1, I had a tiny stack of unordered elements that I can just
 * get from stack2 and store at the very end of the first stack for future use.
 * It could be called something like cache and I could just fetch values from it.
 * For example, my stack 1 is currently 9 8 7, with 7 at the top. The next number
 * in stack2 is 5, so that won't do. I'll push it to stack1 but rotate it into
 * the "cache" for future use. Great news, next element in stack 2 is 6, so I can
 * directly push it. Now, where is 5 located? Oh right, in the cache! I just have
 * to reverse rotate to get it, and focus on getting the rest of the stack2 in the
 * same manner.
 * The idea would be to start with only a 1 number sized cache, and then maybe
 * try with bigger caches to see if the optimization would be substantial.
*/

static void	cache_slab(t_slab **stack1, t_slab **stack2)
{
	t_slab	*tmp;

	tmp = *stack1;
	while ((tmp->next)->next)
		tmp = tmp->next;
}

/**
 * @brief Finds the element with the final_position int set to index in stack2,
 * brings it to the top of the stack then pushes it onto stack1.
 */
static void	push_element(t_slab **stack1, t_slab **stack2, int32_t index)
{
	t_slab	*tmp;
	int		counter;

	counter = 0;
	tmp = *stack2;
    // print_stack(stack1); // debug
    // print_stack(stack2); // debug
	while (tmp->final_position != index)
	{
		tmp = tmp->next;
		counter++;
	}
	if (counter > slab_count(*stack2) / 2)
		while ((*stack2)->final_position != index)
			ft_rrb(stack1, stack2, FALSE);
	else
		while ((*stack2)->final_position != index)
			ft_rb(stack1, stack2, FALSE);
	ft_pa(stack1, stack2);
}

static void	sort_back(t_slab **stack1, t_slab **stack2)
{
	t_slab	*slab;
	t_slab	*tmp;
	int		index;

	slab = *stack2;
	tmp = *stack2;
	while (tmp)
	{
		if (tmp->final_position > slab->final_position)
			slab = tmp;
		tmp = tmp->next;
	}
	index = slab->final_position;
	while (index && *stack2)
	{
		tmp = *stack2;
		while (tmp)
		{
			if (tmp->final_position == index)
				push_element(stack1, stack2, index);
			tmp = tmp->next;
		}
		index--;
	}
}

void	ft_reflection(t_slab **stack1, t_slab **stack2)
{
	findex_stack(*stack1);
	while (slab_count(*stack1) > 3)
	{
		split_push(stack1, stack2);
		//print_stack(stack1); // debug
		//print_stack(stack2); // debug
	}
	ft_roxy(stack1, stack2);
	// print_stack(stack1); // debug
	// print_stack(stack2); // debug
	sort_back(stack1, stack2);
	// print_stack(stack1); // debug
	// print_stack(stack2); // debug
}
