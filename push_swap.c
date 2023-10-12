/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/12 18:07:47 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

//void	check_leaks();

void	data_init(t_dt *dt)
{
	dt->a = ft_lstnew(NULL);
	dt->b = ft_lstnew(NULL);
	dt->head_a = dt->a;
	dt->head_b = dt->b;
}
void	data_free(t_dt *dt)
{
	ft_lstclear(&dt->head_a, NULL);
	ft_lstclear(&dt->head_b, NULL);
	free(dt);
}

int	main(int argc, const char *argv[])
{
	t_dt	*dt;

	dt = NULL;
	printf("%i\n", argc);
	ft_putstr_fd((char *)argv[0], 1);
	dt = malloc(sizeof(dt));
	if (!dt)
		return (-1);
	data_init(dt);
//	check_leaks();
//	system("leaks push_swap");
	return (0);
}
