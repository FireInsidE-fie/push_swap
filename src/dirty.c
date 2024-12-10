/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:14 by estettle          #+#    #+#             */
/*   Updated: 2024/12/10 10:24:12 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/
void	ft_dirty(t_slab **stack1, t_slab **stack2)
{
	while (*stack1)
	{
		if (!(*stack2) || (*stack1)->number > (*stack2)->number)
			ft_pb(stack1, stack2);
		else
		{
			ft_pa(stack1, stack2);
			ft_sa(stack1, stack2, 0);
			while (*stack2 && (*stack1)->number < (*stack2)->number)
			{
				ft_pa(stack1, stack2);
				ft_sa(stack1, stack2, 0);
			}
		}
	}
	while (*stack2)
		ft_pa(stack1, stack2);
}
