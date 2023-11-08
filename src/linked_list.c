/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:14:46 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/05 01:28:10 by stepan           ###   ########.fr       */
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

/*Frees entire list from head*/
void	list_free(t_link *head, t_dt *dt)
{
	t_link	*current;
	t_link	*next;

	current = NULL;
	next = NULL;
	current = head;
	while (1)
	{
		next = current->next;
		free(current);
		current = next;
		if (next == NULL)
		{
			free(current);
			break ;
		}
		next->prev = NULL;
	}
	if (dt->head_a == head)
	{
		dt->head_a = NULL;
		dt->a_length = 0;
	}
	if (dt->head_b == head)
	{
		dt->head_b = NULL;
		dt->b_length = 0;
	}
	if (dt->head_c == head)
	{
		dt->head_c = NULL;
		dt->c_length = 0;
	}
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
