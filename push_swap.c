/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:42:03 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/12 19:24:10 by smelicha         ###   ########.fr       */
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
	if (!(t_ldt *)pointer)
		return ;
	free((t_ldt *)pointer);
}

void	data_init(t_dt *dt)
{
	dt->a = ft_lstnew(NULL);
	dt->b = ft_lstnew(NULL);
	dt->head_a = dt->a;
	dt->head_b = dt->b;
}
void	data_free(t_dt *dt)
{
	if (dt->head_a)
		ft_lstclear(&dt->head_a, &free_ldt);
	if (dt->head_b)
		ft_lstclear(&dt->head_b, &free_ldt);
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
	system("leaks push_swap");
	return (0);
}
