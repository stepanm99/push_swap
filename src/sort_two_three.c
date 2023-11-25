/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:43:53 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 20:48:43 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Gives out instruction, if needed, to sort 2 elements stack
	called by:	sort()
*/
void	sort_two(t_dt *dt)
{
	if (dt->head_a->next->val > dt->head_a->prev->val)
		write(1, "sa\n", 3);
}

/*Gives out instructions for stack with three elements
	called by:	sort()
*/
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
