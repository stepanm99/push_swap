/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:14:46 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/03 17:01:56 by smelicha         ###   ########.fr       */
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
void	list_free(t_link *head)
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
}

/*Adds next link to the list a and returns address of the new link*/
t_link	*list_add_link_a(int val, t_dt *dt)
{
	dt->a->next = malloc(sizeof(t_link));
	if (!dt->a->next)
		error(dt);
	dt->head_a->prev = dt->a->next;
	dt->a->next->prev = dt->a;
	dt->a->next->next = NULL;
	dt->a->next->val = val;
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

	a_temp = dt->head_a->next;
	while (a_temp)
	{
		list_add_link_c(a_temp->val, a_temp->index, dt);
		a_temp = a_temp->next;
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
