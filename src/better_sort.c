/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:47:35 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/24 22:54:12 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	merge_and_sort_to_a(t_dt *dt, int test_run)
{
	unsigned int	forward_pos;
	unsigned int	backward_pos;
	int				temp_print_flag;

	forward_pos = 4294967295;
	backward_pos = 4294967295;
	temp_print_flag = dt->print_flag;
	if (test_run)
		dt->print_flag = 0;
	while (dt->b_length)
	{
		min_index(dt, dt->head_b, 0, 1);
		forward_pos = find_min_index(dt, dt->head_b, 0);
		backward_pos = find_min_index_rev(dt, dt->head_b, 0);
		if (forward_pos == backward_pos)
			backward_pos = 4294967295;
		if ((forward_pos < backward_pos) && (dt->head_b->next->index != dt->min_index))
		{
			while (forward_pos)
			{
				rotate_b(dt);
				forward_pos--;
			}
		}
		else if ((backward_pos < forward_pos) && (dt->head_b->next->index != dt->min_index))
		{
			while (backward_pos)
			{
				rev_rotate_b(dt);
				backward_pos--;
			}
		}
		push_a(dt);
	}
	if (test_run)
		dt->print_flag = temp_print_flag;
}

void	sort_to_buckets(t_dt *dt, int range, int test_run)
{
	unsigned int	forward_pos;
	unsigned int	backward_pos;
	int				temp_range;
	int				temp_print_flag;

	forward_pos = 4294967295;
	backward_pos = 4294967295;
	temp_range = range;
	temp_print_flag = dt->print_flag;
	if (test_run)
		dt->print_flag = 0;
	while (temp_range && dt->a_length)
	{
		min_index(dt, dt->head_a, temp_range, 0);
		forward_pos = find_min_index(dt, dt->head_a, temp_range);
		backward_pos = find_min_index_rev(dt, dt->head_a, temp_range);
		if (forward_pos == backward_pos)
			backward_pos = 4294967295;
		if ((forward_pos < backward_pos) && (dt->head_a->next->index != dt->min_index))
		{
			while (forward_pos)
			{
				rotate_a(dt);
				forward_pos--;
			}
		}
		else if ((backward_pos < forward_pos) && (dt->head_a->next->index != dt->min_index))
		{
			while (backward_pos)
			{
				rev_rotate_a(dt);
				backward_pos--;
			}
		}
		push_b(dt);
		temp_range--;
	}
	if (test_run)
		dt->print_flag = temp_print_flag;
}

unsigned int	min_range(t_dt *dt, unsigned int *range_operations)
{
	unsigned int	min_operations;
	unsigned int	range;



	range = dt->a_length / 2U;
	min_operations = 4294967295;
	while (range >= 2)
	{
		if (range_operations[range] < min_operations)
			min_operations = range_operations[range];
		range--;
	}
	range = dt->a_length / 2U;
	while ((range_operations[range] != min_operations) && range)
		range--;
	return (range);
}

unsigned int	find_best_range(t_dt *dt)
{
	unsigned int	*range_operations;
	unsigned int	range;

	range = dt->a_length / 2;
	range_operations = malloc(sizeof(unsigned int) * range);
	while (range > 1)
	{
		sort_to_buckets(dt, range, 1);
		merge_and_sort_to_a(dt, 1);
		range_operations[range] = dt->operations;
		dt->operations = 0;
		range--;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
	}
	range = min_range(dt, range_operations);
	free(range_operations);
	return (range);
}

void	better_sort(t_dt *dt)
{
	int	range;
	range = find_best_range(dt);
	while (dt->a_length)
		sort_to_buckets(dt, range, 0);
	merge_and_sort_to_a(dt, 0);
}
