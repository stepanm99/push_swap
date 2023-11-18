/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:26 by stepan            #+#    #+#             */
/*   Updated: 2023/11/18 23:14:17 by stepan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/push_swap.h"

/*prototype
void	b_rotation(t_dt *dt)
{

}*/

/*need to work out the logic :(*/
int	calculate_b_rot_cost(int a_position, t_dt *dt)
{
	int	cost;
	int	a_stack_middle;
	int	rev_flag;

	a_stack_middle = dt->a_length / 2;
	if (a_position <= a_stack_middle)
		rev_flag = 0;
	else
		rev_flag = 1;
	if (dt->sort_data.b_rev_rot < 0)
	{
		if (a_position < dt->sort_data.b_rot)

		else

	}
	if (dt->sort_data.b_rot < 0)
	{
		if (a_positon < dt->sort_data.b_rev_rot)

		else

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

void	best_sort(t_dt *dt)
{
	push_b(dt);
	push_b(dt);
	
	printf("max a value: %i\n", max_value(dt->head_a));
	printf("max b value: %i\n", max_value(dt->head_b));
	calculate_cost(dt);
}
