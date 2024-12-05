/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melodies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:03:18 by estettle          #+#    #+#             */
/*   Updated: 2024/12/02 12:46:32 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Algorithm function in case of two elements to sort.
 */
void	ft_alis(t_slab **stack1, t_slab **stack2)
{
	if (!is_sorted(*stack1))
	{
		ft_printf("sa\n");
		ft_sa(stack1, stack2);
	}
}

/**
 * @brief Algorithm function in case of three elements to sort.
 */
void	ft_roxy(t_slab **stack1, t_slab **stack2)
{
	if ((*stack1)->number > (*stack1)->next->number &&
		(*stack1)->next->number > (*stack1)->next->next->number)
	{
		ft_printf("ra\nra\n");
		ft_ra(stack1, stack2);
		ft_ra(stack1, stack2);
		return ;
	}
	ft_printf("pb\n");
	ft_pb(stack1, stack2);
	ft_alis(stack1, stack2);
	ft_printf("pa\n");
	ft_pa(stack1, stack2);
	if ((*stack1)->number > (((*stack1)->next)->next)->number)
	{
		ft_printf("ra\n");
		ft_ra(stack1, stack2);
	}
	else if ((*stack1)->number > ((*stack1)->next)->number)
	{
		ft_printf("sa\n");
		ft_sa(stack1, stack2);
	}
}
