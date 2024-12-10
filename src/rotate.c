/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:02 by estettle          #+#    #+#             */
/*   Updated: 2024/12/10 10:23:48 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_slab **stack1, t_slab **stack2, int silenced)
{
	t_slab	*first;
	t_slab	*last;

	if (!stack1 || !(*stack1) || !(*stack1)->next)
		return ;
	if (!silenced)
		ft_printf("ra\n");
	(void)stack2;
	first = *stack1;
	last = *stack1;
	while (last->next)
		last = last->next;
	*stack1 = first->next;
	last->next = first;
	first->next = NULL;
}

void	ft_rb(t_slab **stack1, t_slab **stack2, int silenced)
{
	t_slab	*first;
	t_slab	*last;

	if (!stack2 || !(*stack2) || !(*stack2)->next)
		return ;
	if (!silenced)
		ft_printf("rb\n");
	(void)stack1;
	first = *stack2;
	last = *stack2;
	while (last->next)
		last = last->next;
	*stack1 = first->next;
	last->next = first;
	first->next = NULL;
}

void	ft_rr(t_slab **stack1, t_slab **stack2)
{
	ft_printf("rr\n");
	ft_ra(stack1, stack2, 1);
	ft_rb(stack1, stack2, 1);
}
