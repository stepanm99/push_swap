/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sort_to_buckets.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:13:39 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 18:46:01 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	sort_to_buckets_loop(t_dt *dt, int range)
{
	unsigned int	forward_pos;
	unsigned int	backward_pos;

	forward_pos = 4294967295;
	backward_pos = 4294967295;
	while (range && dt->a_length)
	{
		min_index(dt, dt->head_a, range, 0);
		forward_pos = find_min_index(dt, dt->head_a, range);
		backward_pos = find_min_index_rev(dt, dt->head_a, range);
		if (forward_pos == backward_pos)
			backward_pos = 4294967295;
		if ((forward_pos < backward_pos)
			&& (dt->head_a->next->index != dt->min_index))
			b_rotation(dt, forward_pos);
		else if ((backward_pos < forward_pos)
			&& (dt->head_a->next->index != dt->min_index))
			b_rev_rotation(dt, backward_pos);
		push_b(dt);
		range--;
	}
}

void	sort_to_buckets(t_dt *dt, int range, int test_run)
{
	int				temp_print_flag;

	temp_print_flag = dt->print_flag;
	if (test_run)
		dt->print_flag = 0;
	sort_to_buckets_loop(dt, range);
	if (test_run)
		dt->print_flag = temp_print_flag;
}
