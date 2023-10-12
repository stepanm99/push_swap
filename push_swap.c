/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/12 20:57:15 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

//void	check_leaks();

void	print_val(void *pointer)
{
	t_ldt	*ldt;

	if (!pointer)
		return ;
	ldt = pointer;
	printf("val: %i\n", ldt->val);
	printf("index: %i\n\n", ldt->index);
}

void	free_ldt(void *pointer)
{

	if (!pointer)
		return ;
	// pointer = NULL;
	free(pointer);
}

void	data_init(t_dt *dt)
{
	t_ldt	*empty;

	empty = malloc(sizeof(t_ldt));
	empty->val = 0;
	empty->index = 0;
	dt->a = ft_lstnew(empty);
	dt->b = ft_lstnew(empty);
	dt->head_a = dt->a;
	dt->head_b = dt->b;
}
void	data_free(t_dt *dt)
{
	void (*fp_free_ldt)(void *pointer);
	t_list	*head_a;
	t_list	*head_b;

	head_a = dt->head_a;
	head_b = dt->head_b;

	fp_free_ldt = &free_ldt;
	if (dt->head_a){
		ft_lstclear(&head_a, fp_free_ldt);
		//free(head_a);
		}
	if (dt->head_b)
		ft_lstclear(&head_b, fp_free_ldt);
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
	arg_pars_to_a(argv, dt);
	ft_lstiter(dt->head_a, &print_val);
	data_free(dt);
//	check_leaks();
//	system("leaks push_swap");
	return (0);
}
