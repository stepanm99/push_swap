/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/27 21:11:45 by smelicha         ###   ########.fr       */
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
	min_val = INT32_MAX;
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

void	free_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		arg[i] = NULL;
		i++;
	}
	free(arg);
}

int	main(int argc, const char *argv[])
{
	t_dt	*dt;
	char	**arg;

	dt = NULL;
	arg = NULL;
	dt = malloc(sizeof(t_dt));
	if (!dt)
		return (-1);
	data_init(dt);
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		check_single_argument(argv[1], dt);
		arg = ft_split(argv[1], ' ');
	}
	if (!arg)
		arg_pars(argv, dt);
	else
		arg_pars((const char**)arg, dt);
	indexer(dt);
	duplicate_list_a_to_c(dt);
	sort(dt);
	return (free_data(dt), free_arg(arg), 0);
}
