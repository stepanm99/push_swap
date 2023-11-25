/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_find_min_index.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:52:23 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 17:19:26 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

t_link	*find_min_index_get_temp(t_dt *dt, t_link *head)
{
	if (head == dt->head_a)
		return (dt->head_a->next);
	else if (head == dt->head_b)
		return (dt->head_b->next);
	else
		return (NULL);
}

unsigned int	find_min_index_get_limit(t_dt *dt, t_link *head, int range)
{
	unsigned int	limit;

	limit = range;
	if (head == dt->head_a)
	{
		if (range == 0)
			limit = dt->a_length;
		else
			limit = range;
	}
	else if (head == dt->head_b)
	{
		if (range == 0)
			limit = dt->b_length;
		else
			limit = range;
	}
	return (limit);
}

unsigned int	find_min_index(t_dt *dt, t_link *head, int range)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	i;

	if (!head)
		error(dt);
	limit = find_min_index_get_limit(dt, head, range);
	temp = find_min_index_get_temp(dt, head);
	i = 0;
	while (limit)
	{
		if (temp->index == dt->min_index && limit)
			return (i);
		temp = temp->next;
		i++;
		limit--;
	}
	return (4294967295);
}
