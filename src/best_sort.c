/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:26 by stepan            #+#    #+#             */
/*   Updated: 2023/11/23 18:47:01 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Continuing of function performing actual rotations of stacks*/
void	do_rotations_cont(t_dt *dt)
{
	while (dt->sort_data.rrb != 0)
	{
		rev_rotate_b(dt);
		dt->sort_data.rrb--;
	}
	while (dt->sort_data.rrr != 0)
	{
		rev_rotate_ab(dt);
		dt->sort_data.rrr--;
	}
}

/*Function for performing actual rotations of stacks*/
void	do_rotations(t_dt *dt)
{
	while (dt->sort_data.ra != 0)
	{
		rotate_a(dt);
		dt->sort_data.ra--;
	}
	while (dt->sort_data.rb != 0)
	{
		rotate_b(dt);
		dt->sort_data.rb--;
	}
	while (dt->sort_data.rr != 0)
	{
		rotate_ab(dt);
		dt->sort_data.rr--;
	}
	while (dt->sort_data.rra != 0)
	{
		rev_rotate_a(dt);
		dt->sort_data.rra--;
	}
	do_rotations_cont(dt);
}

void	best_sort_loop_to_b(t_dt *dt)
{
	int	b_max_value;
	int	b_max_pos;

	b_max_pos = 0;
	b_max_value = 0;
	while (dt->a_length)
	{
		calculate_cost(dt);
		best_sort_get_rot(dt);
		do_rotations(dt);
		push_b(dt);
//		print_stacks_with_neigbors(dt);
	}
	b_max_value = max_value(dt->head_b);
	b_max_pos = find_value(dt->head_b, b_max_value, dt);
	if (b_max_pos < 0)
	{
		b_max_pos *= -1;
		while (b_max_pos)
		{
			rev_rotate_b(dt);
			b_max_pos--;
//			print_stacks_with_neigbors(dt);
		}
	}
	else
	{
		while (b_max_pos)
		{
			rotate_b(dt);
			b_max_pos--;
//			print_stacks_with_neigbors(dt);
		}
	}
}

void	best_sort(t_dt *dt)
{
	push_b(dt);
	push_b(dt);
//	printf("max a value: %i\n", max_value(dt->head_a));
//	printf("max b value: %i\n", max_value(dt->head_b));
	best_sort_loop_to_b(dt);
	while (dt->b_length)
		push_a(dt);
}
