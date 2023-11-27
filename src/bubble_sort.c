/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:47:39 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/26 20:08:56 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief Checks if the stack a is sorted, then changes the a_sorted
///			flag accordingly.
/// @param dt main data struct
void	check_sort(t_dt *dt)
{
	t_link	*current_a;

	if (dt->head_a->next)
	{
		current_a = dt->head_a->next;
		while (current_a->next)
		{
			if (current_a->index > current_a->next->index)
			{
				dt->a_sorted_flag = 0;
				break ;
			}
			else
				dt->a_sorted_flag = 1;
			current_a = current_a->next;
		}
	}
}

/// @brief Rotates entire stack once and swaps values if neccesarry
/// @param dt main data struct
static void	bubble_iteration(t_dt *dt)
{
	unsigned int	i;

	i = dt->a_length;
	while (i)
	{
		if (dt->head_a->next->next->index < dt->head_a->next->index && i > 1)
			swap_a(dt);
		rotate_a(dt);
		i--;
	}
}

/// @brief Rotates stack. If the second value from top is less than first one,
///	it swaps those and then continues.
/// @param dt main data struct
void	bubble(t_dt *dt)
{
	while (!dt->a_sorted_flag)
	{
		bubble_iteration(dt);
		check_sort(dt);
	}
}
