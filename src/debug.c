/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:44:14 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/23 22:01:27 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	print_rotations(t_dt *dt)
{
	printf("ra: %i\trb: %i\trr: %i\nrra: %i\trrb: %i\trrr: %i\n", dt->sort_data.ra, dt->sort_data.rb, dt->sort_data.rr,
		dt->sort_data.rra, dt->sort_data.rrb, dt->sort_data.rrr);
}

/*For controlling if the length of final sorted a is the same as the length saved in struct*/
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
}//*/

void	interactive(t_dt *dt)
{
	char	input[10];		//for interactive test

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
		if (ft_match("rpr", input))
			reverse_print_stacks_with_neigbors(dt);
		if (ft_match("lpr", input))
			print_stacks_in_line(dt);
		if (ft_match("rotpr", input))
			print_rotations(dt);
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
		{
			check_sort(dt);
			printf("a_sorted: %i\tb_sorted: %i\n", dt->a_sorted_flag, dt->b_sorted_flag);
		}
		if (ft_match(input, "better"))
		{
			sort_to_buckets(dt, 2, 0);
			merge_and_sort_to_a(dt, 0);
		}
		if (ft_match(input, "acost"))
			rotation_cost(dt);
		if (ft_match(input, "cost"))
			calculate_cost(dt);
		if (ft_match("bestloop", input))
			best_sort_loop_to_b(dt);
	}//*/
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
		printf("a:");
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
		printf("\n");
	}
	if (dt->head_b)
	{
		b_temp = dt->head_b->next;
		printf("b:");
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
		printf("\n");
	}
	if (dt->head_c)
	{
		printf("c:");
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

void	reverse_print_stacks_with_neigbors(t_dt *dt)
{
	t_link	*a_temp;
	t_link	*b_temp;
	t_link	*c_temp;

	printf("\nalength: %u\tblength: %u\tclength: %u\n", dt->a_length, dt->b_length, dt->c_length);
	if (dt->head_a && dt->head_a->prev)
	{
		a_temp = dt->head_a->prev;
		printf("a:");
		while (a_temp != dt->head_a)
		{
		if (a_temp->prev && a_temp->prev != dt->head_a)
			printf("prev val:\t%i\tindex:\t%u\n", a_temp->prev->val, a_temp->prev->index);
		else
			printf("HEAD_A\tnext val: %u\n", dt->head_a->next->val);
		printf("a:\t%i\tindex:\t%u\tcost:\t%i\n", a_temp->val, a_temp->index, a_temp->cost);
		if (a_temp->next)
			printf("next val:\t%i\tindex:\t%u\n", a_temp->next->val, a_temp->next->index);
		a_temp = a_temp->prev;
		}
		printf("\n");
	}
	if (dt->head_b && dt->head_b->prev)
	{
		b_temp = dt->head_b->prev;
		printf("b:");
		while (b_temp != dt->head_b)
		{
		if (b_temp->prev && b_temp->prev != dt->head_b)
			printf("prev val:\t%i\tindex:\t%u\n", b_temp->prev->val, b_temp->prev->index);
		else
			printf("HEAD_B\n");
		printf("b:\t%i\tindex:\t%u\tcost:\t%i\n", b_temp->val, b_temp->index, b_temp->cost);
		if (b_temp->next)
			printf("next val:\t%i\tindex:\t%u\n", b_temp->next->val, b_temp->next->index);
		b_temp = b_temp->prev;
		}
		printf("\n");
	}
	if (dt->head_c && dt->head_c->prev)
	{
		printf("c:");
		c_temp = dt->head_c->prev;
		while (c_temp != dt->head_c)
		{
			if (c_temp->prev && c_temp->prev != dt->head_c)
				printf("prev val:\t%i\tindex:\t%u\n", c_temp->prev->val, c_temp->prev->index);
			else
				printf("HEAD_C\n");
			printf("c:\t%i\tindex:\t%u\tcost:\t%i\n", c_temp->val, c_temp->index, c_temp->cost);
			if (c_temp->next)
				printf("next val:\t%i\tindex:\t%u\n", c_temp->next->val, c_temp->next->index);
			c_temp = c_temp->prev;
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

/*Dev test function to print stack elements and their neighbors in list*/
void	print_stacks_in_line(t_dt *dt)
{
	t_link	*a_temp;
	t_link	*b_temp;
	t_link	*c_temp;


	if (dt->head_a)
	{
		a_temp = dt->head_a->next;
		printf("a:");
		while (a_temp)
		{
			printf(" %i", a_temp->val);
			a_temp = a_temp->next;
		}
		printf("\n");
	}
	if (dt->head_b)
	{
		b_temp = dt->head_b->next;
		printf("b:");
		while (b_temp)
		{
			printf(" %i", b_temp->val);
			b_temp = b_temp->next;
		}
		printf("\n");
	}
	if (dt->head_c)
	{
		printf("c:");
		c_temp = dt->head_c->next;
		while (c_temp)
		{
			printf(" %i", c_temp->val);
			c_temp = c_temp->next;
		}
		printf("\n---------------------\n");
	}
}
