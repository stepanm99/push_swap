/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_and_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:00:44 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/26 20:08:17 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief continuation of data_init()
/// @param dt 
static void	data_init_continuum(t_dt *dt)
{
	dt->a_length = 0U;
	dt->b_length = 0U;
	dt->c_length = 0U;
	dt->ab_flag = 0;
	dt->operations = 0;
	dt->min_operations = 0;
	dt->alg_flag = 0;
	dt->print_flag = 0;
	dt->stack_div = 1;
	dt->a_sorted_flag = 0;
	dt->min_index = 0;
}

/// @brief Initialization of variables in main data struct
/// @param dt main data struct
void	data_init(t_dt *dt)
{
	dt->head_a = malloc(sizeof(t_link));
	if (!dt->head_a)
		error(dt);
	dt->head_a->next = NULL;
	dt->head_a->prev = NULL;
	dt->head_b = malloc(sizeof(t_link));
	if (!dt->head_b)
		error(dt);
	dt->head_b->next = NULL;
	dt->head_b->prev = NULL;
	dt->head_c = malloc(sizeof(t_link));
	if (!dt->head_c)
		error(dt);
	dt->head_c->next = NULL;
	dt->head_c->prev = NULL;
	dt->head_a->index = 0;
	dt->head_b->index = 0;
	dt->head_c->index = 0;
	dt->head_a->val = 0;
	dt->head_b->val = 0;
	dt->head_c->val = 0;
	dt->a = dt->head_a;
	dt->b = dt->head_b;
	dt->c = dt->head_c;
	data_init_continuum(dt);
}

/// @brief Routine to free all allocated memory
/// @param dt main data struct
void	free_data(t_dt *dt)
{
	if (dt->head_a)
		list_free(dt->head_a, dt);
	if (dt->head_b)
		list_free(dt->head_b, dt);
	if (dt->head_c)
		list_free(dt->head_c, dt);
	free(dt);
	dt = NULL;
}
