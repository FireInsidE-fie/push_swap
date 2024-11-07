/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:02 by estettle          #+#    #+#             */
/*   Updated: 2024/11/06 13:13:02 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pa(t_slab **stack1, t_slab **stack2)
{
	t_slab	**tmp;

	if (!stack2 || !(*stack2))
		return ;
	tmp = &((*stack2)->next);
	(*stack2)->next = *stack1;
	stack2 = tmp;
}

void	ft_pb(t_slab **stack1, t_slab **stack2)
{
	t_slab	**tmp;

	if (!stack1 || !(*stack1))
		return ;
	tmp = &((*stack1)->next);
	(*stack1)->next = *stack2;
	stack1 = tmp;
}
