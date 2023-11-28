/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/28 17:20:02 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

/// @brief Finds minimal value present in the stack a
/// @param dt main data struct
/// @return minimal value of the stack a
static int	find_min_val(t_dt *dt)
{
	t_link	*temp;
	int		min_val;

	temp = dt->head_a->next;
	min_val = INT32_MAX;
	while (temp)
	{
		if (temp->val < min_val && !temp->index)
			min_val = temp->val;
		temp = temp->next;
	}
	return (min_val);
}

/// @brief Checks the values of the list and indexes them with unsigned integer
/// @param dt main data struct
static void	indexer(t_dt *dt)
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

/// @brief Checks if the argument string contains only numbers
/// @param arg argument string
/// @param dt main data struct
void	check_single_argument(const char *arg, t_dt *dt)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] > '9' || arg[i] < '0') && (arg[i] != '-' && arg[i] != ' '))
			error(dt);
		i++;
	}
	dt->single_arg_flag = 1;
}

int	main(int argc, const char *argv[])
{
	t_dt	*dt;

	dt = NULL;
	dt = malloc(sizeof(t_dt));
	if (!dt)
		return (-1);
	data_init(dt);
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		check_single_argument(argv[1], dt);
		dt->arg = ft_split(argv[1], ' ');
	}
	if (!dt->arg)
		arg_pars(argv, dt);
	else
		arg_pars((const char **)dt->arg, dt);
	indexer(dt);
	duplicate_list_a_to_c(dt);
	sort(dt);
	free_data(dt);
	return (0);
}
