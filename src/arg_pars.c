/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:03:38 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/16 17:02:56 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	ft_atoi(const char *str)
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

/*Check if the argument contains only digits or minus sign*/
void	arg_check(const char *arg, t_dt *dt)
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

/*Parses and checks program argument ans saves the data to list a*/
void	arg_pars(const char *argv[], t_dt *dt)
{
	int	i;

	i = 1;
	if (argv[i])
	{
		while (argv[i])
		{
			arg_check(argv[i], dt);
			dt->a = list_add_link_a(ft_atoi(argv[i]), 0, dt);
			i++;
		}
	}
}
