/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/09 21:05:37 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdlib.h>
# include<stdio.h>

typedef struct link {
	void	*prev;
	void	*next;
	int		val;
}	t_link;

typedef struct dt {
	t_link	*a;
	t_link	*head_a;
	t_link	*b;
	t_link	*head_b;
}	t_dt;


void	arg_pars(int argc, const char *argv[], t_dt *dt);
void	list_init(t_dt *dt);
void	data_init(t_dt *dt);

void	error(int errno, t_dt *dt);

#endif