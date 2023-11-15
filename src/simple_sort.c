/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:17 by stepan            #+#    #+#             */
/*   Updated: 2023/11/15 21:14:31 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static void	sort_to_b_iteration(unsigned int forward_pos,
	unsigned int backward_pos, t_dt *dt)
{
	if ((forward_pos < backward_pos)
		&& (dt->head_a->next->index != dt->min_index))
	{
		while (forward_pos)
		{
			rotate_a(dt);
			forward_pos--;
		}
	}
	else if ((backward_pos < forward_pos)
		&& (dt->head_a->next->index != dt->min_index))
	{
		while (backward_pos)
		{
			rev_rotate_a(dt);
			backward_pos--;
		}
	}
}

/*Rotates stack a, pushes into stack b in descending order and pushing back,
	resulting in sorted stack a*/
void	sort_to_b(t_dt *dt)
{
	unsigned int	forward_pos;
	unsigned int	backward_pos;

	forward_pos = 4294967295;
	backward_pos = 4294967295;
	while (dt->a_length)
	{
		min_index(dt, dt->head_a, 0, 0);
		forward_pos = find_min_index(dt, dt->head_a, 0);
		backward_pos = find_min_index_rev(dt, dt->head_a, 0);
		if (forward_pos == backward_pos)
			backward_pos = 4294967295;
		sort_to_b_iteration(forward_pos, backward_pos, dt);
		push_b(dt);
	}
	while (dt->b_length)
		push_a(dt);
}
