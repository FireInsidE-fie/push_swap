/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:02 by estettle          #+#    #+#             */
/*   Updated: 2024/11/12 17:16:46 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_slab **stack1, t_slab **stack2)
{
	t_slab	*slab;
	t_slab	*tmp;

	if (!stack1 || !(*stack1) || !(*stack1)->next)
		return ;
	(void)stack2;
	tmp = *stack1;
	slab = *stack1;
	*stack1 = tmp->next;
	while (slab->next && (slab->next)->next)
		slab = slab->next;
	slab->next = tmp;
}

void	ft_rb(t_slab **stack1, t_slab **stack2)
{
	t_slab	*slab;
	t_slab	*tmp;

	if (!stack2 || !(*stack2) || !(*stack2)->next)
		return ;
	(void)stack1;
	tmp = *stack2;
	slab = *stack2;
	*stack2 = tmp->next;
	while (slab->next && (slab->next)->next)
		slab = slab->next;
	slab->next = tmp;
}

void	ft_rr(t_slab **stack1, t_slab **stack2)
{
	ft_ra(stack1, stack2);
	ft_rb(stack1, stack2);
}
