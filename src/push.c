/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:02 by estettle          #+#    #+#             */
/*   Updated: 2024/12/16 12:55:16 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pa(t_slab **stack1, t_slab **stack2)
{
	t_slab	*pushed;
	t_slab	*tmp;

	if (!stack2 || !(*stack2))
		return ;
	ft_printf("pa\n");
	pushed = *stack2;
	tmp = ((*stack2)->next);
	pushed->next = *stack1;
	*stack1 = pushed;
	*stack2 = tmp;
}

void	ft_pb(t_slab **stack1, t_slab **stack2)
{
	t_slab	*pushed;
	t_slab	*tmp;

	if (!stack1 || !(*stack1))
		return ;
	ft_printf("pb\n");
	pushed = *stack1;
	tmp = ((*stack1)->next);
	pushed->next = *stack2;
	*stack2 = pushed;
	*stack1 = tmp;
}
