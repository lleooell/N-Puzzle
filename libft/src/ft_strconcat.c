/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:14:37 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/15 21:35:50 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strconcat(char *s1, char *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(new = ft_strnew(len_s1 + len_s2)))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		new[i] = s2[i - len_s1];
		i++;
	}
	free(s1);
	return (new);
}
