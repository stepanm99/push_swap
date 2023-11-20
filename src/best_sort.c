/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:26 by stepan            #+#    #+#             */
/*   Updated: 2023/11/20 17:46:57 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/push_swap.h"


/*need to work out the logic :(*/
int	calculate_b_rot_cost(int a_position, t_dt *dt)
{
	int	cost;
	int	a_stack_middle;

	a_stack_middle = dt->a_length / 2;
	if (dt->sort_data.b_rev_rot < 0)
	{
		if (a_position < dt->sort_data.b_rot)
			cost = dt->sort_data.b_rot - a_position;
		else
			cost = a_position - dt->sort_data.b_rot;
	}
	if (dt->sort_data.b_rot < 0)
	{
		if ((a_position - a_stack_middle) < dt->sort_data.b_rev_rot)
			cost = dt->sort_data.b_rev_rot - (a_position - a_stack_middle);
		else
			cost = (a_position - a_stack_middle) - dt->sort_data.b_rev_rot;
	}
	return (cost);
}

/*How many move would it take to put this number into correct position*/
void	calculate_cost(t_dt *dt)
{
	t_link	*current;
//	int		cost;
	int		i;

	null_cost(dt);
	rotation_cost(dt);
	current = dt->head_a->next;
	i = 0;
	while (current)
	{
		b_rotation_cost(current->val, dt);
		current->cost += calculate_b_rot_cost(i, dt);
		current = current->next;
		i++;
	}
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
	return (min_cost_value);
}

/*Function for finding how many and which rotations to make on each stack*/
void	best_sort_get_rot(t_dt *dt)
{
	int	min_cost_position;
	int	min_cost_value;

	min_cost_position = get_min_cost_pos(dt);
	min_cost_value = get_min_cost_value(min_cost_position, dt);
}

void	best_sort(t_dt *dt)
{
	push_b(dt);
	push_b(dt);
	
	printf("max a value: %i\n", max_value(dt->head_a));
	printf("max b value: %i\n", max_value(dt->head_b));
	calculate_cost(dt);
	while (dt->a_length)
	{
		calculate_cost(dt);
		best_sort_get_rot(dt);
		push_b(dt);
	}
}
