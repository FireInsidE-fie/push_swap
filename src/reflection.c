/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:26:22 by estettle          #+#    #+#             */
/*   Updated: 2025/01/07 17:47:07 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/push_swap.h"

static void	split_push(t_slab **stack1, t_slab **stack2)
{
	int	i;
	int	slabs_a;
	int	slice_size;
	int	index_limit;

	index_stack(*stack1);
	i = 0;
	slabs_a = slab_count(*stack1);
	slice_size = slabs_a / 3;
	index_limit = slabs_a - slice_size;
	ft_printf("%d\n\n", index_limit); // debug
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
 * @brief Finds the element with the highest "final_position" in stack 2,
 * brings it to the top of the stack then pushes it onto stack1.
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
	if (counter > slab_count(*stack2))
	{
		while ((*stack2)->final_position)
			ft_rrb(stack1, stack2, FALSE);
	}
	else
	{
		while ((*stack2)->final_position)
			ft_rb(stack1, stack2, FALSE);
	}
	ft_pa(stack1, stack2);
}

static void	sort_back(t_slab **stack1, t_slab **stack2)
{
	t_slab	*slab;
	t_slab	*tmp;
	int		index;

	(void)stack1;
	slab = *stack2;
	tmp = *stack2;
	while (tmp)
	{
		if (tmp->final_position > slab->final_position)
			slab = tmp;
		tmp = tmp->next;
	}
	index = slab->final_position;
	// then pretty much just push each element index by index, decreasing to end
	// with a sorted stack1
	while (index && *stack2)
		push_element(stack1, stack2, index--);
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
	print_stack(stack1); // debug
	print_stack(stack2); // debug
	sort_back(stack1, stack2);
}
