/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:26:22 by estettle          #+#    #+#             */
/*   Updated: 2024/12/19 14:55:53 by estettle         ###   ########.fr       */
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

	clear_indexes(*stack1);
	index_stack(*stack1);
	i = 0;
	slabs_a = slab_count(*stack1);
	slice_size = slab_count(*stack1) / 3;
	index_limit = slabs_a - slice_size;
	// ft_printf("%d\n\n", index_limit); // debug
	while (i < slabs_a)
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

void	ft_reflection(t_slab **stack1, t_slab **stack2)
{
	while (slab_count(*stack1) > 3)
	{
		split_push(stack1, stack2);
		print_stack(stack1);
		print_stack(stack2);
	}
	ft_roxy(stack1, stack2);
	print_stack(stack1);
	clear_indexes(*stack2);
	index_stack(*stack2);
	print_stack(stack2);
}