/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:26:22 by estettle          #+#    #+#             */
/*   Updated: 2025/01/06 15:13:28 by estettle         ###   ########.fr       */
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
	// ft_printf("%d\n\n", index_limit); // debug
	while (i < slabs_a)
	{
		if ((*stack1)->index <= index_limit)
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
		if (tmp->index > slab->index)
			slab = tmp;
		tmp = tmp->next;
	}
	index = slab->index;
	ft_printf("\n\n%d\n", index);
	// then pretty much just push each element index by index, decreasing to end
	// with a sorted stack1
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
