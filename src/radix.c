/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:59:23 by estettle          #+#    #+#             */
/*   Updated: 2024/11/19 16:17:24 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_radix(t_slab **stack1, t_slab **stack2)
{
	uint16_t	size;
	uint16_t	max_num;
	uint16_t	max_bits;
	uint16_t	i;

	size = slab_count(*stack1);
	max_num = size - 1;
	max_bits = 0;
	i = 0;
	while (max_num >> max_bits)
		max_bits++;
	while (++i < max_bits)
	{
		while (size--)
		{
			if ((((*stack1)->number >> i)&1) == 1)
			{
				ft_printf("ra\n");
				ft_ra(stack1, stack2);
			}
			else
			{
				ft_printf("pb\n");
				ft_pb(stack1, stack2);
			}
		}
	}
	while (*stack2)
	{
		ft_printf("pa\n");
		ft_pa(stack1, stack2);
	}
}
