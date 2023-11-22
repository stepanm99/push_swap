/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:53:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/22 13:19:12 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Function to sort stack with only two elelemnts*/
void	sort_two(t_dt *dt)
{
	if (dt->head_a->next->index > dt->head_a->prev->index)
		swap_a(dt);
}

/*Continuation of function to meet norm requirements*/
static void	find_best_algorithm_1(t_dt *dt)
{
	if (dt->a_length >= 10)
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
		best_sort(dt);
		if (dt->operations < dt->min_operations)
			dt->alg_flag = 4;
		dt->operations = 0;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag = 0;
	}
	dt->print_flag = 1;
}

/*Checks which algorithm makes least moves*/
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
		sort_to_b(dt);
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
	find_best_algorithm_1(dt);
}

/*Main sorting function, decides what should be done*/
void	sort(t_dt *dt)
{

//	find_best_algorithm(dt);
	dt->print_flag = 1;
	dt->alg_flag = 4;			//for testing
	if (dt->a_length == 1)
		return ;
	else if (dt->a_length == 2)
		sort_two(dt);
	else if (dt->a_length == 3)
		bubble(dt);
	else
	{
		if (dt->alg_flag == 1)
			bubble(dt);
		else if (dt->alg_flag == 2)
			sort_to_b(dt);
		else if (dt->alg_flag == 3)
			better_sort(dt);
		else if (dt->alg_flag == 4)
			best_sort(dt);
	}
}
