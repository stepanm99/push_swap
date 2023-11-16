/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:26 by stepan            #+#    #+#             */
/*   Updated: 2023/11/16 20:16:10 by smelicha         ###   ########.fr       */
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
	
	printf("max a value: %i\n", max_value(dt->head_a));
	printf("max b value: %i\n", max_value(dt->head_b));
	calculate_cost(dt);
}
