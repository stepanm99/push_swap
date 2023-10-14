/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/14 22:20:50 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

//void	check_leaks();

/*Dev test function to print both stacks and their values*/
void	print_stack_a(t_dt *dt)
{
	t_link	*a_temp;

	a_temp = dt->head_a->next;
	while ((a_temp != dt->head_a) && a_temp)
	{
		printf("a:\t%i\tindex:\t%i\n", a_temp->val, a_temp->index);
		a_temp = a_temp->next;
	}
}

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

void	data_init_1(t_dt *dt)
{
	dt->a_length = 0;
	dt->b_length = 0;
}

/*Initialization of main data struct*/
void	data_init(t_dt *dt)
{
	t_link	*temp_a;
	t_link	*temp_b;

	temp_a = NULL;
	temp_b = NULL;
	temp_a = (t_link*) malloc(sizeof(t_link));
	temp_a->next = NULL;
	temp_a->prev = NULL;
	if (!temp_a)
		error(dt);
	temp_b = (t_link*) malloc(sizeof(t_link));
	temp_b->next = NULL;
	temp_b->prev = NULL;
	if (!temp_b)
		error(dt);
	temp_a->index = 0;
	temp_b->index = 0;
	temp_a->val = 0;
	temp_b->val = 0;
	dt->a = temp_a;
	dt->b = temp_b;
	dt->head_a = temp_a;
	dt->head_b = temp_b;
	data_init_1(dt);
}

/*Routine to clean all allocated data*/
void	free_data(t_dt *dt)
{
	if (dt->head_a)
		list_free(dt->head_a);
	if (dt->head_b)
		list_free(dt->head_b);
	printf("%p", dt);
	free(dt);
}

int	main(int argc, const char *argv[])
{
	t_dt	*dt;

	dt = NULL;
	printf("%i\n", argc);
	dt = malloc(sizeof(dt));
	if (!dt)
		return (-1);
	data_init(dt);
	arg_pars(argv, dt);
	indexer(dt);
	print_stack_a(dt);
	free_data(dt);
//	check_leaks();
	return (0);
}
