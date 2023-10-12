/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/12 19:58:53 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "../incl/libft.h"

typedef struct link_data {
	int					val;
	unsigned int		index;
}	t_ldt;

typedef struct dt {
	t_list	*a;
	t_list	*head_a;
	t_list	*b;
	t_list	*head_b;
}	t_dt;

/*List functions*/

void	free_ldt(void *pointer);
void	print_val(void *pointer);

/*Argument parsing and saving to stack*/

void	arg_pars_to_a(const char *argv[], t_dt *dt);

/*Error functions*/

void	error(t_dt *dt);

#endif