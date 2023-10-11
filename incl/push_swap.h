/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/11 14:55:44 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct link {
	void				*prev;
	void				*next;
	int					val;
	unsigned int		index;
}	t_link;

typedef struct dt {
	t_link	*a;
	t_link	*head_a;
	t_link	*b;
	t_link	*head_b;
}	t_dt;

/*Data initialization*/

void	list_init(int val, t_dt *dt);
void	data_init(t_dt *dt);

/*List manipulating functions*/

void	list_free(t_link *head);
t_link	*list_add_link_a(t_link *link, int val, t_dt *dt);
t_link	*list_add_link_b(t_link *link, int val, t_dt *dt);

/*Argument parsing and saving to stack*/
void	arg_pars(const char *argv[], t_dt *dt);

/*Error functions*/

void	error(t_dt *dt);

#endif