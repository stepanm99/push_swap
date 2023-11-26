/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:14:49 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/26 18:14:30 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief Address operations to perform rotation
/// @param address ordered array of adresses affected by the operation
static void	rotate_many(t_link *address[])
{
	address[0]->next = address[3];
	address[1]->next = address[2];
	address[2]->next = NULL;
	address[0]->prev = address[2];
	address[2]->prev = address[1];
	address[3]->prev = address[0];
}

/// @brief Address operations to perform rotation of two elements in stack
/// @param address ordered array of adresses affected by the operation
static void	rotate_two(t_link *address[])
{
	address[0]->next = address[1];
	address[1]->next = address[2];
	address[2]->next = NULL;
	address[0]->prev = address[2];
	address[1]->prev = address[0];
	address[2]->prev = address[1];
}

/// @brief Rotate operation on stack a
/// @param dt main data struct
void	rotate_a(t_dt *dt)
{
	t_link	*address[4];

	if (dt->a_length == 1)
		return ;
	address[0] = dt->head_a;
	address[1] = dt->head_a->prev;
	address[2] = dt->head_a->next;
	address[3] = dt->head_a->next->next;
	if (dt->a_length > 3)
		rotate_many(address);
	else if (dt->a_length == 3)
		rotate_three_a(dt);
	else
		rotate_two(address);
	if (!dt->ab_flag)
	{
		if (dt->print_flag)
			write(1, "ra\n", 3);
		dt->operations++;
	}
}

/// @brief Rotate operation on stack b
/// @param dt main data struct
void	rotate_b(t_dt *dt)
{
	t_link	*address[4];

	if (dt->b_length <= 1)
		return ;
	address[0] = dt->head_b;
	address[1] = dt->head_b->prev;
	address[2] = dt->head_b->next;
	address[3] = dt->head_b->next->next;
	if (dt->b_length > 3)
		rotate_many(address);
	else if (dt->b_length == 3)
		rotate_three_b(dt);
	else
		rotate_two(address);
	if (!dt->ab_flag)
	{
		if (dt->print_flag)
			write(1, "rb\n", 3);
		dt->operations++;
	}
	dt->ab_flag = 0;
}

/// @brief Rotate operation on stack a and b
/// @param dt main data struct
void	rotate_ab(t_dt *dt)
{
	dt->ab_flag = 1;
	rotate_a(dt);
	rotate_b(dt);
	if (dt->print_flag)
		write(1, "rr\n", 3);
	dt->operations++;
}
