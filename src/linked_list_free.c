/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:36:58 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/24 22:39:37 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	list_free_heads(t_link *head, t_dt *dt)
{
	if (dt->head_a == head)
	{
		dt->head_a = NULL;
		dt->a_length = 0;
	}
	if (dt->head_b == head)
	{
		dt->head_b = NULL;
		dt->b_length = 0;
	}
	if (dt->head_c == head)
	{
		dt->head_c = NULL;
		dt->c_length = 0;
	}
}

/*Frees entire list from head*/
void	list_free(t_link *head, t_dt *dt)
{
	t_link	*current;
	t_link	*next;

	current = NULL;
	next = NULL;
	current = head;
	while (1)
	{
		next = current->next;
		free(current);
		current = next;
		if (next == NULL)
		{
			free(current);
			break ;
		}
		next->prev = NULL;
	}
	list_free_heads(head, dt);
}
