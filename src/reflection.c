/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:26:22 by estettle          #+#    #+#             */
/*   Updated: 2024/12/16 13:54:56 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	split_push(t_slab **stack1, t_slab **stack2)
{
	int	i;
	int	slice_size;
	int	total_slabs;

	i = 0;
	slice_size = slab_count(*stack1) / 3;
	total_slabs = slab_count(*stack1) + slab_count(*stack2);
	while (i < slice_size)
	{
		if ((*stack1)->index < slice_size * 2)
		{

		}
	}
}

void	ft_reflection(t_slab **stack1, t_slab **stack2)
{
	int	i;

	index_stack(*stack1);
	while (slab_count(*stack1) > 3)
	{
		split_push(stack1, stack2);
	}
}