/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:03:38 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/12 19:26:56 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int		integer_test(const char *arg)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] > '9' || arg[i] < '0')
			flag = 1;
		i++;
	}
	return (flag);
}

void	arg_check(const char *arg, t_dt *dt)
{
	if (integer_test(arg))
		error(dt);
}

/*Parses and checks program argument ans saves the data to list a*/
void	arg_pars_to_a(const char *argv[], t_dt *dt)
{
	int		i;
	t_ldt	*ldt;
	t_list	*temp;

	temp = dt->head_a;
	i = 1;
	if (argv[i])
	{
		while (argv[i])
		{
			ldt = malloc(sizeof(int *));
			arg_check(argv[i], dt);
			ldt->index = 0;
			ldt->val = ft_atoi(argv[i]);
			temp = ft_lstnew(ldt);
			ft_lstadd_back(&dt->head_a, temp);
			temp = NULL;
			ldt = NULL;
			i++;
		}
	}
}
