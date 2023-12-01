/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:53:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/29 20:30:43 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief In case the two values are not sorted it prints the swap command
/// @param dt main data struct
static void	sort_two(t_dt *dt)
{
	if (dt->head_a->next->val > dt->head_a->prev->val)
		write(1, "sa\n", 3);
}

/// @brief Prints out instructions to sort all possible unsorted states of
///		stack with three elements
/// @param dt main data struct
static void	sort_three(t_dt *dt)
{
	if (dt->head_a->next->index == 1 && dt->head_a->prev->index == 2)
		write(1, "ra\nsa\nrra\n", 10);
	else if (dt->head_a->next->index == 2 && dt->head_a->prev->index == 3)
		write(1, "sa\n", 3);
	else if (dt->head_a->next->index == 2 && dt->head_a->prev->index == 1)
		write(1, "rra\n", 4);
	else if (dt->head_a->next->index == 3 && dt->head_a->prev->index == 2)
		write(1, "ra\n", 3);
	else if (dt->head_a->next->index == 3 && dt->head_a->prev->index == 1)
		write(1, "sa\nrra\n", 7);
}

/// @brief Continuation of find_best_algorithm procedure.
/// @param dt main data struct
static void	find_best_algorithm_continuum(t_dt *dt)
{
	if (dt->a_length > 4 && dt->a_length < 1000)
	{
		better_sort(dt);
		if (dt->operations < dt->min_operations)
		{
			dt->alg_flag = 3;
			dt->min_operations = dt->operations;
		}
		dt->operations = 0;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag = 0;
	}
	if (dt->a_length >= 4)
	{
		k_sort(dt);
		if (dt->operations <= dt->min_operations)
			dt->alg_flag = 4;
		dt->operations = 0;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag = 0;
	}
	dt->print_flag = 1;
}

/// @brief Runs every algorithm and checks which algorithm is the most
///		efficient for a given stack.
/// @param dt main data struct
static void	find_best_algorithm(t_dt *dt)
{
	if (dt->a_length > 2 && dt->a_length < 500)
	{
		bubble(dt);
		dt->min_operations = dt->operations;
		dt->operations = 0;
		dt->alg_flag = 1;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag = 0;
	}
	if (dt->a_length > 4 && dt->a_length < 1000)
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

/// @brief Main sorting function, decides what should be done. First checks
///	if the input is already sorted or if there is need for complex algorithm
///	(i.e.: input is less than 3 values). Then runs routine to decide which
///	algorithm sorts with least steps and chooses this algorithm via the flag
///	from main data struct.
/// @param dt main data struct
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
