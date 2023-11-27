/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:03:38 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/27 16:22:22 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief Converts array of numerical characters to integer
/// @param str input array of numerical characters
/// @return type int number
static int	ft_atoi(const char *str)
{
	size_t	i;
	int		negflag;
	int		n;

	i = 0;
	n = 0;
	negflag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			negflag = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * negflag);
}

/// @brief Checks if the string contains only numerical characters
/// @param arg string to check
/// @param dt main data struct; is passed to error() in case of error
static void	arg_check(const char *arg, t_dt *dt)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] > '9' || arg[i] < '0') && arg[i] != '-')
			error(dt);
		i++;
	}
}

/// @brief Checks if the number overflows 32-bit integer
/// @param arg argument to check
/// @param dt main data struct
static void	int_min_max_check(const char *arg, t_dt *dt)
{
	long	number;
	int		arg_length;

	arg_length = 0;
	number = ft_atol(arg);
	while (arg[arg_length])
		arg_length++;
	if (arg_length > 12)
		error(dt);
	if ((INT32_MIN > number) || (number > INT32_MAX))
		error(dt);
}

/// @brief Checks if the new_val already is in the stack
/// @param new_val new valued to be saved to the stack
/// @param dt main data struct
static void	duplicate_check(int new_val, t_dt *dt)
{
	t_link	*temp;

	if (dt->head_a->next)
		temp = dt->head_a->next;
	else
		return ;
	while (temp)
	{
		if (temp->val == new_val)
			error(dt);
		temp = temp->next;
	}
}

/// @brief Parses and checks program argument ans saves the data to stack a
/// @param argv array of arguments
/// @param dt main data struct
void	arg_pars(const char *argv[], t_dt *dt)
{
	int	i;

	i = 1;
	if (argv[i])
	{
		while (argv[i])
		{
			int_min_max_check(argv[i], dt);
			arg_check(argv[i], dt);
			duplicate_check(ft_atoi(argv[i]), dt);
			dt->a = list_add_link_a(ft_atoi(argv[i]), 0, dt);
			i++;
		}
	}
}
