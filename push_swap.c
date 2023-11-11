/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/11 22:48:05 by stepan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

//void	check_leaks();

/*Compares two strings, if they are same, returns length of those strings,
if strings are different returns 0*/
int	ft_match(const char *str1, const char *str2)
{
	int	i;
	int	j;
	int	k;

	if (str1 == NULL || str2 == NULL)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (str1[j] != '\0')
		j++;
	while (str2[k] != '\0')
		k++;
	while ((str1[i] == str2[i]) && (str1[i] != '\0' || str2[i] != '\0'))
		i++;
	if (j == k && j == i)
		return (i);
	else
		return (0);
}

void	checksum(t_dt *dt)
{
	unsigned int	i;
	t_link	*temp;

	temp = dt->head_a->next;
	i = 1;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	printf("a_length: %u, real: %u\n", dt->a_length, i);
}

/*Dev test function to print stack elements and their neighbors in list*/
void	print_stacks_with_neigbors(t_dt *dt)
{
	t_link	*a_temp;
	t_link	*b_temp;
	t_link	*c_temp;

	printf("\nalength: %u\tblength: %u\tclength: %u\n", dt->a_length, dt->b_length, dt->c_length);
	if (dt->head_a)
	{
		a_temp = dt->head_a->next;
		while (a_temp)
		{
		if (a_temp->prev && a_temp->prev != dt->head_a)
			printf("prev val:\t%i\tindex:\t%u\n", a_temp->prev->val, a_temp->prev->index);
		else
			printf("HEAD_A\tnext val: %u\n", dt->head_a->next->val);
		printf("a:\t%i\tindex:\t%u\tcost:\t%i\n", a_temp->val, a_temp->index, a_temp->cost);
		if (a_temp->next)
			printf("next val:\t%i\tindex:\t%u\n", a_temp->next->val, a_temp->next->index);
		a_temp = a_temp->next;
		}
		printf("---------------------\n");
	}
	if (dt->head_b)
	{
		b_temp = dt->head_b->next;
		while (b_temp)
		{
		if (b_temp->prev && b_temp->prev != dt->head_b)
			printf("prev val:\t%i\tindex:\t%u\n", b_temp->prev->val, b_temp->prev->index);
		else
			printf("HEAD_B\n");
		printf("b:\t%i\tindex:\t%u\tcost:\t%i\n", b_temp->val, b_temp->index, b_temp->cost);
		if (b_temp->next)
			printf("next val:\t%i\tindex:\t%u\n", b_temp->next->val, b_temp->next->index);
		b_temp = b_temp->next;
		}
		printf("---------------------\n");
	}
	if (dt->head_c)
	{
		c_temp = dt->head_c->next;
		while (c_temp)
		{
			if (c_temp->prev && c_temp->prev != dt->head_c)
				printf("prev val:\t%i\tindex:\t%u\n", c_temp->prev->val, c_temp->prev->index);
			else
				printf("HEAD_C\n");
			printf("c:\t%i\tindex:\t%u\tcost:\t%i\n", c_temp->val, c_temp->index, c_temp->cost);
			if (c_temp->next)
				printf("next val:\t%i\tindex:\t%u\n", c_temp->next->val, c_temp->next->index);
			c_temp = c_temp->next;
		}
		printf("---------------------\n");
	}
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

/*static void	mark_links(t_dt *dt)
{
	t_link	*link;

	link = dt->head_a->next;
	link->val = -1;
	while (link->next)
	{
		link = link->next;
		link->val = 0;
	}
	link->val = -2;
}*/

int	main(int argc, const char *argv[])
{
	t_dt	*dt;
	char	input[10];		//for interactive test

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


/* interactive */
	while (1)
	{
		scanf("%s", input);
		if (ft_match(input, "x"))
			break ;
		if (ft_match(input, "sa"))
			swap_a(dt);
		if (ft_match(input, "sb"))
			swap_b(dt);
		if (ft_match(input, "ss"))
			swap_ab(dt);
		if (ft_match(input, "pa"))
			push_a(dt);
		if (ft_match(input, "pb"))
			push_b(dt);
		if (ft_match(input, "ra"))
			rotate_a(dt);
		if (ft_match(input, "rb"))
			rotate_b(dt);
		if (ft_match(input, "rr"))
			rotate_ab(dt);
		if (ft_match(input, "rra"))
			rev_rotate_a(dt);
		if (ft_match(input, "rrb"))
			rev_rotate_b(dt);
		if (ft_match(input, "rrr"))
			rev_rotate_ab(dt);
		if (ft_match(input, "pr"))
			print_stacks_with_neigbors(dt);
		if (ft_match(input, "dupc"))
			duplicate_list_a_to_c(dt);
		if (ft_match(input, "dupa"))
			duplicate_list_c_to_a(dt);
		if (ft_match(input, "fra"))
			list_free(dt->head_a, dt);
		if (ft_match(input, "frb"))
			list_free(dt->head_b, dt);
		if (ft_match(input, "frc"))
			list_free(dt->head_c, dt);
		if (ft_match(input, "pc"))
			printf("count: %u\n", dt->operations);
		if (ft_match(input, "setprint"))
			dt->print_flag = 1;
		if (ft_match(input, "usetprint"))
			dt->print_flag = 0;
		if (ft_match(input, "sort"))
			sort(dt);
		if (ft_match(input, "check"))
			check_sort(dt);
		if (ft_match(input, "better"))
		{
			sort_to_buckets(dt, 2, 0);
			merge_and_sort_to_a(dt, 0);
		}
		
	}
	sort(dt);
//	checksum(dt);
	free_data(dt);
//	check_leaks();
	return (0);
}
