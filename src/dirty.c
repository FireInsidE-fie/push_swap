/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:14 by estettle          #+#    #+#             */
/*   Updated: 2024/11/15 13:33:52 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/
void	ft_dirty(t_slab **stack1, t_slab **stack2)
{
	while (*stack1)
	{
		if (!(*stack2) || (*stack1)->number > (*stack2)->number)
		{
			ft_printf("pb\n");
			ft_pb(stack1, stack2);
		}
		else
		{
			ft_printf("pa\nsa\n");
			ft_pa(stack1, stack2);
			ft_sa(stack1, stack2);
			while (*stack2 && (*stack1)->number < (*stack2)->number)
			{
				ft_printf("pa\nsa\n");
				ft_pa(stack1, stack2);
				ft_sa(stack1, stack2);
			}
		}
	}
	while (*stack2)
	{
		ft_printf("pa\n");
		ft_pa(stack1, stack2);
	}
}
