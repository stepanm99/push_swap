/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/11 14:56:28 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

/*Dev test function to print both stacks and their values*/
void	print_stacks(t_dt *dt)
{
	t_link	*a_temp;
	t_link	*b_temp;

	a_temp = dt->head_a->next;
	b_temp = dt->head_b->next;
	while (a_temp != dt->head_a)
	{
		printf("a:\t%i\tindex:\t%ib:\t%i\tindex:\t%i\n", a_temp->val, a_temp->index, b_temp->val, b_temp->index);
		a_temp = a_temp->next;
		b_temp = b_temp->next;
	}
}

/*Initialization of main data struct*/
void	data_init(t_dt *dt)
{
	dt->a = NULL;
	dt->head_a = NULL;
	dt->b = NULL;
	dt->head_b = NULL;
}

int	main(int argc, const char *argv[])
{
	t_dt	*dt;

	printf("%i\n", argc);
	dt = malloc(sizeof(dt));
	if (!dt)
		return (-1);
	data_init(dt);
	list_init(0, dt);
	arg_pars(argv, dt);
	print_stacks(dt);
	return (0);
}
