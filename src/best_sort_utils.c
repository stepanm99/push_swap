/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:44:11 by stepan            #+#    #+#             */
/*   Updated: 2023/11/23 23:46:57 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Finds and return maximal value in the stack of the given head*/
int	max_value(t_link *head)
{
	t_link	*current;
	int		max_value;

	max_value = -2147483648;
	if (head)
		current = head->next;
	else
		return (0);
	while (current)
	{
		if (current->val > max_value)
			max_value = current->val;
		current = current->next;
	}
	return (max_value);
}

/*Finds and return minimal value in the stack of the given head*/
int	min_value(t_link *head)
{
	t_link	*current;
	int		min_value;

	min_value = 2147483647;
	current = head->next;
	while (current)
	{
		if (current->val < min_value)
			min_value = current->val;
		current = current->next;
	}
	return (min_value);
}

int	find_head_length(t_link *head, t_dt *dt)
{
	int	length;

	length = 0;
	if (head == dt->head_a)
		length = dt->a_length;
	else if (head == dt->head_b)
		length = dt->b_length;
	else
		error(dt);
	return (length);
}

int	get_min_cost_pos(t_dt *dt)
{
	t_link	*current;
	int		min_cost;
	int		min_cost_pos;
	int		pos;

	min_cost = 2147483647;
	current = dt->head_a->next;
	pos = 0;
	while (current)
	{
		if (current->cost < min_cost)
		{
			min_cost = current->cost;
			min_cost_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_cost_pos);
}

int	get_min_cost_value(int min_cost_position, t_dt *dt)
{
	t_link	*current;
	int		min_cost_value;

	current = dt->head_a->next;
	min_cost_value = 0;
//	printf("min_cost_position: %i ", min_cost_position);
	while (min_cost_position && current)
	{
		current = current->next;
		min_cost_position--;
	}
	if (current)
	{
		min_cost_value = current->val;
	}
	else
		error(dt);
//	printf("min_cost_value: %i\n", min_cost_value);
	return (min_cost_value);
}
