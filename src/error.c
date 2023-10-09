/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:14:10 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/09 21:05:22 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	free_and_exit(t_dt *dt)
{
	if (dt->head_a)
		list_free(dt->head_a);
	if (dt->head_b)
		list_free(dt->head_b);
	data_init(dt);
}

void	error(int errno, t_dt *dt)
{
	if (errno == 0)
		printf("Malloc error\n");
	else
		printf("Unknown error\n");
	free_and_exit(dt);
}