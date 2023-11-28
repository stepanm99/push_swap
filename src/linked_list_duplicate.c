/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_duplicate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:36:45 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/28 17:46:51 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief Duplicates stack a to stack c to save initial state for testing
///		multiple algorithms without need for new parsing
/// @param dt main data struct
void	duplicate_list_a_to_c(t_dt	*dt)
{
	t_link	*a_temp;

	if (!dt->head_a->next)
		return ;
	if (!dt->head_c)
	{
		dt->head_c = malloc(sizeof(t_link));
		if (!dt->head_c)
			error(dt);
		dt->head_c->next = NULL;
		dt->head_c->prev = NULL;
		dt->c = dt->head_c;
	}
	a_temp = dt->head_a->next;
	while (a_temp)
	{
		list_add_link_c(a_temp->val, a_temp->index, dt);
		a_temp = a_temp->next;
	}
}

/// @brief Duplicates stack c to stack a
/// @param dt main data struct
void	duplicate_list_c_to_a(t_dt	*dt)
{
	t_link	*c_temp;

	if (!dt->head_a)
	{
		dt->head_a = malloc(sizeof(t_link));
		if (!dt->head_a)
			error(dt);
		dt->head_a->next = NULL;
		dt->head_a->prev = NULL;
		dt->a = dt->head_a;
	}
	c_temp = dt->head_c->next;
	while (c_temp)
	{
		list_add_link_a(c_temp->val, c_temp->index, dt);
		c_temp = c_temp->next;
	}
}
