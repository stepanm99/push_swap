/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:25:21 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/23 22:32:36 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Finds value in the stack of the head, if it is closer from the back,
	returns negative number*/
int	find_value(t_link *head, int val, t_dt *dt)
{
	t_link	*current;
	int		forward;

	forward = 0;
	current = NULL;
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
	if (forward < (int)(dt->b_length / 2))
		return (forward - dt->b_length);
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

	current = NULL;
	forward = 0;
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
		else
		{
			if (current->prev->prev->val > val && current->val < val)
				break ;
		}
		current = current->next;
		forward++;
	}
	if (forward > (int)(dt->b_length / 2))
		return ((forward - dt->b_length));
	else
		return (forward);
}


/*Procedure to set correct values for b rotation*/
void	set_b_rot_values(int rot, t_dt *dt)
{
	if (rot < 0)
	{
		dt->sort_data.b_rev_rot = (rot * -1);
		dt->sort_data.b_rot = -1;
	}
	else
	{
		dt->sort_data.b_rot = rot;
		dt->sort_data.b_rev_rot = -1;
	}
}

/*Finds out how many rotation steps are needed to get max
	value to the top of the stack*/
void	b_rotation_max_to_top(t_dt *dt)
{
	int	rot;

	rot = find_value(dt->head_b, dt->sort_data.b_max_val, dt);
	set_b_rot_values(rot, dt);
}

/*Finds out how many rotation steps are needed to get min
	value to the top of the stack*/
void	b_rotation_min(t_dt *dt)
{
	int	rot;

	rot = find_value(dt->head_b, dt->sort_data.b_min_val, dt);
	set_b_rot_values(rot, dt);
}

/*Finds out how many rotation steps are needed to get
	correct position according to a given value to the top of the stack*/
void	b_rotation_middle(int val, t_dt *dt)
{
	int	rot;

	rot = find_space(dt->head_b, val, dt);
	set_b_rot_values(rot, dt);
}

void	check_parallel_rotations(t_dt *dt)
{
	if (dt->sort_data.ra > 0 && dt->sort_data.rb > 0)
	{
		if (dt->sort_data.ra >= dt->sort_data.rb)
		{
			dt->sort_data.rr = dt->sort_data.ra - dt->sort_data.rb;
			dt->sort_data.rb = 0;
			dt->sort_data.ra = dt->sort_data.ra - dt->sort_data.rr;
		}
		else if (dt->sort_data.rb > dt->sort_data.ra)
		{
			dt->sort_data.rr = dt->sort_data.rb - dt->sort_data.ra;
			dt->sort_data.ra = 0;
			dt->sort_data.rb = dt->sort_data.rb - dt->sort_data.rr;
		}
	}
	if (dt->sort_data.rra > 0 && dt->sort_data.rrb > 0)
	{
		if (dt->sort_data.rra >= dt->sort_data.rrb)
		{
			dt->sort_data.rrr = dt->sort_data.rra - dt->sort_data.rrb;
			dt->sort_data.rrb = 0;
			dt->sort_data.rra = dt->sort_data.rra - dt->sort_data.rrr;
		}
		else if (dt->sort_data.rrb > dt->sort_data.rra)
		{
			dt->sort_data.rrr = dt->sort_data.rrb - dt->sort_data.rra;
			dt->sort_data.rra = 0;
			dt->sort_data.rrb = dt->sort_data.rrb - dt->sort_data.rrr;
		}
	}
}

/*Function for finding how many and which rotations to make on each stack*/
void	best_sort_get_rot(t_dt *dt)
{
	int	min_cost_position;
	int	min_cost_value;
	int	stack_a_middle;

	min_cost_position = get_min_cost_pos(dt);
	min_cost_value = get_min_cost_value(min_cost_position, dt);
	stack_a_middle = dt->a_length / 2;
//	clean_rot_data(dt);
	b_rotation_cost(min_cost_value, dt);
	if (min_cost_position <= stack_a_middle)
		dt->sort_data.ra = min_cost_position;
	else if (min_cost_position > stack_a_middle)
		dt->sort_data.rra = (min_cost_position - stack_a_middle);
	if (dt->sort_data.b_rev_rot < 0)
		dt->sort_data.rb = dt->sort_data.b_rot;
	else if (dt->sort_data.b_rot < 0)
		dt->sort_data.rrb = dt->sort_data.b_rev_rot;
}
