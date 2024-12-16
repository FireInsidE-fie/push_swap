/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:26:22 by estettle          #+#    #+#             */
/*   Updated: 2024/12/16 11:32:56 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/push_swap.h"

void	ft_merge(t_slab **stack1, t_slab **stack2)
{
	int	i;
	while (slab_count(*stack1) > slab_count(*stack2))
		ft_pb(stack1, stack2);
	// TODO: need a condition in case the number of slabs is uneven
	i = slab_count(*stack1);
	while (i-- && (!is_sorted(*stack1) || !is_sorted(*stack2)))
	{
		if ((*stack1)->number > ((*stack1)->next)->number
			&& (*stack2)->number > ((*stack2)->next)->number)
			ft_ss(stack1, stack2);
		else if ((*stack1)->number > (*stack1)->next->number)
			ft_sa(stack1, stack2, 0);
		else if ((*stack2)->number > (*stack2)->next->number)
			ft_sb(stack1, stack2, 0);
		ft_rr(stack1, stack2);
		// getchar(); // debug
	}
	ft_printf("%d\t%d\n", is_sorted(*stack1), is_sorted(*stack2));
}