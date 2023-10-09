/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:14:46 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/09 21:38:05 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Frees entire list from head*/
void	list_free(t_link *head)
{
	printf("%p\n", head);
}

/*Adds next link to the link and returns address of the new link*/
t_link	*list_add_link(t_link *link, int val)
{
	printf("%p\n", link);
	printf("%i\n", val);
	return (link);
}

/*Initializes list a and list b*/
void	list_init(t_dt *dt)
{
	if (!dt->a)
		dt->a = malloc(sizeof(t_link));
	if (!dt->a)
		error(0, dt);
	
}
