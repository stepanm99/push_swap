/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/05 19:07:54 by stepan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_link	t_link;

struct s_link {
	t_link				*prev;
	t_link				*next;
	int					val;
	unsigned int		index;
};


/*
alg_flag:
	1: bubble
	2: sort to b and push to a
	3: "bucket" sort
*/
typedef struct dt {
	unsigned int	a_length;		//0
	unsigned int	b_length;		//0
	unsigned int	c_length;		//0
	unsigned int	min_index;		//0
	unsigned int	operations;		//0
	unsigned int	min_operations;	//0
	int				stack_div;		//1
	char			ab_flag;		//0
	char			a_sorted_flag;	//0
	char			b_sorted_flag;	//0
	char			alg_flag;		//0
	char			print_flag;		//0
	t_link			*head_a;
	t_link			*a;
	t_link			*head_b;
	t_link			*b;
	t_link			*head_c;
	t_link			*c;
}	t_dt;

/*Data initialization*/

void	data_init(t_dt *dt);
void	free_data(t_dt *dt);

/*List manipulating functions*/

void	list_free(t_link *head, t_dt *dt);
t_link	*list_add_link_a(int val, unsigned int index, t_dt *dt);
void	duplicate_list_a_to_c(t_dt	*dt);
void	duplicate_list_c_to_a(t_dt	*dt);

/*Push, swap, rotate operations*/

void	push_a(t_dt *dt);
void	push_b(t_dt *dt);
void	swap_a(t_dt *dt);
void	swap_b(t_dt *dt);
void	swap_ab(t_dt *dt);
void	rotate_a(t_dt *dt);
void	rotate_three_a(t_dt *dt);
void	rotate_b(t_dt *dt);
void	rotate_three_b(t_dt *dt);
void	rotate_ab(t_dt *dt);
void	rev_rotate_a(t_dt *dt);
void	rev_rotate_three_a(t_dt *dt);
void	rev_rotate_b(t_dt *dt);
void	rev_rotate_three_b(t_dt *dt);
void	rev_rotate_ab(t_dt *dt);

/*Argument parsing and saving to stack*/

void	arg_pars(const char *argv[], t_dt *dt);

/*Sorting functions*/

void	sort(t_dt *dt);

/*Error functions*/

void	error(t_dt *dt);

#endif