/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/27 00:29:11 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

/// @brief 
/// @param dt 
/// @return 
int	find_min_val(t_dt *dt)
{
	t_link	*temp;
	int		min_val;

	temp = dt->head_a->next;
	min_val = INT_MAX;
	while (temp)
	{
		if (temp->val < min_val && !temp->index)
			min_val = temp->val;
		temp = temp->next;
	}
	return (min_val);
}

/*Checks the values of the list and indexes them with unsigned integer
	called by:	main()
	calls:		find_min_val()
*/

/// @brief 
/// @param dt 
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

int	main(int argc, const char *argv[])
{
	t_dt	*dt;

	dt = NULL;
	if (argc == 1)
		return (0);
	dt = malloc(sizeof(t_dt));
	if (!dt)
		return (-1);
	data_init(dt);
	arg_pars(argv, dt);
	indexer(dt);
	duplicate_list_a_to_c(dt);
	sort(dt);
	free_data(dt);
	return (0);
}
