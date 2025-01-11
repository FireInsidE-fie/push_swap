/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:46:42 by estettle          #+#    #+#             */
/*   Updated: 2025/01/11 15:14:24 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	has_cache(t_slab **stack)
{
	t_slab	*tmp;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	if (tmp->number > tmp->next->number)
		return TRUE;
	return FALSE;
}