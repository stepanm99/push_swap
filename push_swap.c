/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/22 21:44:17 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

//void	check_leaks();

/*Dev test function to print stack elements and their neighbors in list*/
void	print_stacks_with_neigbors(t_dt *dt)
{
	t_link	*a_temp;
	t_link	*b_temp;

	a_temp = dt->head_a->next;
	b_temp = dt->head_b->next;
	while (a_temp)
	{
		if (a_temp->prev)
			printf("prev val:\t%i\tindex:\t%u\n", a_temp->prev->val, a_temp->prev->index);
		printf("a:\t%i\tindex:\t%u\n", a_temp->val, a_temp->index);
		if (a_temp->next)
			printf("next val:\t%i\tindex:\t%u\n", a_temp->next->val, a_temp->next->index);
		a_temp = a_temp->next;
	}
	printf("---------------------\n");
	while (b_temp)
	{
		if (b_temp->prev)
			printf("prev val:\t%i\tindex:\t%u\n", b_temp->prev->val, b_temp->prev->index);
		printf("b:\t%i\tindex:\t%u\n", b_temp->val, b_temp->index);
		if (b_temp->next)
			printf("next val:\t%i\tindex:\t%u\n", b_temp->next->val, b_temp->next->index);
		b_temp = b_temp->next;
	}
	printf("---------------------\n");
}

/*Dev test function to print both stacks and their values*/
void	print_stacks(t_dt *dt)
{
	t_link	*a_temp;
	t_link	*b_temp;

	a_temp = dt->head_a->next;
	b_temp = dt->head_b->next;
	printf("\nalength: %u\tblength: %u\n", dt->a_length, dt->b_length);
	while (a_temp)
	{
		printf("a:\t%i\tindex:\t%u\n", a_temp->val, a_temp->index);
		a_temp = a_temp->next;
	}
	printf("---------------------\n");
	while (b_temp)
	{
		printf("b:\t%i\tindex:\t%u\n", b_temp->val, b_temp->index);
		b_temp = b_temp->next;
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

/*Initialization of main data struct*/
void	data_init(t_dt *dt)
{
	dt->head_a = malloc(sizeof(t_link));
	dt->head_a->next = NULL;
	dt->head_a->prev = NULL;
	if (!dt->head_a)
		error(dt);
	dt->head_b = malloc(sizeof(t_link));
	dt->head_b->next = NULL;
	dt->head_b->prev = NULL;
	if (!dt->head_b)
		error(dt);
	dt->head_a->index = 0;
	dt->head_b->index = 0;
	dt->head_a->val = 0;
	dt->head_b->val = 0;
	dt->a = dt->head_a;
	dt->b = dt->head_b;
	dt->a_length = (unsigned int)0;
	dt->b_length = (unsigned int)0;
	dt->ab_flag = 0;
}

/*Routine to clean all allocated data*/
void	free_data(t_dt *dt)
{
	if (dt->head_a)
		list_free(dt->head_a);
	dt->head_a = NULL;
	if (dt->head_b)
		list_free(dt->head_b);
	dt->head_b = NULL;
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
	print_stacks_with_neigbors(dt);
	rev_rotate_a(dt);
	push_b(dt);
	rotate_a(dt);
	push_a(dt);
	print_stacks_with_neigbors(dt);
	free_data(dt);
//	check_leaks();
	return (0);
}
