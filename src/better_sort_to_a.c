/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sort_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:46:39 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 18:48:54 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	b_rotation(t_dt *dt, unsigned int forward_pos)
{
	while (forward_pos)
	{
		rotate_b(dt);
		forward_pos--;
	}
}

void	b_rev_rotation(t_dt *dt, unsigned int backward_pos)
{
	while (backward_pos)
	{
		rev_rotate_b(dt);
		backward_pos--;
	}
}

void	merge_and_sort_to_a_loop(t_dt *dt)
{
	unsigned int	forward_pos;
	unsigned int	backward_pos;

	forward_pos = 4294967295;
	backward_pos = 4294967295;
	while (dt->b_length)
	{
		min_index(dt, dt->head_b, 0, 1);
		forward_pos = find_min_index(dt, dt->head_b, 0);
		backward_pos = find_min_index_rev(dt, dt->head_b, 0);
		if (forward_pos == backward_pos)
			backward_pos = 4294967295;
		if ((forward_pos < backward_pos)
			&& (dt->head_b->next->index != dt->min_index))
			b_rotation(dt, forward_pos);
		else if ((backward_pos < forward_pos)
			&& (dt->head_b->next->index != dt->min_index))
			b_rev_rotation(dt, backward_pos);
		push_a(dt);
	}
}

void	merge_and_sort_to_a(t_dt *dt, int test_run)
{
	int				temp_print_flag;

	temp_print_flag = dt->print_flag;
	if (test_run)
		dt->print_flag = 0;
	merge_and_sort_to_a_loop(dt);
	if (test_run)
		dt->print_flag = temp_print_flag;
}
