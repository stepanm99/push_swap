/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:14:46 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/12 16:34:21 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int		list_length(t_link *head)
{
	int		i;
	t_link	*temp;

	i = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i - 1);
}

/*Frees entire list from head*/
void	list_free(t_link *head)
{
	t_link	*temp;
	int		list_len;

	list_len = list_length(head);
	temp = NULL;
	while (list_len)
	{
		temp = head->prev;
		head->prev = temp->prev;
		free(temp);
		temp = NULL;
		list_len--;
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

/*Initializes list a and list b
void	list_init(int val, t_dt *dt)
{
	t_link	*a;
	t_link	*b;

	a = NULL;
	b = NULL;
	if (!dt->a)
		a = malloc(sizeof(t_link));
	if (!a)
		error(dt);
	if (!dt->b)
		b = malloc(sizeof(t_link));
	if (!b)
		error(dt);
	dt->a = a;
	dt->b = b;
	dt->head_a = dt->a;
	dt->head_b = dt->b;
	dt->a->val = val;
	dt->a->prev = NULL;
	dt->a->next = NULL;
	dt->a->index = 0;
	dt->b->prev = NULL;
	dt->b->next = NULL;
	dt->b->index = 0;
	dt->b->val = 0;
}
*/
