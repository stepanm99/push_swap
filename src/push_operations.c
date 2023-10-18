/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:14:09 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/18 22:07:18 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	push_a(t_dt *dt)
{
	if (dt->b_length == 0)
		return ;
	write(1, "pa\n", 3);
}

void	push_b(t_dt *dt)
{
	if (dt->a_length == 0)
		return ;
	write(1, "pb\n", 2);
}