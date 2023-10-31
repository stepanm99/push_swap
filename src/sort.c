/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:53:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/31 19:34:45 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"


void	min_index(t_dt *dt)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	min_index;

	temp = dt->head_a->next;
	limit = dt->a_length;
	min_index = 4294967295;
	while (temp)
	{
		if (temp->index < min_index && limit)
			min_index = temp->index;
		temp = temp->next;
		limit--;
	}
	dt->min_index = min_index;
	printf("MIN_INDEX: %u\n", min_index);
}


/*Find place of minimal index in the stack a*/
unsigned int	find_min_index(t_dt *dt)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	i;

	temp = dt->head_a->next;
	limit = dt->a_length;
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
unsigned int	find_min_index_rev(t_dt *dt)
{
	t_link			*temp;
	unsigned int	limit;
	unsigned int	i;

	temp = dt->head_a->prev;
	limit = dt->a_length;
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

static void	sort_to_b(t_dt *dt)
{
	unsigned int	forward_pos;
	unsigned int	backward_pos;

	forward_pos = 4294967295;
	backward_pos = 4294967295;
	while (dt->a_length)
	{
		min_index(dt);
		forward_pos = find_min_index(dt);
		backward_pos = find_min_index_rev(dt);
		if (forward_pos == backward_pos)
			backward_pos = 4294967295;
		printf("forward_pos: %u\nbackward_pos: %u\n", forward_pos, backward_pos);
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
		printf("index to move to b: %u\n", dt->head_a->next->index);
		push_b(dt);
	}
//	if (dt->head_a->next->index > dt->head_a->next->next->index)
//		swap_a(dt);
	while (dt->b_length)
		push_a(dt);
}

/*Dev function to check if stacks are sorted*/
static void	check_sort(t_dt *dt)
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
	if (!dt->a_sorted_flag && dt->a_length != 1)
		printf("Stack a not sorted :(\n");
	else
		printf("Stack a sorted :)\n");
	if (!dt->b_sorted_flag)
		printf("Stack b not sorted :(\n");
	else
		printf("Stack b sorted :)\n");
}

/*Function to sort stack with only two elelemnts*/
static void	sort_two(t_dt *dt)
{
	if (dt->head_a->next->index > dt->head_a->prev->index)
		swap_a(dt);
}

/*
static void	bubble(t_dt *dt)
{
	while (!dt->a_sorted_flag)
	{
		while (dt->head_a->next->index != 1)
		{
			if (dt->head_a->next->index > dt->head_a->next->next->index)
				swap_a(dt);
			rev_rotate_a(dt);
		}
		check_sort(dt);
		if (!dt->a_sorted_flag)
			rev_rotate_a(dt);
	}

}*/

/*Function to sort stack with three elements*/
static void	sort_three(t_dt *dt)
{
	dt->a_length = dt->a_length;
}
/*
static void	stalin_sort(t_dt *dt)
{
	unsigned int	max_index;
	unsigned int	limit;

	max_index = dt->head_a->next->index;
	limit = dt->a_length;
	while (limit)
	{
		if (max_index > dt->head_a->next->index)
		{
			push_b(dt);
			limit--;
		}
		else
		{
			max_index = dt->head_a->next->index;
			rotate_a(dt);
			limit--;
		}
	}
}*/

/*Main sorting function, decides what should be done*/
void	sort(t_dt *dt)
{
	if (dt->a_length == 1)
		return ;
	else if (dt->a_length == 2)
		sort_two(dt);
	else if (dt->a_length == 3)
		sort_three(dt);
	else
	{
//		stalin_sort(dt);
//		bubble(dt);
		sort_to_b(dt);
//		push_all_to_a(dt);
	}
	check_sort(dt);
}