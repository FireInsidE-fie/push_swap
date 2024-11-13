/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:49:24 by estettle          #+#    #+#             */
/*   Updated: 2024/11/12 18:08:21 by estettle         ###   ########.fr       */
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
	printf("---\n");
}

int	main(int argc, char **argv)
{
	t_slab	**stack1;
	t_slab	**stack2;

	if (argc < 2)
		return (-1);
	stack1 = parse_input(argc, argv);
	stack2 = 0;
	print_stack(stack1);
	ft_sa(stack1, stack2);
	print_stack(stack1);
	ft_sa(stack1, stack2);
	print_stack(stack1);
	ft_ra(stack1, stack2);
	print_stack(stack1);
	ft_ra(stack1, stack2);
	print_stack(stack1);
	ft_ra(stack1, stack2);
	ft_ra(stack1, stack2);
	ft_ra(stack1, stack2);
	print_stack(stack1);
	(void)stack2;
}
