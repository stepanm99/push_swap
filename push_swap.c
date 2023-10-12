/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/12 21:09:53 by smelicha         ###   ########.fr       */
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
	t_link	*temp_a;
	t_link	*temp_b;

	// dt->a = NULL;
	// dt->head_a = NULL;
	// dt->b = NULL;
	// dt->head_b = NULL;
	temp_a = (t_link*) malloc(sizeof(t_link));
	temp_a->next = NULL;
	temp_a->prev = NULL;
	if (!temp_a)
		error(dt);
	temp_b = (t_link*) malloc(sizeof(t_link));
	temp_b->next = NULL;
	temp_b->prev = NULL;
	if (!temp_b)
		error(dt);
	// temp_a = dt->a;
	// temp_b = dt->b;
	
	temp_a->index = 0;
	temp_b->index = 0;
	temp_a->val = 0;
	temp_b->val = 0;
	dt->a = temp_a;
	dt->b = temp_b;
	dt->head_a = temp_a;
	dt->head_b = temp_b;
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

	dt = NULL;
	printf("%i\n", argc);
	dt = malloc(sizeof(dt));
	if (!dt)
		return (-1);
	data_init(dt);
	arg_pars(argv, dt);
	print_stack_a(dt);
	free_data(dt);
//	check_leaks();
	return (0);
}
