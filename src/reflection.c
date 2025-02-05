/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:26:22 by estettle          #+#    #+#             */
/*   Updated: 2025/02/05 11:04:22 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/push_swap.h"

#ifndef SLICE_COUNT
# define SLICE_COUNT	3
#endif

/**
 * @brief Splits the stack1 into SLICE_COUNT slices (according to the slabs'
 * indexes) and pushes all slabs except the ones contained in the very last
 * slice to stack2.
 */
static void	split_push(t_slab **stack1, t_slab **stack2)
{
	int	i;
	int	slabs_a;
	int	slice_size;
	int	index_limit;

	index_stack(*stack1);
	i = 0;
	slabs_a = slab_count(*stack1);
	slice_size = slabs_a / SLICE_COUNT + 1;
	index_limit = slabs_a - slice_size;
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

/**
 * @brief Finds the slab with the final_position int set to the index argument
 * in stack2, brings it to the top of the stack then pushes it onto stack1.
 */
static void	push_element(t_slab **stack1, t_slab **stack2, int32_t index)
{
	t_slab	*tmp;
	int		counter;

	counter = 0;
	tmp = *stack2;
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

/**
 * @brief Push back all stack2 elements, using a cache element and performing
 * the final sort.
 */
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
	while (index > 0)
	{
		process_cache(stack1, stack2, &index);
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

/**
 * @brief This algorithm is pretty scuffed, but the idea was to split slabs in
 * multiple slices that could be sorted progressively, first with a semi-sorted
 * push to stack2 until three elements are left (then call the 3 element algo),
 * before finishing off with a final push back to stack1 to end up with a sorted
 * result.
 *
 * @details This algorithm definitely has more potential than is shown here, I
 * think I will eventually come back to it when I feel better prepared to tackle
 * those sorting algorithms.
 */
void	ft_reflection(t_slab **stack1, t_slab **stack2)
{
	findex_stack(*stack1);
	while (slab_count(*stack1) > 3)
		split_push(stack1, stack2);
	ft_roxy(stack1, stack2);
	sort_back(stack1, stack2);
}
