/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melodies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:03:18 by estettle          #+#    #+#             */
/*   Updated: 2024/12/10 10:31:17 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Algorithm function in case of two elements to sort.
 */
void	ft_alis(t_slab **stack1, t_slab **stack2)
{
	if (!is_sorted(*stack1))
		ft_sa(stack1, stack2, 0);
}

/**
 * @brief Algorithm function in case of three elements to sort.
 */
void	ft_roxy(t_slab **stack1, t_slab **stack2)
{
	if ((*stack1)->number > (*stack1)->next->number
		&& (*stack1)->next->number > (*stack1)->next->next->number)
	{
		ft_ra(stack1, stack2, 0);
		ft_ra(stack1, stack2, 0);
		return ;
	}
	ft_pb(stack1, stack2);
	ft_alis(stack1, stack2);
	ft_pa(stack1, stack2);
	if ((*stack1)->number > (((*stack1)->next)->next)->number)
		ft_ra(stack1, stack2, 0);
	else if ((*stack1)->number > ((*stack1)->next)->number)
		ft_sa(stack1, stack2, 0);
}
