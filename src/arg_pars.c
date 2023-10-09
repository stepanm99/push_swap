/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:03:38 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/09 21:35:17 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Parses and checks program argument ans saves the data to list a*/
void	arg_pars(int argc, const char *argv[], t_dt *dt)
{
	printf("%i\n", argc);
	printf("%s\n", argv[3]);
	printf("%p\n", dt->a);
	printf("from arg pars\n");
}
