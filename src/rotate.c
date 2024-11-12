/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:02 by estettle          #+#    #+#             */
/*   Updated: 2024/11/12 20:46:54 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_slab **stack1, t_slab **stack2)
{
	t_slab	*first;
	t_slab	*slast;
	t_slab	*last;

	if (!stack1 || !(*stack1) || !(*stack1)->next)
		return ;
	(void)stack2;
	first = *stack1;
	slast = *stack1;
	while (slast->next && (slast->next)->next)
		slast = slast->next;
	last = slast->next;
	last->next = first->next;
	slast->next = first;
	*stack1 = (slast->next)->next;
	first->next = NULL;
}

void	ft_rb(t_slab **stack1, t_slab **stack2)
{
	t_slab	*first;
	t_slab	*slast;

	if (!stack2 || !(*stack2) || !(*stack2)->next)
		return ;
	(void)stack1;
	first = *stack2;
	slast = *stack2;
	while (slast->next && (slast->next)->next)
		slast = slast->next;
	(slast->next)->next = first->next;
	slast->next = first;
	*stack2 = (slast->next)->next;
	first->next = NULL;
}

void	ft_rr(t_slab **stack1, t_slab **stack2)
{
	ft_ra(stack1, stack2);
	ft_rb(stack1, stack2);
}
