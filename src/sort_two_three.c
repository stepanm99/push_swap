/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:43:53 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 19:57:40 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Function to sort stack with only two elelemnts*/
void	sort_two(t_dt *dt)
{
	if (dt->head_a->next->val > dt->head_a->prev->val)
		write(1, "sa\n", 3);
}

void	sort_three(t_dt *dt)
{
	if (dt->head_a->next->index == 1 && dt->head_a->prev->index == 2)
		write(1, "ra\nsa\nrra\n", 10);
	else if (dt->head_a->next->index == 2 && dt->head_a->prev->index == 3)
		write(1, "sa\n", 3);
	else if (dt->head_a->next->index == 2 && dt->head_a->prev->index == 1)
		write(1, "rra\n", 4);
	else if (dt->head_a->next->index == 3 && dt->head_a->prev->index == 2)
		write(1, "ra\n", 3);
	else if (dt->head_a->next->index == 3 && dt->head_a->prev->index == 1)
		write(1, "sa\nrra\n", 7);
}

/*
123	nothing
132	ra sa rra *
213 sa *
231 rra *
312	ra *
321	sa rra <
*/