/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:49:24 by estettle          #+#    #+#             */
/*   Updated: 2024/11/14 12:57:30 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Kills the program while freeing stacks' memory and displays
 * an error message if applicable.
 *
 * @note Note that both stacks can be NULL in case the program needs to close
 * but hasn't initialized its stacks just yet.
 *
 * @param stack1 The first stack to clear.
 * @param stack2 The second stack to clear.
 * @param error_code An error code to pass as argument to the exit() function.
 * If error_code == 0, the program will exit without printing "Error\n".
 */
void	ft_kill(t_slab **stack1, t_slab **stack2, int error_code)
{
	stack_clear(stack1);
	stack_clear(stack2);
	if (error_code != 0)
		write(2, "Error\n", 6);
	exit(error_code);
}

void	print_stack(t_slab **list)
{
	t_slab	*slab;

	if (!list || !(*list))
		return ;
	slab = *list;
	while (slab)
	{
		printf("%lld\n", slab->number);
		slab = slab->next;
	}
	printf("---\n"); // DON'T FORGET TO REPLACE WITH FT_PRINTF
}

int	main(int argc, char **argv)
{
	t_slab	**stack1;
	t_slab	**stack2;

	if (argc < 2)
		return (-1);
	stack1 = parse_input(argc, argv);
	stack2 = malloc(sizeof(t_slab*));
	if (!stack2)
		ft_kill(stack1, NULL, -1);
	ft_pb(stack1, stack2);
	print_stack(stack1);
	print_stack(stack2);
	/*
	print_stack(stack1);
	ft_dirty(stack1, stack2);
	print_stack(stack1);
	*/
	ft_kill(stack1, stack2, 0);
}
