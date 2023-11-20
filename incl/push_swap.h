/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/20 18:02:08 by smelicha         ###   ########.fr       */
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
	int					cost;
	unsigned int		index;
};

typedef struct s_sort_data {
	int	min_cost_dist;
	int	min_cost_dist_rev;
	int	sim_rot;
	int	sim_rev_rot;
	int	b_max_val;
	int	b_min_val;
	int	b_rot;
	int	b_rev_rot;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_sort_data;

/*
alg_flag:
	1: bubble
	2: sort to b and push to a
	3: "bucket" sort
	4: best sort
*/
typedef struct dt {
	unsigned int	a_length;		//0
	unsigned int	b_length;		//0
	unsigned int	c_length;		//0
	unsigned int	min_index;		//0
	unsigned int	operations;		//0
	unsigned int	min_operations;	//0
	int				stack_div;		//1
	int			ab_flag;		//0
	int			a_sorted_flag;	//0
	int			b_sorted_flag;	//0
	int			alg_flag;		//0
	int			print_flag;		//0
	t_link			*head_a;
	t_link			*a;
	t_link			*head_b;
	t_link			*b;
	t_link			*head_c;
	t_link			*c;
	t_sort_data		sort_data;
}	t_dt;

/*Data initialization*/

void			data_init(t_dt *dt);
void			free_data(t_dt *dt);

/*List manipulating functions*/

void			list_free(t_link *head, t_dt *dt);
t_link			*list_add_link_a(int val, unsigned int index, t_dt *dt);
void			duplicate_list_a_to_c(t_dt	*dt);
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

/*Sorting functions*/

void			sort(t_dt *dt);
void			min_index(t_dt *dt,	t_link *head, int range, char max_flag);
unsigned int	find_min_index(t_dt *dt, t_link *head, int range);
unsigned int	find_min_index_rev(t_dt *dt, t_link *head, int range);
void			sort_to_buckets(t_dt *dt, int range, int test_run);
void			merge_and_sort_to_a(t_dt *dt, int test_run);
void			better_sort(t_dt *dt);
void			check_sort(t_dt *dt);
void			sort_two(t_dt *dt);
void			bubble_iteration(t_dt *dt);
void			bubble(t_dt *dt);
void			find_best_algorithm(t_dt *dt);
void			sort_to_b(t_dt *dt);
void			best_sort(t_dt *dt);

/*Best sort utils*/

int				max_value(t_link *head);
int				min_value(t_link *head);
int				find_value(t_link *head, int val, t_dt *dt);
int				find_space(t_link *head, int val, t_dt *dt);
void			null_cost_stack(t_link *head);
void			null_cost(t_dt *dt);
void			calculate_cost(t_dt *dt);
void			rotation_cost(t_dt *dt);
void			b_rotation_cost(int a_val, t_dt *dt);
void			b_rotation_max(t_dt *dt);
void			b_rotation_min(t_dt *dt);
void			b_rotation_middle(int val, t_dt *dt);


/*Error functions*/

void	error(t_dt *dt);

#endif