/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:14:49 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/31 16:53:52 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static void	rotate_many(t_link *address[])
{
	address[0]->next = address[3];
	address[1]->next = address[2];
	address[2]->next = NULL;
	address[0]->prev = address[2];
	address[2]->prev = address[1];
	address[3]->prev = address[0];
}

static void	rotate_two(t_link *address[])
{
	address[0]->next = address[1];
	address[1]->next = address[2];
	address[2]->next = NULL;
	address[0]->prev = address[2];
	address[1]->prev = address[0];
	address[2]->prev = address[1];
}

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
		write(1, "ra\n", 3);
}

void	rotate_b(t_dt *dt)
{
	t_link	*address[4];

	if (dt->b_length == 1)
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
		write(1, "rb\n", 3);
		dt->ab_flag = 0;
	}
}

void	rotate_ab(t_dt *dt)
{
	dt->ab_flag = 1;
	rotate_a(dt);
	rotate_b(dt);
	write(1, "rr\n", 3);
}
