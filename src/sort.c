/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:53:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/24 22:57:59 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"



/*Function to sort stack with only two elelemnts*/
void	sort_two(t_dt *dt)
{
	if (dt->head_a->next->index > dt->head_a->prev->index)
		swap_a(dt);
}

/*prototype*/
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
		dt->a_sorted_flag =0;
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
		dt->a_sorted_flag =0;
	}
	if (dt->a_length >= 10)
	{
		better_sort(dt);
		if (dt->operations < dt->min_operations)
			dt->alg_flag = 3;
		dt->operations = 0;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag =0;
	}
	if (dt->a_length >=20)
		dt->alg_flag = 4;
	dt->print_flag = 1;
}

/*Main sorting function, decides what should be done*/
void	sort(t_dt *dt)
{
	find_best_algorithm(dt);
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
			simple_sort(dt);
		else if (dt->alg_flag == 3)
			better_sort(dt);
		else if (dt->alg_flag == 4)
			k_sort(dt);
	}
}