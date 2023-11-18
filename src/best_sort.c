/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:26 by stepan            #+#    #+#             */
/*   Updated: 2023/11/18 22:32:32 by stepan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/push_swap.h"

/*prototype
void	b_rotation(t_dt *dt)
{

}*/

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
