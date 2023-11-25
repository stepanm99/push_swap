/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:53:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 20:01:44 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	find_best_algorithm_continuum(t_dt *dt)
{
	if (dt->a_length >= 10)
	{
		better_sort(dt);
		if (dt->operations < dt->min_operations)
			dt->alg_flag = 3;
		dt->operations = 0;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag = 0;
	}
	if (dt->a_length >= 20)
		dt->alg_flag = 4;
	dt->print_flag = 1;
}

void	find_best_algorithm(t_dt *dt)
{
	if (dt->a_length > 2)
	{
		bubble(dt);
		dt->min_operations = dt->operations;
		dt->operations = 0;
		dt->alg_flag = 1;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag = 0;
	}
	if (dt->a_length > 4)
	{
		simple_sort(dt);
		if (dt->operations < dt->min_operations)
		{
			dt->min_operations = dt->operations;
			dt->alg_flag = 2;
		}
		dt->operations = 0;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag = 0;
	}
	find_best_algorithm_continuum(dt);
}

/*Main sorting function, decides what should be done*/
void	sort(t_dt *dt)
{
	check_sort(dt);
	if (dt->a_length == 1)
		return ;
	else if (dt->a_sorted_flag)
		return ;
	else if (dt->a_length == 2)
	{
		sort_two(dt);
		return ;
	}
	else if (dt->a_length == 3)
	{
		sort_three(dt);
		return ;
	}
	find_best_algorithm(dt);
	if (dt->alg_flag == 1)
		bubble(dt);
	else if (dt->alg_flag == 2)
		simple_sort(dt);
	else if (dt->alg_flag == 3)
		better_sort(dt);
	else if (dt->alg_flag == 4)
		k_sort(dt);
}
