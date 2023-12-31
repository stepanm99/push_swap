/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:14:09 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/26 18:07:12 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief Address operations to perform push
/// @param address ordered array of adresses affected by push operation
static void	push(t_link *address[])
{
	address[0]->next = address[2];
	if (address[2])
		address[2]->prev = address[0];
	address[1]->prev = address[3];
	address[1]->next = address[4];
	address[3]->next = address[1];
	if (address[4])
	{
		address[4]->prev = address[1];
		address[4]->next = address[5];
	}
}

/// @brief Push operation from stack b to stack a
/// @param dt main data struct
void	push_a(t_dt *dt)
{
	t_link	*address[6];

	if (dt->b_length == 0)
		return ;
	address[0] = dt->head_b;
	address[1] = dt->head_b->next;
	address[2] = dt->head_b->next->next;
	address[3] = dt->head_a;
	address[4] = dt->head_a->next;
	if (address[4])
		address[5] = dt->head_a->next->next;
	push(address);
	if (dt->b_length == 1)
		address[0]->prev = NULL;
	if (dt->a_length == 0)
		address[3]->prev = address[1];
	dt->a_length = dt->a_length + 1U;
	dt->b_length = dt->b_length - 1U;
	if (dt->print_flag)
		write(1, "pa\n", 3);
	dt->operations++;
}

/// @brief Push operation from stack a to stack b
/// @param dt main data struct
void	push_b(t_dt *dt)
{
	t_link	*address[6];

	if (dt->a_length == 0)
		return ;
	address[0] = dt->head_a;
	address[1] = dt->head_a->next;
	address[2] = dt->head_a->next->next;
	address[3] = dt->head_b;
	address[4] = dt->head_b->next;
	if (address[4])
		address[5] = dt->head_b->next->next;
	push(address);
	if (dt->a_length == 1)
		dt->head_a->prev = NULL;
	if (dt->b_length == 0)
		address[3]->prev = address[1];
	dt->a_length = dt->a_length - 1U;
	dt->b_length = dt->b_length + 1U;
	if (dt->print_flag)
		write(1, "pb\n", 3);
	dt->operations++;
}
