/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:53:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 20:52:00 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Continuation of find_best_algorithm procedure.
	called by:	find_best_algorithm()

	calls:		better_sort()
				list_free()
				duplicate_list_c_to_a()
*/
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

/*Runs every algorithm and checks which algorithm is the most
	efficient for a given stack.
	called by:	sort()

	calls:	bubble()
			list_free()
			duplicate_list_c_to_a()
			simple_sort()
			find_best_algorithm_continuum()
*/
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

/*Main sorting function, decides what should be done. First checks if the input
	is already sorted or if there is need for complex algorithm (i.e.: input
	is less than 3 values). Ther runs routine to decide which algorithm
	sorts with least steps and chooses this algorithm via the flag.
	called by:	main()

	calls:	check_sort(dt)
			sort_two(dt)
			sort_three(dt)
			find_best_algorithm(dt)
			bubble(dt)
			simple_sort(dt)
			better_sort(dt)
			k_sort(dt)
*/
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
