/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:49:24 by estettle          #+#    #+#             */
/*   Updated: 2024/11/08 13:41:44 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h> // DON'T FORGET TO REPLACE WITH FT_PRINTF

void	print_stack(t_slab **list)
{
	t_slab	*slab;

	if (!list || !(*list))
		return ;
	slab = *list;
	while (slab)
	{
		printf("%i\n", slab->number);
		slab = slab->next;
	}
}

int	main(int argc, char **argv)
{
	t_slab	**stack1;
	t_slab	**stack2;

	if (argc < 2)
		return (-1);
	stack1 = ft_parse_input(argc, argv);
	stack2 = 0;
	print_stack(stack1);
	(void)stack2;
}
