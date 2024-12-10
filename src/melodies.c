/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melodies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:03:18 by estettle          #+#    #+#             */
/*   Updated: 2024/12/10 15:34:25 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Algorithm function in case of two elements to sort.
 */
void	ft_alis(t_slab **stack1, t_slab **stack2)
{
	if (*stack1 > (*stack1)->next)
		ft_sa(stack1, stack2, 0);
}

/**
 * @brief Algorithm function in case of three elements to sort.
 */
void	ft_roxy(t_slab **stack1, t_slab **stack2)
{
	int64_t	first;
	int64_t	second;
	int64_t	third;

	first = (*stack1)->number;
	second = (*stack1)->next->number;
	third = (*stack1)->next->next->number;
	if (first > second && second < third && third < first)
		ft_ra(stack1, stack2, 0);
	else if (first < second && second > third && third < first)
		ft_rra(stack1, stack2, 0);
	else if (first > second && second < third && third > first)
		ft_sa(stack1, stack2, 0);
	else if (first > second && second > third && third < first)
	{
		ft_sa(stack1, stack2, 0);
		ft_rra(stack1, stack2, 0);
	}
	else if (first < second && second > third && third > first)
	{
		ft_sa(stack1, stack2, 0);
		ft_ra(stack1, stack2, 0);
	}
}
