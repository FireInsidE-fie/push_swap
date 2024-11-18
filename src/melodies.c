/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melodies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:03:18 by estettle          #+#    #+#             */
/*   Updated: 2024/11/18 13:07:30 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_alis(t_slab **stack1, t_slab **stack2)
{
	if (!is_sorted(*stack1))
	{
		ft_printf("sa\n");
		ft_sa(stack1, stack2);
	}
}
