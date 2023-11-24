/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:47:39 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/24 23:05:41 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	check_sort_continuum(t_dt *dt)
{
	t_link	*current_b;

	if (dt->head_b->next)
	{
		current_b = dt->head_b->next;
		while (current_b->next)
		{
			if (current_b->index > current_b->next->index)
			{
				dt->b_sorted_flag = 0;
				break ;
			}
			else
				dt->b_sorted_flag = 1;
			current_b = current_b->next;
		}
	}
}

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
	check_sort_continuum(dt);
}

void	bubble_iteration(t_dt *dt)
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

void	bubble(t_dt *dt)
{
	while (!dt->a_sorted_flag)
	{
		bubble_iteration(dt);
		check_sort(dt);
	}
}
