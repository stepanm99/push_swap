/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:44:11 by stepan            #+#    #+#             */
/*   Updated: 2023/11/17 18:16:08 by stepan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Finds and return maximal value in the stack of the given head*/
int	max_value(t_link *head)
{
	t_link	*current;
	int		max_value;

	max_value = -2147483648;
	current = head->next;
	while(current)
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
	while(current)
	{
		if (current->val < min_value)
			min_value = current->val;
		current = current->next;
	}
	return (min_value);
}

/*Finds value in the stack of the head, if it is closer from the back,
	returns negative number*/
int	find_value(t_link *head, int val, t_dt *dt)
{
	t_link	*current;
	int		forward;
	int		backward;

	forward = 0;
	backward = 0;
	if (!head)
		error(dt);
	if (head->next)
		current = head->next;
	while (current)
	{
		if (current->val == val)
			break ;
		current = current->next;
		forward++;
	}
	current = head->prev;
	while (current != head)
	{
		if (current->val == val)
			break ;
		current = current->prev;
		backward++;
	}
	if (backward < forward)
		return ((backward * -1));
	else
		return (forward);
}

/*In case the value that should be pushed to b is not new minimum or maximum,
	finds a correct place for the value, for reverse rotation returns negative
	number*/
int	find_space(t_link *head, int val, t_dt *dt)
{
	t_link	*current;
	int		forward;
	int		backward;

	forward = 0;
	backward = 0;
	if (!head)
		error(dt);
	if (head->next)
		current = head->next;
	while (current)
	{
		if (current->prev != head)
		{
			if (current->prev->val > val && current->val < val)
				break ;
		}
		current = current->next;
		forward++;
	}
	current = head->prev;
	while (current != head)
	{
		if (current->next != NULL)
		{
			if (current->val < val && current->next->val > val)
				break ;
		}
		current = current->prev;
		backward++;
	}
	if (backward < forward)
		return ((backward * -1));
	else
		return (forward);
}

/*Nulls cost in the stack of the particular head*/
void	null_cost_stack(t_link *head)
{
	t_link	*current;

	current = head->next;
	while (current)
	{
		current->cost = 0;
		current = current->next;
	}
}

/*Function to null cost of both stacks*/
void	null_cost(t_dt *dt)
{
	null_cost_stack(dt->head_a);
	null_cost_stack(dt->head_b);
}

/*Calculates unavoidable cost of rotating the link to the top for pushing,
	takes reverse rotation into account*/
void	rotation_cost(t_dt *dt)
{
	int		i;
	int		stack_middle;
	int		rev_flag;
	t_link	*current;

	i = 0;
	stack_middle = dt->a_length / 2;
	current = dt->head_a->next;
	rev_flag = 0;
	while (current)
	{
		current->cost = i;
		if (!rev_flag)
			i++;
		else
			i--;
		if (i == stack_middle)
		{
			rev_flag = 1;
			current = current->next;
			current->cost = i;
		}
		current = current->next;
	}
}

void	b_rotation_max(t_dt *dt)
{
	int	rot;

	rot = find_value(dt->head_b, dt->sort_data.b_max_val, dt);
	if (rot < 0)
		dt->sort_data.b_rev_rot = (rot * -1);
	else
		dt->sort_data.b_rot = rot;
}

void	b_rotation_min(t_dt *dt)
{
	int	rot;

	rot = find_value(dt->head_b, dt->sort_data.b_min_val, dt);
	if (rot < 0)
		dt->sort_data.b_rev_rot = (rot * -1);
	else
		dt->sort_data.b_rot = rot;
}

/*Decide how to rotate b stack in order to push a stack value into correct position*/
void	b_rotation(int a_val, t_dt *dt)
{
	dt->sort_data.b_min_val = min_value(dt->head_b);
	dt->sort_data.b_max_val = max_value(dt->head_b);
	if (a_val > dt->sort_data.b_max_val)
		b_rotation_max(dt);
	else if (a_val < dt->sort_data.b_min_val)
		b_rotation_min(dt);
	else
		b_rotation_middle(a_val, dt);
}