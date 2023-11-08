/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:53:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/08 17:51:31 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"


void	min_index(t_dt *dt,	t_link *head, int range, char max_flag)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	min_index;
	char			back_flag;

	if (!head)
		error(dt);
	back_flag = 0;
	limit = range;
	if (head == dt->head_a)
	{
		if (range == 0)
			limit = dt->a_length;
		else
		{
			limit = range;
			back_flag = 1;
		}
		temp = dt->head_a->next;
	}
	else if (head == dt->head_b)
	{
		if (range == 0)
			limit = dt->b_length;
		else
		{
			limit = range;
			back_flag = 1;
		}
		temp = dt->head_b->next;
	}
	if (!max_flag)
		min_index = 4294967295;
	else
		min_index = 0;
	while (limit && temp)
	{
		if (!max_flag)
		{
			if (temp->index < min_index && limit)
				min_index = temp->index;
		}
		else
		{
			if (temp->index > min_index && limit)
				min_index = temp->index;
		}
		temp = temp->next;
		limit--;
	}
	dt->min_index = min_index;
	if (back_flag)
	{
		limit = range;
		temp = head->prev;
		while (limit && temp != head)
		{
			if (temp->index < min_index && limit)
				min_index = temp->index;
			temp = temp->prev;
			limit--;
		}
		dt->min_index = min_index;
	}
}


/*Find place of minimal index in the stack a*/
unsigned int	find_min_index(t_dt *dt, t_link *head, int range)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	i;

	if (!head)
		error(dt);
	limit = range;
	if (head == dt->head_a)
	{
		temp = dt->head_a->next;
		if (range == 0)
			limit = dt->a_length;
		else
			limit = range;
	}
	else if (head == dt->head_b)
	{
		temp = dt->head_b->next;
		if (range == 0)
			limit = dt->b_length;
		else
			limit = range;
	}
	i = 0;
	while (limit)
	{
		if (temp->index == dt->min_index && limit)
			return (i);
		temp = temp->next;
		i++;
		limit--;
	}
	return (4294967295);
}

/*Find place of minimal index in the stack a from back*/
unsigned int	find_min_index_rev(t_dt *dt, t_link *head, int range)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	i;

	if (!head)
		error(dt);
	limit = range;
	if(head == dt->head_a)
	{
		temp = dt->head_a->prev;
		if (range == 0)
			limit = dt->a_length;
		else
			limit = range;
	}
	else if (head == dt->head_b)
	{
		temp = dt->head_b->prev;
		if (range == 0)
			limit = dt->b_length;
		else
			limit = range;
	}
	i = 1;
	while (limit)
	{
		if (temp->index == dt->min_index && limit)
			return (i);
		temp = temp->prev;
		i++;
		limit--;
	}
	return (4294967295);
}

void	sort_to_b(t_dt *dt)
{
	unsigned int	forward_pos;
	unsigned int	backward_pos;

	forward_pos = 4294967295;
	backward_pos = 4294967295;
	while (dt->a_length)
	{
		min_index(dt, dt->head_a, 0, 0);
		forward_pos = find_min_index(dt, dt->head_a, 0);
		backward_pos = find_min_index_rev(dt, dt->head_a, 0);
		if (forward_pos == backward_pos)
			backward_pos = 4294967295;
//		printf("forward_pos: %u\nbackward_pos: %u\n", forward_pos, backward_pos);
		if ((forward_pos < backward_pos) && (dt->head_a->next->index != dt->min_index))
		{
			while (forward_pos)
			{
				rotate_a(dt);
				forward_pos--;
			}
		}
		else if ((backward_pos < forward_pos) && (dt->head_a->next->index != dt->min_index))
		{
			while (backward_pos)
			{
				rev_rotate_a(dt);
				backward_pos--;
			}
		}
//		printf("index to move to b: %u\n", dt->head_a->next->index);
		push_b(dt);
	}
//	if (dt->head_a->next->index > dt->head_a->next->next->index)
//		swap_a(dt);
	while (dt->b_length)
		push_a(dt);
}

void	sort_to_buckets(t_dt *dt, int range, int test_run)
{
	unsigned int	forward_pos;
	unsigned int	backward_pos;
	int				temp_range;
	int				temp_print_flag;

	forward_pos = 4294967295;
	backward_pos = 4294967295;
	temp_range = range;
	temp_print_flag = dt->print_flag;
	if (test_run)
		dt->print_flag = 0;
	while (temp_range && dt->a_length)
	{
		min_index(dt, dt->head_a, temp_range, 0);
		forward_pos = find_min_index(dt, dt->head_a, temp_range);
		backward_pos = find_min_index_rev(dt, dt->head_a, temp_range);
		if (forward_pos == backward_pos)
			backward_pos = 4294967295;
		if ((forward_pos < backward_pos) && (dt->head_a->next->index != dt->min_index))
		{
			while (forward_pos)
			{
				rotate_a(dt);
				forward_pos--;
			}
		}
		else if ((backward_pos < forward_pos) && (dt->head_a->next->index != dt->min_index))
		{
			while (backward_pos)
			{
				rev_rotate_a(dt);
				backward_pos--;
			}
		}
		push_b(dt);
		temp_range--;
	}
	if (test_run)
		dt->print_flag = temp_print_flag;
}

