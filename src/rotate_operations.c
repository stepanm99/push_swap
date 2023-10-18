/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:14:49 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/19 00:21:19 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	rotate_a(t_dt *dt)
{
	t_link	*address[4];

	address[0] = dt->head_a;
	address[1] = dt->head_a->prev;
	address[2] = dt->head_a->next;
	address[3] = dt->head_a->next->next;
	address[0]->prev = address[2];
	address[0]->next = address[3];
	address[1]->next = address[2];
	address[2]->prev = address[1];
	address[2]->next = NULL;
	address[3]->prev = address[0];
	write(1, "ra\n", 3);
}

void	rotate_b(t_dt *dt)
{
	dt->a_length = dt->a_length;
	write(1, "rb\n", 3);
}

void	rotate_ab(t_dt *dt)
{
	dt->a_length = dt->a_length;
	write(1, "rr\n", 3);
}
