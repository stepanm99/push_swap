/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:03:38 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/10 16:15:27 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	arg_check(const char *arg, t_dt *dt)
{
	if (integer_test(arg))
		error(dt);
}

/*Parses and checks program argument ans saves the data to list a*/
void	arg_pars(int argc, const char *argv[], t_dt *dt)
{
	printf("argv[1]: %s\n", argv[1]);
	printf("argc: %i\n", argc);
	printf("list a: %p\n", dt->head_a);
	printf("list b: %p\n", dt->head_b);
}
