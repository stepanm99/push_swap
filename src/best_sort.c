/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:26 by stepan            #+#    #+#             */
/*   Updated: 2023/11/14 18:54:42 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/push_swap.h"

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

void	null_cost(t_dt *dt)
{
	null_cost_stack(dt->head_a);
	null_cost_stack(dt->head_b);
}

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
/*prototype
void	b_rotation(t_dt *dt)
{

}*/

void	calculate_cost(t_dt *dt)
{
	t_link	*current;
	int		b_max;
//	int		cost;
//	int		i;

	null_cost(dt);
	rotation_cost(dt);
	b_max = max_value(dt->head_b);
	current = dt->head_a->next;
	current++;
	current--;
	b_max++;
	b_max--;
}

void	best_sort(t_dt *dt)
{
	push_b(dt);
	push_b(dt);
	
	printf("max value: %i\n", max_value(dt->head_a));
	calculate_cost(dt);
}
