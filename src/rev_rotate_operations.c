/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:20:47 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/05 00:53:53 by stepan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static void	rev_rotate_many(t_link *address[])
{
	address[0]->next = address[2];
	address[1]->next = NULL;
	address[2]->next = address[3];
	address[0]->prev = address[1];
	address[2]->prev = address[0];
	address[3]->prev = address[2];
}

static void	rev_rotate_two(t_link *address[])
{
	address[0]->next = address[2];
	address[1]->next = NULL;
	address[2]->next = address[1];
	address[0]->prev = address[1];
	address[1]->prev = address[2];
	address[2]->prev = address[0];
}

void	rev_rotate_a(t_dt *dt)
{
	t_link	*address[4];

	if (dt->a_length <= 1)
		return ;
	address[0] = dt->head_a;
	address[1] = dt->head_a->prev->prev;
	address[2] = dt->head_a->prev;
	address[3] = dt->head_a->next;
	if (dt->a_length > 3)
		rev_rotate_many(address);
	else if (dt->a_length == 3)
		rev_rotate_three_a(dt);
	else
		rev_rotate_two(address);
	if (!dt->ab_flag)
	{
		if (dt->print_flag)
			write(1, "rra\n", 4);
		dt->operations++;
	}
}

void	rev_rotate_b(t_dt *dt)
{
	t_link	*address[4];

	if (dt->b_length <= 1)
		return ;
	address[0] = dt->head_b;
	address[1] = dt->head_b->prev->prev;
	address[2] = dt->head_b->prev;
	address[3] = dt->head_b->next;
	if (dt->b_length > 3)
		rev_rotate_many(address);
	else if (dt->b_length == 3)
		rev_rotate_three_b(dt);
	else
		rev_rotate_two(address);
	if (!dt->ab_flag)
	{
		if (dt->print_flag)
			write(1, "rrb\n", 4);
		dt->operations++;
	}
	dt->ab_flag = 0;
}

void	rev_rotate_ab(t_dt *dt)
{
	dt->ab_flag = 1;
	rev_rotate_a(dt);
	rev_rotate_b(dt);
	if (dt->print_flag)
		write(1, "rrr\n", 4);
	dt->operations++;
}
