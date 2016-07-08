/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 04:11:13 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/11 00:04:20 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhite(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *str)
{
	size_t	start;
	size_t	end;
	char	*new;
	char	*trav;

	if (str == NULL)
		return (NULL);
	start = 0;
	end = 0;
	trav = (char *)str;
	while (ft_iswhite(*(trav++)))
		start++;
	trav = (char *)str + ft_strlen(str) - 1;
	while (ft_iswhite(*(trav--)))
		end++;
	if (start + end == 0)
		return (ft_strdup(str));
	if (start == ft_strlen(str))
		return (ft_strnew(0));
	if (!(new = ft_strnew(ft_strlen(str) - (start + end))))
		return (NULL);
	return (ft_strncpy(new, str + start, ft_strlen(str) - (start + end)));
}
