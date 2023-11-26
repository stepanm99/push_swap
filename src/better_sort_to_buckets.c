/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sort_to_buckets.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:13:39 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/26 17:28:35 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief Loop to sort the numbers in a to small clusters of values
/// @param dt main data struct
/// @param range how big the clusters, buckets, are
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

/// @brief Routine to sort a to b in small buckets
/// @param dt main data struct
/// @param range how big the buckets will be
/// @param test_run 0 = normal run; 1 = test run (does not print)
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
