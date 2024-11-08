/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:46:30 by estettle          #+#    #+#             */
/*   Updated: 2024/11/08 13:04:22 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Allocates and returns a new t_slab element.
 *
 * @param nb The integer that the slab will represent.
 * @return The newly allocated t_slab.
 */
t_slab	*slab_new(int nb)
{
	t_slab	*new_slab;

	new_slab = malloc(sizeof(t_slab));
	new_slab->number = nb;
	return (new_slab);
}

t_slab	*slab_last(t_slab *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	slab_add_back(t_slab **lst, t_slab *new)
{
	t_slab	*last;

	last = slab_last(*lst);
	last->next = new;
}

void	slab_add_front(t_slab **lst, t_slab *new)
{
	new->next = *lst;
	*lst = new;
}
