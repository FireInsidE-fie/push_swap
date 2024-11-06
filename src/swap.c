/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:02 by estettle          #+#    #+#             */
/*   Updated: 2024/11/06 13:13:13 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_slab **stack1, t_slab **stack2)
{
	t_slab	*tmp;

	(void)stack2;
	tmp = ((*stack1)->next)->next;
	((*stack1)->next)->next = *stack1;
	(*stack1)->next = tmp;
}

void	ft_sb(t_slab **stack1, t_slab **stack2)
{
	t_slab	*tmp;

	(void)stack1;
	tmp = ((*stack2)->next)->next;
	((*stack2)->next)->next = *stack2;
	(*stack2)->next = tmp;
}

void	ft_ss(t_slab **stack1, t_slab **stack2)
{
	ft_sa(stack1, stack2);
	ft_sb(stack1, stack2);
}

