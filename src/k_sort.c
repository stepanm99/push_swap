/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:29:30 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/28 17:48:57 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Returns square root in form of integer*/

/// @brief Quick square root aproximation algorithm
/// @param n number for which the square root is searched
/// @return aproximate integer value of the number n
static int	babylonian_sqrt(int n)
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

/// @brief Function to find particular index in the stack
/// @param head head of the stack we search in
/// @param index index we search for
/// @return position from the top of the stack
static int	find_index_position(t_link *head, unsigned int index)
{
	t_link	*temp;
	int		i;

	i = 0;
	temp = head->next;
	while (temp->index != index)
	{
		temp = temp->next;
		i++;
	}
	return (i - 1);
}

/// @brief Routine to push values back to stack a from K shaped stack b
///		(highest values on top and bottom of b, smallest in the middle of b)
/// @param dt main data struct
static void	push_back(t_dt *dt)
{
	int				max_b_index_pos;
	unsigned int	max_index;

	max_index = dt->b_length;
	while (dt->b_length)
	{
		while (dt->head_b->next->index != max_index)
		{
			max_b_index_pos = find_index_position(dt->head_b, max_index);
			if (max_b_index_pos <= ((int)dt->b_length / 2))
				rotate_b(dt);
			else
				rev_rotate_b(dt);
		}
		max_index--;
		push_a(dt);
	}
}

/// @brief Values from stack a are pushed to be to create K shape in b and then
///		those values can be efficiently pushed and sorted back to a.
/// @param dt main data struct
void	k_sort(t_dt *dt)
{
	int	i;
	int	range;

	i = 0;
	range = babylonian_sqrt(dt->a_length) * 16 / 10;
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