void	merge_and_sort_to_a(t_dt *dt, int test_run)
{
	unsigned int	forward_pos;
	unsigned int	backward_pos;
	int				temp_print_flag;

	forward_pos = 4294967295;
	backward_pos = 4294967295;
	temp_print_flag = dt->print_flag;
	if (test_run)
		dt->print_flag = 0;
	while (dt->b_length)
	{
		min_index(dt, dt->head_b, 0, 1);
		forward_pos = find_min_index(dt, dt->head_b, 0);
		backward_pos = find_min_index_rev(dt, dt->head_b, 0);
		if (forward_pos == backward_pos)
			backward_pos = 4294967295;
//		printf("forward_pos: %u\nbackward_pos: %u\n", forward_pos, backward_pos);
		if ((forward_pos < backward_pos) && (dt->head_b->next->index != dt->min_index))
		{
			while (forward_pos)
			{
				rotate_b(dt);
				forward_pos--;
			}
		}
		else if ((backward_pos < forward_pos) && (dt->head_b->next->index != dt->min_index))
		{
			while (backward_pos)
			{
				rev_rotate_b(dt);
				backward_pos--;
			}
		}
//		printf("index to move to b: %u\n", dt->head_a->next->index);
		push_a(dt);
	}
//	if (dt->head_a->next->index > dt->head_a->next->next->index)
//		swap_a(dt);
	if (test_run)
		dt->print_flag = temp_print_flag;
}

unsigned int	min_range(t_dt *dt, unsigned int *range_operations)
{
	unsigned int	min_operations;
	unsigned int	range;



	range = dt->a_length / 2U;
	min_operations = 4294967295;
	while (range >= 2)
	{
		if (range_operations[range] < min_operations)
			min_operations = range_operations[range];
		range--;
	}
	range = dt->a_length / 2U;
	while ((range_operations[range] != min_operations) && range)
		range--;
	return (range);
}

unsigned int	find_best_range(t_dt *dt)
{
	unsigned int	*range_operations;
	unsigned int	range;

	range = dt->a_length / 2;
	range_operations = malloc(sizeof(unsigned int) * range);
	while (range > 1)
	{
		sort_to_buckets(dt, range, 1);
		merge_and_sort_to_a(dt, 1);
		range_operations[range] = dt->operations;
//		printf("operations: %u\n",dt->operations);
		dt->operations = 0;
		range--;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
	}
	range = min_range(dt, range_operations);
	free(range_operations);
//	printf("range: %i\n", range);
	return (range);
}

void	better_sort(t_dt *dt)
{
	int	range;
	range = find_best_range(dt);
	while (dt->a_length)
		sort_to_buckets(dt, range, 0);
	merge_and_sort_to_a(dt, 0);
}

/*Dev function to check if stacks are sorted*/
void	check_sort(t_dt *dt)
{
	t_link	*current_a;
	t_link	*current_b;

	if (dt->head_a->next)
	{
		current_a = dt->head_a->next;
		while (current_a->next)
		{
			if (current_a->index > current_a->next->index)
			{
				dt->a_sorted_flag = 0;
				break ;
			}
			else
				dt->a_sorted_flag = 1;
			current_a = current_a->next;
		}
	}
	if (dt->head_b->next)
	{
		current_b = dt->head_b->next;
		while (current_b->next)
		{
			if (current_b->index > current_b->next->index)
			{
				dt->b_sorted_flag = 0;
				break ;
			}
			else
				dt->b_sorted_flag = 1;
			current_b = current_b->next;
		}
	}
	/*
	if (!dt->a_sorted_flag && dt->a_length != 1)
		printf("Stack a not sorted :(\n");
	else
		printf("Stack a sorted :)\n");
	if (!dt->b_sorted_flag)
		printf("Stack b not sorted :(\n");
	else
		printf("Stack b sorted :)\n");
	*/
}

/*Function to sort stack with only two elelemnts*/
void	sort_two(t_dt *dt)
{
	if (dt->head_a->next->index > dt->head_a->prev->index)
		swap_a(dt);
}

void	bubble_iteration(t_dt *dt)
{
	unsigned int	i;

	i = dt->a_length;
	while (i)
	{
		if (dt->head_a->next->next->index < dt->head_a->next->index && i > 1)
			swap_a(dt);
		rotate_a(dt);
		i--;
	}
}

void	bubble(t_dt *dt)
{
	while (!dt->a_sorted_flag)
	{
		bubble_iteration(dt);
		check_sort(dt);
	}
}

/*prototype*/
void	find_best_algorithm(t_dt *dt)
{
	if (dt->a_length > 2)
	{
		bubble(dt);
		dt->min_operations = dt->operations;
//		printf("bubble sort operations: %i\n", dt->operations);
		dt->operations = 0;
		dt->alg_flag = 1;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag =0;
	}
	if (dt->a_length > 4)
	{
		simple_sort(dt);
		if (dt->operations < dt->min_operations)
		{
			dt->min_operations = dt->operations;
			dt->alg_flag = 2;
		}
//		printf("simple sort operations: %i\n", dt->operations);
		dt->operations = 0;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag =0;
	}
	if (dt->a_length >= 10)
	{
		better_sort(dt);
//		printf("better sort operations: %i\n", dt->operations);
		if (dt->operations < dt->min_operations)
			dt->alg_flag = 3;
		dt->operations = 0;
		list_free(dt->head_a, dt);
		duplicate_list_c_to_a(dt);
		dt->a_sorted_flag =0;
	}
	dt->print_flag = 1;
//	printf("algorithm cosen: %i\n", dt->alg_flag);
}

void	simple_sort(t_dt *dt)
{
	sort_to_b(dt);
}

/*Main sorting function, decides what should be done*/
void	sort(t_dt *dt)
{
	find_best_algorithm(dt);
	if (dt->a_length == 1)
		return ;
	else if (dt->a_length == 2)
		sort_two(dt);
	else if (dt->a_length == 3)
		bubble(dt);
	else
	{
		if (dt->alg_flag == 1)
			bubble(dt);
		else if (dt->alg_flag == 2)
			simple_sort(dt);
		else if (dt->alg_flag == 3)
			better_sort(dt);
	}
}