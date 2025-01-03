/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:02 by estettle          #+#    #+#             */
/*   Updated: 2024/12/17 10:05:32 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_slab **stack1, t_slab **stack2, int silenced)
{
	t_slab	*first;
	t_slab	*third;

	if (!stack1 || !(*stack1) || !((*stack1)->next))
		return ;
	if (!silenced)
		ft_printf("sa\n");
	(void)stack2;
	first = *stack1;
	third = ((*stack1)->next)->next;
	((*stack1)->next)->next = first;
	*stack1 = first->next;
	first->next = third;
}

void	ft_sb(t_slab **stack1, t_slab **stack2, int silenced)
{
	t_slab	*first;
	t_slab	*third;

	if (!stack2 || !(*stack2) || !((*stack2)->next))
		return ;
	if (!silenced)
		ft_printf("sb\n");
	(void)stack1;
	first = *stack2;
	third = ((*stack2)->next)->next;
	((*stack2)->next)->next = first;
	*stack2 = first->next;
	first->next = third;
}

void	ft_ss(t_slab **stack1, t_slab **stack2)
{
	ft_printf("ss\n");
	ft_sa(stack1, stack2, TRUE);
	ft_sb(stack1, stack2, TRUE);
}
