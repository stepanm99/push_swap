/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:14:46 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/11 13:50:05 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Frees entire list from head*/
void	list_free(t_link *head)
{
	t_link	*temp;

	temp = NULL;
	while (temp != head)
	{
		temp = head->prev;
		head->prev = temp->prev;
		free(temp);
	}
}

/*Adds next link to the list a and returns address of the new link*/
t_link	*list_add_link_a(t_link *link, int val, t_dt *dt)
{
	t_link	*new_link;

	new_link = malloc(sizeof(t_link));
	if (!new_link)
		error(dt);
	dt->head_a->prev = new_link;
	link->next = new_link;
	new_link->prev = link;
	new_link->next = NULL;
	new_link->val = val;
	new_link->index = 0;
	return (new_link);
}

/*Adds next link to the list b and returns address of the new link*/
t_link	*list_add_link_b(t_link *link, int val, t_dt *dt)
{
	t_link	*new_link;

	new_link = malloc(sizeof(t_link));
	if (!new_link)
		error(dt);
	dt->head_b->prev = new_link;
	link->next = new_link;
	new_link->prev = link;
	new_link->next = NULL;
	new_link->val = val;
	new_link->index = 0;
	return (new_link);
}

/*Initializes list a and list b*/
void	list_init(int val, t_dt *dt)
{
	if (!dt->a)
		dt->a = malloc(sizeof(t_link));
	if (!dt->a)
		error(dt);
	if (!dt->b)
		dt->b = malloc(sizeof(t_link));
	if (!dt->b)
		error(dt);
	dt->head_a = dt->a;
	dt->a->val = val;
	dt->a->prev = NULL;
	dt->a->next = NULL;
	dt->a->index = 0;
	dt->a->val = val;
	dt->head_b = dt->b;
	dt->b->prev = NULL;
	dt->b->next = NULL;
	dt->b->index = 0;
	dt->b->val = 0;
}
