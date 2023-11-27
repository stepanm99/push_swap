/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:12:12 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/27 21:16:55 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/// @brief Converts string into long number
/// @param str string with numerical characters to convert
/// @return converted string to number or 0 in case of error
long	ft_atol(const char *str)
{
	size_t		i;
	int			negflag;
	long		n;

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
	return (n * (long)negflag);
}

void	*ft_memcpy(void *dest, const void *src, size_t l)
{
	char		*destination;
	const char	*source;
	size_t		i;

	i = 0;
	source = src;
	destination = dest;
	if (destination == NULL && source == NULL)
		return (NULL);
	while (l > 0)
	{
		destination[i] = source[i];
		l--;
		i++;
	}
	return (dest);
}
