/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnconcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:25:38 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/18 22:29:33 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnconcat(char **s1, char *s2, size_t n)
{
	char	*new;
	size_t	len_s1;
	size_t	i;

	if (!s1 || !*s1 || !s2)
		return (1);
	len_s1 = ft_strlen(*s1);
	if (n > ft_strlen(s2))
		return (1);
	if (!(new = ft_strnew(len_s1 + n)))
		return (1);
	i = 0;
	while (i < len_s1)
	{
		new[i] = (*s1)[i];
		i++;
	}
	while (i < len_s1 + n)
	{
		new[i] = s2[i - len_s1];
		i++;
	}
	free(*s1);
	*s1 = new;
	return (0);
}
