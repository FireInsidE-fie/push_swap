/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:59:23 by estettle          #+#    #+#             */
/*   Updated: 2024/11/22 12:35:54 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int32_t	get_max_bits(t_slab **stack1)
{
	int32_t	size;
	int32_t	max_bits;

	size = slab_count(*stack1);
	max_bits = 0;
	while (size >> max_bits)
		max_bits++;
	return (max_bits);
}

void	ft_radix(t_slab **stack1, t_slab **stack2)
{
	int32_t	size;
	int32_t	max_bits;
	int32_t	i;
	int32_t	j;

	size = slab_count(*stack1);
	max_bits = get_max_bits(stack1);
	i = -1;
	while (++i < max_bits)
	{
		j = 0;
		while (++j <= size)
		{
			if (!(*stack1))
				break ;
			if ((((*stack1)->index >> i) & 1) == 1 && ft_printf("ra\n"))
				ft_ra(stack1, stack2);
			else if (ft_printf("pb\n"))
				ft_pb(stack1, stack2);
		}
		while (*stack2 && ft_printf("pa\n"))
			ft_pa(stack1, stack2);
	}
}
