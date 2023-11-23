/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/23 17:04:19 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

//void	check_leaks();

/*checks if all links have index value*/
int	check_index(t_dt *dt)
{
	t_link	*temp;

	temp = dt->head_a->next;
	printf("temp: %p\n", temp);
	while (temp != dt->head_a)
	{
		if (temp->index == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/*Find minimal value in the stack a*/
int	find_min_val(t_dt *dt)
{
	t_link	*temp;
	int		min_val;

	temp = dt->head_a->next;
	min_val = 2147483647;
	while (temp)
	{
		if (temp->val < min_val && !temp->index)
			min_val = temp->val;
		temp = temp->next;
	}
	return (min_val);
}

/*Checks the values of the list and indexes them with unsigned integer*/
void	indexer(t_dt *dt)
{
	t_link			*temp;
	t_link			*min;
	int				min_val;
	unsigned int	i;

	i = 1;
	min_val = find_min_val(dt);
	min = NULL;
	while (i != (dt->a_length + 1))
	{
		temp = dt->head_a->next;
		while (temp)
		{
			if ((temp->val <= min_val) && temp->index == 0)
			{
				min_val = temp->val;
				min = temp;
			}
			temp = temp->next;
		}
		if (min)
			min->index = i;
		min_val = find_min_val(dt);
		i++;
	}
}

/*Initialization of main data struct*/
void	data_init(t_dt *dt)
{
	dt->head_a = malloc(sizeof(t_link));
	if (!dt->head_a)
		error(dt);
	dt->head_a->next = NULL;
	dt->head_a->prev = NULL;
	dt->head_b = malloc(sizeof(t_link));
	if (!dt->head_b)
		error(dt);
	dt->head_b->next = NULL;
	dt->head_b->prev = NULL;
	dt->head_c = malloc(sizeof(t_link));
	if(!dt->head_c)
		error(dt);
	dt->head_c->next = NULL;
	dt->head_c->prev = NULL;
	dt->head_a->index = 0;
	dt->head_b->index = 0;
	dt->head_c->index = 0;
	dt->head_a->val = 0;
	dt->head_b->val = 0;
	dt->head_c->val = 0;
	dt->head_a->cost = 0;
	dt->head_b->cost = 0;
	dt->head_c->cost = 0;
	dt->a = dt->head_a;
	dt->b = dt->head_b;
	dt->c = dt->head_c;
	dt->a_length = 0U;
	dt->b_length = 0U;
	dt->c_length = 0U;
	dt->ab_flag = 0;
	dt->operations = 0;
	dt->min_operations = 0;
	dt->alg_flag = 0;
	dt->print_flag = 0;
	dt->stack_div = 1;
	dt->a_sorted_flag = 0;
	dt->b_sorted_flag = 0;
	dt->min_index = 0;
}

/*Routine to clean all allocated data*/
void	free_data(t_dt *dt)
{
	if (dt->head_a)
		list_free(dt->head_a, dt);
	if (dt->head_b)
		list_free(dt->head_b, dt);
	if (dt->head_c)
		list_free(dt->head_c, dt);
	free(dt);
	dt = NULL;
}

int	main(int argc, const char *argv[])
{
	t_dt	*dt;

	dt = NULL;
	if (argc == 1)
	{
		write(2, "Error!\n", 7);
		return (-1);
	}
	dt = malloc(sizeof(t_dt));
	if (!dt)
		return (-1);
	data_init(dt);
	arg_pars(argv, dt);
	indexer(dt);
	duplicate_list_a_to_c(dt);

	interactive(dt);	//for debug purposes
	
	sort(dt);
	checksum(dt);
	free_data(dt);
//	check_leaks();
	return (0);
}
