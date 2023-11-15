/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:43:24 by stepan            #+#    #+#             */
/*   Updated: 2023/11/15 21:21:21 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Find minimal index in a stack of given head, limited by range;
	if max flag = 1, it finds maximal index*/
void	min_index(t_dt *dt,	t_link *head, int range, char max_flag)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	min_index;
	char			back_flag;

	if (!head)
		error(dt);
	back_flag = 0;
	limit = range;
	if (head == dt->head_a)
	{
		if (range == 0)
			limit = dt->a_length;
		else
		{
			limit = range;
			back_flag = 1;
		}
		temp = dt->head_a->next;
	}
	else if (head == dt->head_b)
	{
		if (range == 0)
			limit = dt->b_length;
		else
		{
			limit = range;
			back_flag = 1;
		}
		temp = dt->head_b->next;
	}
	if (!max_flag)
		min_index = 4294967295;
	else
		min_index = 0;
	while (limit && temp)
	{
		if (!max_flag)
		{
			if (temp->index < min_index && limit)
				min_index = temp->index;
		}
		else
		{
			if (temp->index > min_index && limit)
				min_index = temp->index;
		}
		temp = temp->next;
		limit--;
	}
	dt->min_index = min_index;
	if (back_flag)
	{
		limit = range;
		temp = head->prev;
		while (limit && temp != head)
		{
			if (temp->index < min_index && limit)
				min_index = temp->index;
			temp = temp->prev;
			limit--;
		}
		dt->min_index = min_index;
	}
}

static t_link	*find_min_index_head_logic(t_dt *dt, t_link *head)
{
	t_link	*temp;

	temp = NULL;
	if (head == dt->head_a)
		temp = dt->head_a->prev;
	else if (head == dt->head_b)
		temp = dt->head_b->prev;
	return (temp);
}

static unsigned int	find_min_index_limit_logic(t_dt *dt, t_link *head,
	int range)
{
	unsigned int	limit;

	limit = 0;
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

/*Find place of minimal index in the stack a*/
unsigned int	find_min_index(t_dt *dt, t_link *head, int range)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	i;

	if (!head)
		error(dt);
	limit = find_min_index_limit_logic(dt, head, range);
	temp = find_min_index_head_logic(dt, head);
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

/*Find place of minimal index in the stack a from back*/
unsigned int	find_min_index_rev(t_dt *dt, t_link *head, int range)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	i;

	if (!head)
		error(dt);
	limit = find_min_index_limit_logic(dt, head, range);
	temp = find_min_index_head_logic(dt, head);
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

static void	check_sort_b(t_dt *dt)
{
	t_link	*current_b;

	if (dt->head_b->next)
	{
		current_b = dt->head_b->next;
		while (current_b->next)
		{
			if (current_b->index > current_b->next->index)
			{
				dt->b_sorted_flag = 0;
				break ;
			}
			else
				dt->b_sorted_flag = 1;
			current_b = current_b->next;
		}
	}
}

/*Dev function to check if stacks are sorted*/
void	check_sort(t_dt *dt)
{
	t_link	*current_a;

	if (dt->head_a->next)
	{
		current_a = dt->head_a->next;
		while (current_a->next)
		{
			if (current_a->index > current_a->next->index)
			{
				dt->a_sorted_flag = 0;
				break ;
			}
			else
				dt->a_sorted_flag = 1;
			current_a = current_a->next;
		}
	}
	check_sort_b(dt);
}
