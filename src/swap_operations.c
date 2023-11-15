/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:14:25 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/14 18:27:05 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static void	swap_two(t_link *address[])
{
	address[0]->next = address[2];
	address[1]->next = NULL;
	address[2]->next = address[1];
	address[0]->prev = address[1];
	address[1]->prev = address[2];
	address[2]->prev = address[0];
}

void	swap_a(t_dt *dt)
{
	t_link	*address[4];

	if (dt->a_length == 1)
		return ;
	address[0] = dt->head_a;
	address[1] = dt->head_a->next;
	address[2] = dt->head_a->next->next;
	if (dt->a_length == 2)
	{
		swap_two(address);
		return ;
	}
	address[3] = dt->head_a->next->next->next;
	address[0]->next = address[2];
	address[1]->next = address[3];
	address[2]->next = address[1];
	address[1]->prev = address[2];
	address[2]->prev = address[0];
	address[3]->prev = address[1];
	if (!dt->ab_flag && dt->print_flag)
	{
		if (dt->print_flag)
			write(1, "sa\n", 3);
		dt->operations++;
	}
}

void	swap_b(t_dt *dt)
{
	t_link	*address[4];

	if (dt->b_length < 2)
		return ;
	address[0] = dt->head_b;
	address[1] = dt->head_b->next;
	address[2] = dt->head_b->next->next;
	if (dt->b_length == 2)
		return (swap_two(address));
	address[3] = dt->head_b->next->next->next;
	address[0]->next = address[2];
	address[1]->next = address[3];
	address[2]->next = address[1];
	address[1]->prev = address[2];
	address[2]->prev = address[0];
	address[3]->prev = address[1];
	if (!dt->ab_flag)
	{
		if (dt->print_flag)
			write(1, "sb\n", 3);
		dt->operations++;
	}
	dt->ab_flag = 0;
}

void	swap_ab(t_dt *dt)
{
	dt->ab_flag = 1;
	swap_a(dt);
	swap_b(dt);
	if (dt->print_flag)
		write(1, "ss\n", 3);
	dt->operations++;
}
