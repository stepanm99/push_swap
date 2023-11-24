/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:14:46 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/24 22:38:03 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	list_length(t_link *head)
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

/*Adds next link to the list a and returns address of the new link*/
t_link	*list_add_link_a(int val, unsigned int index, t_dt *dt)
{
	dt->a->next = malloc(sizeof(t_link));
	if (!dt->a->next)
		error(dt);
	dt->head_a->prev = dt->a->next;
	dt->a->next->prev = dt->a;
	dt->a->next->next = NULL;
	dt->a->next->val = val;
	if (index)
		dt->a->next->index = index;
	else
		dt->a->next->index = 0U;
	dt->a_length = dt->a_length + 1U;
	dt->a = dt->a->next;
	return (dt->a);
}

/*Adds next link to the list b and returns address of the new link*/
t_link	*list_add_link_c(int val, unsigned int index, t_dt *dt)
{
	dt->c->next = malloc(sizeof(t_link));
	if (!dt->c->next)
		error(dt);
	dt->head_c->prev = dt->c->next;
	dt->c->next->prev = dt->c;
	dt->c->next->next = NULL;
	dt->c->next->val = val;
	dt->c->next->index = index;
	dt->c_length = dt->c_length + 1U;
	dt->c = dt->c->next;
	return (dt->c);
}

t_link	*list_add_link_b(int val, unsigned int index, t_dt *dt)
{
	dt->b->next = malloc(sizeof(t_link));
	if (!dt->b->next)
		error(dt);
	dt->head_b->prev = dt->b->next;
	dt->b->next->prev = dt->b;
	dt->b->next->next = NULL;
	dt->b->next->val = val;
	dt->b->next->index = index;
	dt->b_length = dt->b_length + 1U;
	dt->b = dt->b->next;
	return (dt->b);
}
