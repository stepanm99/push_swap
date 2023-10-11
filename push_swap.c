/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/11 19:48:22 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

//void	check_leaks();

/*Dev test function to print both stacks and their values*/
void	print_stack_a(t_dt *dt)
{
	t_link	*a_temp;

	a_temp = dt->head_a->next;
	while ((a_temp != dt->head_a) && a_temp)
	{
		printf("a:\t%i\tindex:\t%i\n", a_temp->val, a_temp->index);
		a_temp = a_temp->next;
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

/*Routine to clean all allocated data*/
void	free_data(t_dt *dt)
{
	if (dt->head_a)
		list_free(dt->head_a);
	if (dt->head_b)
		list_free(dt->head_b);
	printf("%p", dt);
	free(dt);
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
	print_stack_a(dt);
	free_data(dt);
//	check_leaks();
	return (0);
}
