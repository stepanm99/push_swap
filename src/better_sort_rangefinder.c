/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sort_rangefinder.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:47:59 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 18:48:40 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

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
