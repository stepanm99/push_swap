/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:26 by stepan            #+#    #+#             */
/*   Updated: 2023/11/24 00:05:39 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	check_rule(int min_cost_value, t_dt *dt)
{
	if (((dt->head_a->next->val < dt->head_b->next->val)
		&& dt->head_a->next->val > dt->head_b->prev->val)
		&& dt->head_a->next->val == min_cost_value)
		return (1);
	else
		return (0);
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
	printf("from do rotations\n");
	print_stacks_with_neigbors(dt);
	printf("rule check: %i\n", check_rule(get_min_cost_value(get_min_cost_pos(dt), dt), dt));
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
		print_rotations(dt);
		do_rotations(dt);
		print_stacks_in_line(dt);
		push_b(dt);
//		print_stacks_with_neigbors(dt);
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
//			print_stacks_with_neigbors(dt);
		}
	}
	else
	{
		while (b_max_pos)
		{
			rotate_b(dt);
			b_max_pos--;
//			print_stacks_with_neigbors(dt);
		}
	}
}

void	old_best_sort(t_dt *dt)
{
	push_b(dt);
	push_b(dt);
//	printf("max a value: %i\n", max_value(dt->head_a));
//	printf("max b value: %i\n", max_value(dt->head_b));
	best_sort_loop_to_b(dt);
	while (dt->b_length)
		push_a(dt);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void	best_sort(t_dt *dt)
{
	int	i;
	int	min_cost_position;
	int	min_cost_value;
	int	min_cost;
	int	b_max_value;
	int	b_min_value;
	int	b_max_value_position;
	int	b_value_position;
	t_link	*current;

	i = 0;
	min_cost_position = 0;
	min_cost_value = INT32_MAX;
	min_cost = INT32_MAX;
	b_max_value = INT32_MIN;
	b_min_value = INT32_MAX;
	b_max_value_position = 0;
	b_value_position = 0;
	current = NULL;
	push_b(dt);
	push_b(dt);
	dt->print_flag = 0;
	while (dt->a_length)
	{
		i = 0;						//reseting values
		min_cost_position = 0;
		min_cost_value = INT32_MAX;
		min_cost = INT32_MAX;
		b_max_value = INT32_MIN;
		b_min_value = INT32_MAX;
		b_max_value_position = 0;
		b_value_position = 0;
		current = NULL;
		printf("before find values\n");
		//find values
		calculate_cost(dt);
		dt->print_flag = 1;
		current = dt->head_a->next;
		while (current)						//finding min_cost_value and min_cost_position
		{
			if (current->cost < min_cost)
			{
				min_cost = current->cost;
				min_cost_position = i;
			}
			i++;
			current = current->next;
		}
		i = 0;
		current = dt->head_b->next;
		while (current)					//finding b_max_value
		{
			if (current->val > b_max_value)
			{
				b_max_value = current->val;
				b_max_value_position = i;
			}
			i++;
			current = current->next;
		}
		i = 0;
		current = dt->head_b->next;
		while (current)					//finding b_min_value
		{
			if (current->val < b_min_value)
				b_min_value = current->val;
			current = current->next;
		}
		current = dt->head_b->next;
		if (min_cost_value < b_max_value || min_cost_value > b_min_value)	//finding b_value_pos
		{
			while (current)
			{
				if (current->prev != dt->head_b)
				{
					if (current->val < min_cost_value && current->prev->val > min_cost_value)
					{
						b_value_position = i;
						break ;
					}
				}
				else
				{
					if (current->val < min_cost_value && current->prev->prev->val > min_cost_value)
					{
						b_value_position = i;
						break ;
					}
				}
				i++;
				current = current->next;
			}
		}
		printf("before do rotations\n");
		//do rotations
		if (min_cost_position && min_cost_position <= (int)(dt->a_length / 2))	//rotating a
		{
			printf("if (min_cost_position && min_cost_position <= (int)(dt->a_length / 2))\n");
			while (min_cost_position)
			{
				rotate_a(dt);
				print_stacks_in_line(dt);
				min_cost_position--;
			}
		}
		else if (min_cost_position && min_cost_position > (int)(dt->a_length / 2))
		{
			printf("else if (min_cost_position && min_cost_position > (int)(dt->a_length / 2))\n");
			min_cost_position = min_cost_position - (int)(dt->a_length / 2) + 1;
			while (min_cost_position)
			{
				rev_rotate_a(dt);
				print_stacks_in_line(dt);
				min_cost_position--;
			}
		}

		if (b_value_position != 0)		//rotating b
		{
			printf("if (b_value_position != 0)\n");
			if (b_value_position && b_value_position <= (int)(dt->b_length / 2))
			{
				printf("if (b_value_position && b_value_position <= (int)(dt->b_length / 2))\n");
				while (b_value_position)
				{
					rotate_b(dt);
					print_stacks_in_line(dt);
					b_value_position--;
				}
			}
			else if (b_value_position && b_value_position > (int)(dt->b_length / 2))
			{
				printf("else if (b_value_position && b_value_position > (int)(dt->b_length / 2))\n");
				b_value_position = b_value_position - (dt->b_length) + 1;
				while (b_value_position)
				{
					rev_rotate_b(dt);
					print_stacks_in_line(dt);
					b_value_position--;
				}
			}
		}
		else
		{
			if (b_max_value_position && b_max_value_position <= (int)(dt->b_length / 2))
			{
				printf("if (b_max_value_position && b_max_value_position <= (int)(dt->b_length / 2))\n");
				while (b_max_value_position)
				{
					rotate_b(dt);
					print_stacks_in_line(dt);
					b_max_value_position--;
				}
			}
			else if (b_max_value_position && b_max_value_position > (int)(dt->b_length / 2))
			{
				printf("else if (b_max_value_position && b_max_value_position > (int)(dt->b_length / 2))\n");
				b_max_value_position = b_max_value_position - (dt->b_length) + 1;
				while (b_max_value_position)
				{
					rev_rotate_b(dt);
					print_stacks_in_line(dt);
					b_max_value_position--;
				}
			}
		}
		push_b(dt);
		print_stacks_in_line(dt);
	}
	printf("after main while\n");
	//aligning stack b for pushing to a
	i = 0;
	current = dt->head_b;
	while (current)						//finding b_max_position of b_max_value
	{
		if (current->val == b_max_value)
		{
			b_max_value_position = i;
			break ;
		}
		i++;
		current = current->next;
	}
	if (b_max_value_position && b_max_value_position <= (int)(dt->b_length / 2))	//rotating b to correct position
	{
		printf("if (b_max_value_position && b_max_value_position <= (int)(dt->b_length / 2))\n");
		while (b_max_value_position)
		{
			rotate_b(dt);
			print_stacks_in_line(dt);
			b_max_value_position--;
		}
	}
	else if (b_max_value_position && b_max_value_position > (int)(dt->b_length / 2))
	{
		printf("else if (b_max_value_position && b_max_value_position > (int)(dt->b_length / 2))\n");
		b_max_value_position = b_max_value_position - (int)(dt->b_length);
		printf("b_max_value_position: %i\n", b_max_value_position);
		while (b_max_value_position > 0)
		{
			printf("b_max_value_position from while: %i\n", b_max_value_position);
			rev_rotate_b(dt);
			print_stacks_in_line(dt);
			b_max_value_position--;
		}
	}
	printf("b_max_value: %i\n", b_max_value);
	while (dt->b_length)
		push_a(dt);
	print_stacks_in_line(dt);
}
