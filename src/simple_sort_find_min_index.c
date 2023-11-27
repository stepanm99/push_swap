/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_find_min_index.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:52:23 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/27 16:24:17 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief Function to get the right first link from the list
/// @param dt main data struct
/// @param head head of the stack we want the first link from
/// @return the address of the first link in the list of head
t_link	*find_min_index_get_temp(t_dt *dt, t_link *head)
{
	if (head == dt->head_a)
		return (dt->head_a->next);
	else if (head == dt->head_b)
		return (dt->head_b->next);
	else
		return (NULL);
}

/// @brief Routine to figure out the correct limit in which to search
/// @param dt main data struct
/// @param head head of the list where we want to search
/// @param range range defining the limit, if 0, limit is the length
///				of the list
/// @return limit of the search
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

/// @brief Routine to find min index in a list of given head
/// @param dt main data struct
/// @param head head of the list we want to search in
/// @param range how far from the top to search
/// @return minimal index position found in the list in a given range
///			or in entire list if range is 0
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
	return (UINT32_MAX);
}
