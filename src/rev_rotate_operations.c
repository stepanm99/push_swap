/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:20:47 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/18 22:00:33 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	rev_rotate_a(t_dt *dt)
{
	dt->a_length = dt->a_length;
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_dt *dt)
{
	dt->a_length = dt->a_length;
	write(1, "rrb\n", 4);
}

void	rev_rotate_ab(t_dt *dt)
{
	dt->a_length = dt->a_length;
	write(1, "rrr\n", 4);
}
