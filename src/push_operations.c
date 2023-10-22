/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:14:09 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/22 20:51:29 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

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
	dt->a_length = dt->a_length + 1U;
	dt->b_length = dt->b_length - 1U;
	write(1, "pa\n", 3);
}

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
	dt->a_length = dt->a_length - 1U;
	dt->b_length = dt->b_length + 1U;
	write(1, "pb\n", 3);
}
