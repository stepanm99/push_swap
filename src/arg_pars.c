/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:03:38 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/09 20:55:07 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	arg_pars(int argc, const char *argv[], t_dt *dt)
{
	printf("%i\n", argc);
	printf("%s\n", argv[3]);
	printf("%p\n", dt->a);
	printf("from arg pars\n");
}