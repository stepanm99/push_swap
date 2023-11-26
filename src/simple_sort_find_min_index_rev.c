/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_find_min_index_rev.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:54:08 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/26 19:54:11 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief Function to get the right last link from the list
/// @param dt main data struct
/// @param head head of the stack we want the last link from
/// @return the address of the last link in the list of head
t_link	*find_min_index_rev_get_temp(t_dt *dt, t_link *head)
{
	if (head == dt->head_a)
		return (dt->head_a->prev);
	else if (head == dt->head_b)
		return (dt->head_b->prev);
	else
		return (NULL);
}

/// @brief Finds the minimal index 
/// @param dt main data struct
/// @param head head of the list we search in
/// @param range range in which to search; if 0, it searches through
/// @return minimal index position in the list in specified range or
///			in entire list if the range is 0
unsigned int	find_min_index_rev(t_dt *dt, t_link *head, int range)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	i;

	if (!head)
		error(dt);
	limit = find_min_index_get_limit(dt, head, range);
	temp = find_min_index_rev_get_temp(dt, head);
	i = 1;
	while (limit)
	{
		if (temp->index == dt->min_index && limit)
			return (i);
		temp = temp->prev;
		i++;
		limit--;
	}
	return (4294967295);
}
