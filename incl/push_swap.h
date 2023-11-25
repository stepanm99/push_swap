/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/25 18:58:16 by smelicha         ###   ########.fr       */
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
all initialized to 0, except int stack_div = 1
alg_flag:
	1: bubble
	2: sort to b and push to a
	3: "bucket" sort
*/
typedef struct dt {
	unsigned int	a_length;
	unsigned int	b_length;
	unsigned int	c_length;
	unsigned int	min_index;
	unsigned int	operations;
	unsigned int	min_operations;
	int				stack_div;
	int				ab_flag;
	int				a_sorted_flag;
	int				b_sorted_flag;
	int				alg_flag;
	int				print_flag;
	t_link			*head_a;
	t_link			*a;
	t_link			*head_b;
	t_link			*b;
	t_link			*head_c;
	t_link			*c;
}	t_dt;

/*Data initialization*/

void			data_init(t_dt *dt);
void			free_data(t_dt *dt);

/*List manipulating functions*/

void			list_free(t_link *head, t_dt *dt);
t_link			*list_add_link_a(int val, unsigned int index, t_dt *dt);
t_link			*list_add_link_b(int val, unsigned int index, t_dt *dt);
t_link			*list_add_link_c(int val, unsigned int index, t_dt *dt);
void			duplicate_list_a_to_c(t_dt	*dt);
void			duplicate_list_a_to_b(t_dt *dt);
void			duplicate_list_b_to_c(t_dt *dt);
void			duplicate_list_c_to_a(t_dt	*dt);

/*Push, swap, rotate operations*/

void			push_a(t_dt *dt);
void			push_b(t_dt *dt);
void			swap_a(t_dt *dt);
void			swap_b(t_dt *dt);
void			swap_ab(t_dt *dt);
void			rotate_a(t_dt *dt);
void			rotate_three_a(t_dt *dt);
void			rotate_b(t_dt *dt);
void			rotate_three_b(t_dt *dt);
void			rotate_ab(t_dt *dt);
void			rev_rotate_a(t_dt *dt);
void			rev_rotate_three_a(t_dt *dt);
void			rev_rotate_b(t_dt *dt);
void			rev_rotate_three_b(t_dt *dt);
void			rev_rotate_ab(t_dt *dt);

/*Argument parsing and saving to stack*/

void	arg_pars(const char *argv[], t_dt *dt);

/*-----Sorting functions-----*/

void			sort(t_dt *dt);
void			min_index(t_dt *dt,	t_link *head, int range, char max_flag);
unsigned int	find_min_index(t_dt *dt, t_link *head, int range);
unsigned int	find_min_index_rev(t_dt *dt, t_link *head, int range);
unsigned int	find_min_index_get_limit(t_dt *dt, t_link *head, int range);
t_link			*find_min_index_get_temp(t_dt *dt, t_link *head);
void			sort_to_buckets(t_dt *dt, int range, int test_run);
void			merge_and_sort_to_a(t_dt *dt, int test_run);
void			better_sort(t_dt *dt);
unsigned int	find_best_range(t_dt *dt);
void			b_rotation(t_dt *dt, unsigned int forward_pos);
void			b_rev_rotation(t_dt *dt, unsigned int backward_pos);
void			check_sort(t_dt *dt);
void			sort_two(t_dt *dt);
void			bubble_iteration(t_dt *dt);
void			bubble(t_dt *dt);
void			find_best_algorithm(t_dt *dt);
void			simple_sort(t_dt *dt);
void			sort_to_b(t_dt *dt);

/*K sort functions*/

void			k_sort(t_dt *dt);
int				babylonian_sqrt(int	n);

/*Error functions*/

void	error(t_dt *dt);

#endif