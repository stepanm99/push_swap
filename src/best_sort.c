/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:26 by stepan            #+#    #+#             */
/*   Updated: 2023/11/22 20:42:51 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Claculates the cost of rotating b, taking in account the simultaneous
	rotations, outputing of actual cost it would take to rotate b alone
	so it could be added to cost of pushing the number in stack a to
	the correct position*/
int	calculate_b_rot_cost(int a_position, t_dt *dt)
{
	int	cost;
	int	a_stack_middle;

	a_stack_middle = dt->a_length / 2;
	if (dt->sort_data.b_rev_rot < 0)
	{
//		printf("first if\n");
		if (a_position < dt->sort_data.b_rot)
			cost = dt->sort_data.b_rot - a_position;
		else
			cost = a_position - dt->sort_data.b_rot;
	}
	if (dt->sort_data.b_rot < 0)
	{
//		printf("second if\n");
		if ((a_position - a_stack_middle) < dt->sort_data.b_rev_rot)
			cost = dt->sort_data.b_rev_rot - (a_position - a_stack_middle);
		else
			cost = (a_position - a_stack_middle) - dt->sort_data.b_rev_rot;
	}
//	printf("cost from b: %i\n", cost);
	return (cost);
}

/*How many move would it take to put this number into correct position*/
void	calculate_cost(t_dt *dt)
{
	t_link	*current;
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

/*Continuing of function performing actual rotations of stacks*/
void	do_rotations_cont(t_dt *dt)
{
	while (dt->sort_data.rrb != 0)
	{
		rev_rotate_b(dt);
		dt->sort_data.rrb--;
	}
	while (dt->sort_data.rrr != 0)
	{
		rev_rotate_ab(dt);
		dt->sort_data.rrr--;
	}
}

/*Function for performing actual rotations of stacks*/
void	do_rotations(t_dt *dt)
{
	while (dt->sort_data.ra != 0)
	{
		rotate_a(dt);
		dt->sort_data.ra--;
	}
	while (dt->sort_data.rb != 0)
	{
		rotate_b(dt);
		dt->sort_data.rb--;
	}
	while (dt->sort_data.rr != 0)
	{
		rotate_ab(dt);
		dt->sort_data.rr--;
	}
	while (dt->sort_data.rra != 0)
	{
		rev_rotate_a(dt);
		dt->sort_data.rra--;
	}
	do_rotations_cont(dt);
}

/*Checking zeroed data for rotation*/
void	clean_rot_data(t_dt *dt)
{
	if (dt->sort_data.ra != 0)
		printf("ra not zero\n");
	if (dt->sort_data.rb != 0)
		printf("rb not zero\n");
	if (dt->sort_data.rr != 0)
		printf("rr not zero\n");
	if (dt->sort_data.rra != 0)
		printf("rra not zero\n");
	if (dt->sort_data.rrb != 0)
		printf("rrb not zero\n");
	if (dt->sort_data.rrr != 0)
		printf("rrr not zero\n");
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
	clean_rot_data(dt);
	b_rotation_cost(min_cost_value, dt);
	if (min_cost_position <= stack_a_middle)
		dt->sort_data.ra = min_cost_position;
	else if (min_cost_position > stack_a_middle)
		dt->sort_data.rra = (min_cost_position - dt->a_length) * -1;
	if (dt->sort_data.b_rev_rot < 0)
		dt->sort_data.rb = dt->sort_data.b_rot;
	else if (dt->sort_data.b_rot < 0)
		dt->sort_data.rrb = dt->sort_data.b_rev_rot;
	check_parallel_rotations(dt);
	/*
	if (min_cost_position <= stack_a_middle)
	{
		if (dt->sort_data.b_rev_rot < 0)
		{
			if (min_cost_position >= dt->sort_data.b_rot)
			{
				printf("from: if (min_cost_position >= dt->sort_data.b_rot)\n");
				dt->sort_data.rr = min_cost_position - dt->sort_data.b_rot;
				dt->sort_data.rb = 0;
				dt->sort_data.ra = min_cost_position - dt->sort_data.rr;
			}
			else if (min_cost_position < dt->sort_data.b_rot)
			{
				printf("from: else if (min_cost_position < dt->sort_data.b_rot)\n");
				dt->sort_data.rr = dt->sort_data.b_rot - min_cost_position;
				dt->sort_data.ra = 0;
				dt->sort_data.rb = dt->sort_data.b_rot - dt->sort_data.rr;
			}
		}
		else if (dt->sort_data.b_rot < 0)
		{
			printf("from: else if (dt->sort_data.b_rot < 0)");
			dt->sort_data.rrb = dt->sort_data.b_rev_rot;
			dt->sort_data.ra = min_cost_position;
		}
	}
	else if (min_cost_position > stack_a_middle)
	{
		if(dt->sort_data.b_rev_rot < 0)
		{
			printf("from: if(dt->sort_data.b_rev_rot < 0)\n");
			dt->sort_data.rb = dt->sort_data.b_rot;
			dt->sort_data.rra = (min_cost_position - stack_a_middle);
		}
		else if (dt->sort_data.b_rot < 0)
		{
			if ((min_cost_position - stack_a_middle) <= dt->sort_data.b_rev_rot)
			{
				printf("from: if ((min_cost_position - stack_a_middle) <= dt->sort_data.b_rev_rot)\n");
				dt->sort_data.rrr = dt->sort_data.b_rev_rot - (min_cost_position - stack_a_middle);
				dt->sort_data.rra = 0;
				dt->sort_data.rrb = dt->sort_data.b_rev_rot - dt->sort_data.rrr;
			}
			else if ((min_cost_position - stack_a_middle) > dt->sort_data.b_rev_rot)
			{
				printf("from: else if ((min_cost_position - stack_a_middle) > dt->sort_data.b_rev_rot)\n");
				dt->sort_data.rrr = (min_cost_position - stack_a_middle) - dt->sort_data.b_rev_rot;
				dt->sort_data.rrb = 0;
				dt->sort_data.rra = (min_cost_position - stack_a_middle) - dt->sort_data.rrr;
			}
		}
	}*/
	printf("ra: %i\trb: %i\trr: %i\trra: %i\trrb: %i\trrr: %i\n", dt->sort_data.ra, dt->sort_data.rb, dt->sort_data.rr, dt->sort_data.rra, dt->sort_data.rrb, dt->sort_data.rrr);
}

void	best_sort_loop_to_b(t_dt *dt)
{
	int	b_max_value;
	int	b_max_pos;

	b_max_pos = 0;
	b_max_value = 0;
	while (dt->a_length)
	{
		calculate_cost(dt);
		best_sort_get_rot(dt);
		do_rotations(dt);
		push_b(dt);
		print_stacks_with_neigbors(dt);
	}
	b_max_value = max_value(dt->head_b);
	b_max_pos = find_value(dt->head_b, b_max_value, dt);
	if (b_max_pos < 0)
	{
		b_max_pos *= -1;
		while (b_max_pos)
		{
			rev_rotate_b(dt);
			b_max_pos--;
			print_stacks_with_neigbors(dt);
		}
	}
	else
	{
		while (b_max_pos)
		{
			rotate_b(dt);
			b_max_pos--;
			print_stacks_with_neigbors(dt);
		}
	}
}

void	best_sort(t_dt *dt)
{
	push_b(dt);
	push_b(dt);
//	printf("max a value: %i\n", max_value(dt->head_a));
//	printf("max b value: %i\n", max_value(dt->head_b));
	calculate_cost(dt);
	best_sort_loop_to_b(dt);
	while (dt->b_length)
		push_a(dt);
}
