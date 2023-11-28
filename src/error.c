/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:14:10 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/28 17:18:48 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief Function called in case of error, prints Error to sdterr and
///			frees all the data
/// @param dt 
void	error(t_dt *dt)
{
	write(2, "Error\n", 6);
	free_data(dt);
	system("leaks push_swap");
	exit(-1);
}
