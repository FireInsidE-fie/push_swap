/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:46:51 by estettle          #+#    #+#             */
/*   Updated: 2025/01/11 14:54:34 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

// Libft and printf
# include "../libftprintf/ft_printf.h"

// Enums
typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
} t_bool;

// Linked list element
typedef struct s_slab
{
	int64_t			number;
	int32_t			index;
	int32_t			final_position;
	struct s_slab	*next;
}	t_slab;

// Operation functions
void		ft_sa(t_slab **stack1, t_slab **stack2, int silenced);
void		ft_sb(t_slab **stack1, t_slab **stack2, int silenced);
void		ft_ss(t_slab **stack1, t_slab **stack2);
void		ft_pa(t_slab **stack1, t_slab **stack2);
void		ft_pb(t_slab **stack1, t_slab **stack2);
void		ft_ra(t_slab **stack1, t_slab **stack2, int silenced);
void		ft_rb(t_slab **stack1, t_slab **stack2, int silenced);
void		ft_rr(t_slab **stack1, t_slab **stack2);
void		ft_rra(t_slab **stack1, t_slab **stack2, int silenced);
void		ft_rrb(t_slab **stack1, t_slab **stack2, int silenced);
void		ft_rrr(t_slab **stack1, t_slab **stack2);

// Algorithm functions
void		ft_alis(t_slab **stack1, t_slab **stack2);
void		ft_roxy(t_slab **stack1, t_slab **stack2);
void		ft_ash(t_slab **stack1, t_slab **stack2);
void		ft_melody(t_slab **stack1, t_slab **stack2);
void		ft_radix(t_slab **stack1, t_slab **stack2);
void		ft_reflection(t_slab **stack1, t_slab **stack2);

// Input parsing functions
t_slab		**parse_input(int argc, char **argv);

// Chained lists management functions
t_slab		*slab_new(int64_t nb, int32_t index);
t_slab		*slab_last(t_slab *lst);
void		slab_add_back(t_slab **lst, t_slab *new);
void		slab_add_front(t_slab **lst, t_slab *new);
void		stack_clear(t_slab **lst);
int32_t		slab_count(t_slab *lst);

// Util and general use functions
void		ft_kill(t_slab **stack1, t_slab **stack2, int error_code);
void		print_stack(t_slab **list);
int8_t		is_sorted(t_slab *lst);
t_slab		*get_min_unindexed(t_slab *lst);
void		index_stack(t_slab *lst);
void		findex_stack(t_slab *lst);
int64_t		ft_atol(const char *str);
void		push_back(t_slab **stack1, t_slab **stack2);
int64_t		slab_max(t_slab **stack);

#endif // PUSH_SWAP_H
