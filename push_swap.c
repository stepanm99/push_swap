/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/09 20:50:00 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

void	data_init(t_dt *dt)
{
	dt->a = NULL;
	dt->head_a = NULL;
	dt->b = NULL;
	dt->head_b = NULL;
	printf("test\n");
}

int	main(int argc, const char *argv[])
{
	t_dt	*dt;

	dt = malloc(sizeof(dt));
	if (!dt)
		return (-1);
	data_init(dt);
	arg_pars(argc, argv, dt);
	return (0);
}