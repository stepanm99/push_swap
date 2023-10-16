/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:14:10 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/16 19:24:03 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"


/*Called in case of error, shows error message and calls frees data*/
void	error(t_dt *dt)
{
	printf("Error\n");
	free_data(dt);
	exit(-1);
}
