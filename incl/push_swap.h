/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/18 21:33:43 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct link t_link;

struct link {
	t_link				*prev;
	t_link				*next;
	int					val;
	unsigned int		index;
};

typedef struct dt {
	unsigned int	a_length;
	unsigned int	b_length;
	t_link	*a;
	t_link	*head_a;
	t_link	*b;
	t_link	*head_b;
}	t_dt;

/*Data initialization*/

void	data_init(t_dt *dt);
void	free_data(t_dt *dt);

/*List manipulating functions*/

void	list_free(t_link *head);
t_link	*list_add_link_a(int val, t_dt *dt);
t_link	*list_add_link_b(t_link *link, int val, t_dt *dt);


/*Push, swap, rotate operations*/

void	push_a(t_dt *dt);
void	push_b(t_dt *dt);
void	swap_a(t_dt *dt);
void	swap_b(t_dt *dt);
void	swap_ab(t_dt *dt);
void	rotate_a(t_dt *dt);
void	rotate_b(t_dt *dt);
void	rotate_ab(t_dt *dt);
void	rev_rotate_a(t_dt *dt);
void	rev_rotate_b(t_dt *dt);
void	rev_rotate_ab(t_dt *dt);

/*Argument parsing and saving to stack*/

void	arg_pars(const char *argv[], t_dt *dt);

/*Error functions*/

void	error(t_dt *dt);

#endif