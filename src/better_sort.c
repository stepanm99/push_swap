/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:47:35 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 18:48:33 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	better_sort(t_dt *dt)
{
	int	range;

	range = find_best_range(dt);
	while (dt->a_length)
		sort_to_buckets(dt, range, 0);
	merge_and_sort_to_a(dt, 0);
}
