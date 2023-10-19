/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:22:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/19 22:25:41 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	rotate_three_a(t_dt *dt)
{
	t_link	*address[4];

	address[0] = dt->head_a;
	address[1] = dt->head_a->next;
	address[2] = dt->head_a->next->next;
	address[3] = dt->head_a->next->next->next;
	address[0]->next = address[2];
	address[1]->next = NULL;
	address[2]->next = address[3];
	address[3]->next = address[1];
	address[0]->prev = address[1];
	address[1]->prev = address[3];
	address[2]->prev = address[0];
	address[3]->prev = address[2];
}

void	rotate_three_b(t_dt *dt)
{
	t_link	*address[4];

	address[0] = dt->head_b;
	address[1] = dt->head_b->next;
	address[2] = dt->head_b->next->next;
	address[3] = dt->head_b->next->next->next;
	address[0]->next = address[2];
	address[1]->next = NULL;
	address[2]->next = address[3];
	address[3]->next = address[1];
	address[0]->prev = address[1];
	address[1]->prev = address[3];
	address[2]->prev = address[0];
	address[3]->prev = address[2];
}
