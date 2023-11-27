/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:19:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/11/27 20:20:55 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static size_t	wordc(const char *s, char c)
{
	int		wflag;
	size_t	wc;

	wc = 0;
	wflag = 0;
	while (*s)
	{
		if (*s == c)
			wflag = 0;
		else if (wflag == 0)
		{
			wflag = 1;
			wc++;
		}
		s++;
	}
	return (wc);
}

static size_t	wordlen(const char *s, char c)
{
	size_t	l;

	l = 0;
	while (*s && *s != c)
	{
		l++;
		s++;
	}
	return (l);
}

static int	memfreek(char **ret, size_t i)
{
	while (i > 0)
	{
		i--;
		free(ret[i]);
	}
	free(ret);
	return (0);
}

static int	dumpitintoit(char **ret, const char *s, char c)
{
	size_t	i;
	size_t	l;

	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
		}
		else
		{
			l = wordlen(s, c);
			ret[i] = malloc((l + 1) * (sizeof(char)));
			if (ret[i] == NULL)
				return (memfreek(ret, i));
			ft_memcpy(ret[i], (char *)s, l);
			ret[i][l] = '\0';
			s += l;
			i++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	wc;
	char	**ret;

	wc = wordc(s, c);
	ret = malloc((wc + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	if (dumpitintoit(ret, s, c))
	{
		ret[wc] = NULL;
		return (ret);
	}
	return (NULL);
}
