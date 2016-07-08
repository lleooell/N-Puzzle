/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:25:47 by rpuccine          #+#    #+#             */
/*   Updated: 2015/01/22 15:33:29 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_strtrimchar(char const *str, char c)
{
	size_t	start;
	size_t	end;
	char	*new;
	char	*trav;

	start = 0;
	end = 0;
	trav = (char *)str;
	while (*(trav++) == c)
		start++;
	trav = (char *)str + ft_strlen(str) - 1;
	while (*(trav--) == c)
		end++;
	if (start + end == 0)
		return (ft_strdup(str));
	if (start == ft_strlen(str))
		return (ft_strnew(0));
	if (!(new = ft_strnew(ft_strlen(str) - (start + end))))
		return (NULL);
	return (ft_strncpy(new, str + start, ft_strlen(str) - (start + end)));
}

static char	*ft_strdupchar(char **str, char c)
{
	size_t	len;
	size_t	i;
	char	*new;

	i = 0;
	len = 0;
	while ((*str)[i] != c && (*str)[i++])
		len++;
	if (!(new = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = **str;
		(*str)++;
		i++;
	}
	while (**str == c)
		(*str)++;
	return (new);
}

static void	ft_find_len(char *new, int *i, int *len, char c)
{
	while (new[*i])
	{
		if (new[*i] == c && new[*i - 1] != c)
			(*len)++;
		(*i)++;
	}
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		len;
	char	**tab;
	char	*new;
	char	*old;

	if (!s)
		return (NULL);
	i = 1;
	len = 1;
	new = ft_strtrimchar(s, c);
	old = new;
	if (!(*new))
		len = 0;
	ft_find_len(new, &i, &len, c);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		tab[i++] = ft_strdupchar(&new, c);
	free(old);
	return (tab);
}
