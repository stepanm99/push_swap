/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:53:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/30 17:48:50 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

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

static void	sort_two(t_dt *dt)
{
	if (dt->head_a->next->index > dt->head_a->prev->index)
		swap_a(dt);
}

static void	sort_three(t_dt *dt)
{
	dt->a_length = dt->a_length;
}

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
//	rotate_a(dt);
}

/*
NOT WORKING!!!
static void	bubble_sort(t_dt *dt)
{
	unsigned int	limit;
	int				i;

	i = 0;
	while (!dt->a_sorted_flag && i < 10)
	{
		limit = dt->a_length;
		while (limit != 0)
		{
			if (dt->head_a->next->index < dt->head_a->next->next->index)
			{
				swap_a(dt);
				rotate_a(dt);
				rotate_a(dt);
				limit--;
			}
			else
				rotate_a(dt);
			limit--;
			i++;
			printf("%u\n", limit);
		}
		printf("%u %i\n", limit, i);
		check_sort(dt);
	}
}
*/

/*
OLD

static void	stalin_sort(t_dt *dt)
{
	unsigned int	limit;
	unsigned int	max_index;

	limit = dt->a_length;
	max_index = dt->head_a->next->index;
	while (limit)
	{
		if (dt->head_a->next->index < max_index)
		{
			max_index = dt->head_a->next->index;
			push_b(dt);
		}
		else
		{
			max_index = dt->head_a->next->index;
			rotate_a(dt);
		}
		limit--;
	}
	rotate_a(dt);
}*/

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
		stalin_sort(dt);
	}
	check_sort(dt);
}