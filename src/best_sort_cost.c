/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:25:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/23 17:33:44 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

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

/*Decide how much to rotate b stack in order to
	push a stack value into correct position*/
void	b_rotation_cost(int a_val, t_dt *dt)
{
	dt->sort_data.b_min_val = min_value(dt->head_b);
	dt->sort_data.b_max_val = max_value(dt->head_b);
	if ((a_val > dt->sort_data.b_max_val) || (a_val < dt->sort_data.b_min_val))
		b_rotation_max_to_top(dt);
	else
		b_rotation_middle(a_val, dt);
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
