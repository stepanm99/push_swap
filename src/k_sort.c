/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:29:30 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/24 17:51:49 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Returns square root in form of integer*/
int	babylonian_sqrt(int	n)
{
	int	temp;
	int	diff;
	int	guess;

	temp = 0;
	diff = 1;
	guess = n / 2;
	while (diff)
	{
		temp = guess;
		guess = (guess + (n / guess)) / 2;
		diff = guess - temp;
	}
	return (guess);
}
