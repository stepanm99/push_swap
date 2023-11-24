/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:29:30 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/24 22:35:30 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Returns square root in form of integer*/
int	babylonian_sqrt(int n)
{
	int	temp;
	int	diff;
	int	guess;

	temp = 0;
	diff = 1;
	guess = n / 2;
	while (diff)
	{
		temp = guess;
		guess = (guess + (n / guess)) / 2;
		diff = guess - temp;
	}
	return (guess);
}

int	find_value_position(t_link *head, int val)
{
	t_link	*temp;
	int		i;

	i = 0;
	temp = head->next;
	while (temp->val != val)
	{
		temp = temp->next;
		i++;
	}
	return (i - 1);
}

void	push_back(t_dt *dt)
{
	int		max_b_index_pos;
	t_link	*c_temp;

	c_temp = dt->head_c->prev;
	while (dt->b_length)
	{
		while (dt->head_b->next->val != c_temp->val)
		{
			max_b_index_pos = find_value_position(dt->head_b, c_temp->val);
			if (max_b_index_pos <= ((int)dt->b_length / 2))
				rotate_b(dt);
			else
				rev_rotate_b(dt);
		}
		c_temp = c_temp->prev;
		push_a(dt);
	}
}

static void	prepare_sorted(t_dt *dt)
{
	dt->print_flag = 0;
	better_sort(dt);
	duplicate_list_a_to_b(dt);
	list_free(dt->head_a, dt);
	duplicate_list_c_to_a(dt);
	list_free(dt->head_c, dt);
	duplicate_list_b_to_c(dt);
	list_free(dt->head_b, dt);
	if (!dt->head_b)
	{
		dt->head_b = malloc(sizeof(t_link));
		if (!dt->head_b)
			error(dt);
		dt->head_b->next = NULL;
		dt->head_b->prev = NULL;
		dt->b = dt->head_b;
	}
	dt->print_flag = 1;
}

void	k_sort(t_dt *dt)
{
	int	i;
	int	range;

	i = 0;
	range = babylonian_sqrt(dt->a_length);
	prepare_sorted(dt);
	while (dt->a_length)
	{
		if ((int)dt->head_a->next->index <= i)
		{
			push_b(dt);
			rotate_b(dt);
			i++;
		}
		else if ((int)dt->head_a->next->index <= i + range)
		{
			push_b(dt);
			i++;
		}
		else
			rotate_a(dt);
	}
	push_back(dt);
}