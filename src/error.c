/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:14:10 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/12 17:58:24 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"


/*Called in case of error, shows error message and calls frees data*/
void	error(t_dt *dt)
{
	printf("Error %p\n", dt);
//	if (dt->head_a)
//		list_free(dt->head_a);
//	if (dt->head_b)
//		list_free(dt->head_b);
//	data_init(dt);
}
