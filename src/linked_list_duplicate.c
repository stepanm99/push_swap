/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_duplicate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:36:45 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/24 22:37:38 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

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

void	duplicate_list_a_to_b(t_dt *dt)
{
	t_link	*a_temp;

	if (!dt->head_a->next)
		return ;
	if (!dt->head_b)
	{
		dt->head_b = malloc(sizeof(t_link));
		if (!dt->head_b)
			error(dt);
		dt->head_b->next = NULL;
		dt->head_b->prev = NULL;
		dt->b = dt->head_b;
	}
	a_temp = dt->head_a->next;
	while (a_temp)
	{
		list_add_link_b(a_temp->val, a_temp->index, dt);
		a_temp = a_temp->next;
	}
}

void	duplicate_list_b_to_c(t_dt *dt)
{
	t_link	*b_temp;

	if (!dt->head_b->next)
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
	b_temp = dt->head_b->next;
	while (b_temp)
	{
		list_add_link_c(b_temp->val, b_temp->index, dt);
		b_temp = b_temp->next;
	}
}
