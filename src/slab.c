/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:46:30 by estettle          #+#    #+#             */
/*   Updated: 2024/11/14 13:32:59 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Allocates and returns a new t_slab element.
 *
 * @param nb The integer that the slab will represent.
 * @return The newly allocated t_slab.
 */
t_slab	*slab_new(int64_t nb)
{
	t_slab	*new_slab;

	new_slab = malloc(sizeof(t_slab));
	if (!new_slab)
		return (NULL);
	new_slab->number = nb;
	new_slab->index = 0;
	new_slab->next = NULL;
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

/**
 * @brief Adds a slab element to the end of the given list.
 *
 * Kills the program if new is NULL, which would mean a malloc() failed in
 * the parse_input function.
 *
 * @param lst The chained list to add the slab behind.
 * @param new The slab element to add to the chained list.
 */
void	slab_add_back(t_slab **lst, t_slab *new)
{
	t_slab	*last;

	if (!new)
		ft_kill(lst, NULL, -1);
	last = slab_last(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

void	slab_add_front(t_slab **lst, t_slab *new)
{
	new->next = *lst;
	*lst = new;
}

void	stack_clear(t_slab **lst)
{
	t_slab	*next_slab;

	if (!lst)
		return ;
	while (*lst)
	{
		next_slab = (*lst)->next;
		free(*lst);
		*lst = next_slab;
	}
	lst = NULL;
}
