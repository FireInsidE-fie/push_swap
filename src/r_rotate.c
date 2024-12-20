/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:02 by estettle          #+#    #+#             */
/*   Updated: 2024/12/10 10:25:49 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rra(t_slab **stack1, t_slab **stack2, int silenced)
{
	t_slab	*first;
	t_slab	*slast;

	if (!stack1 || !(*stack1) || !(*stack1)->next)
		return ;
	if (!silenced)
		ft_printf("rra\n");
	(void)stack2;
	first = *stack1;
	slast = *stack1;
	while (slast->next && (slast->next)->next)
		slast = slast->next;
	(slast->next)->next = first;
	*stack1 = slast->next;
	slast->next = NULL;
}

void	ft_rrb(t_slab **stack1, t_slab **stack2, int silenced)
{
	t_slab	*first;
	t_slab	*slast;

	if (!stack2 || !(*stack2) || !(*stack2)->next)
		return ;
	if (!silenced)
		ft_printf("rrb\n");
	(void)stack1;
	first = *stack2;
	slast = *stack2;
	while (slast->next && (slast->next)->next)
		slast = slast->next;
	(slast->next)->next = first;
	*stack2 = slast->next;
	slast->next = NULL;
}

void	ft_rrr(t_slab **stack1, t_slab **stack2)
{
	ft_printf("rrr\n");
	ft_rra(stack1, stack2, 1);
	ft_rrb(stack1, stack2, 1);
}
