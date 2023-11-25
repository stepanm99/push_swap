/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:47:19 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 17:26:04 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	min_index_loop(t_dt *dt, t_link *temp, unsigned int limit,
			char max_flag)
{
	unsigned int	min_index;

	if (!max_flag)
		min_index = 4294967295;
	else
		min_index = 0;
	while (limit && temp)
	{
		if (!max_flag)
		{
			if (temp->index < min_index && limit)
				min_index = temp->index;
		}
		else
		{
			if (temp->index > min_index && limit)
				min_index = temp->index;
		}
		temp = temp->next;
		limit--;
	}
	dt->min_index = min_index;
}

void	min_index(t_dt *dt,	t_link *head, int range, char max_flag)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	min_index;
	char			back_flag;

	if (!head)
		error(dt);
	back_flag = 0;
	temp = find_min_index_get_temp(dt, head);
	limit = find_min_index_get_limit(dt, head, range);
	min_index_loop(dt, temp, limit, max_flag);
	if (back_flag)
	{
		limit = range;
		temp = head->prev;
		while (limit && temp != head)
		{
			if (temp->index < min_index && limit)
				min_index = temp->index;
			temp = temp->prev;
			limit--;
		}
		dt->min_index = min_index;
	}
}

void	simple_sort_rotate(t_dt *dt, unsigned int forward_pos)
{
	while (forward_pos)
	{
		rotate_a(dt);
		forward_pos--;
	}
}

void	simple_sort_rev_rotate(t_dt *dt, unsigned int backward_pos)
{
	while (backward_pos)
	{
		rev_rotate_a(dt);
		backward_pos--;
	}
}

void	simple_sort(t_dt *dt)
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
		if ((forward_pos < backward_pos)
			&& (dt->head_a->next->index != dt->min_index))
			simple_sort_rotate(dt, forward_pos);
		else if ((backward_pos < forward_pos)
			&& (dt->head_a->next->index != dt->min_index))
			simple_sort_rev_rotate(dt, backward_pos);
		push_b(dt);
	}
	while (dt->b_length)
		push_a(dt);
}
