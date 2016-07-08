/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 02:44:44 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/10 20:30:34 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*add;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	if (!(add = ft_strnew(2)))
		return (NULL);
	i = 0;
	while (*s)
	{
		*add = f(i, *s);
		ft_strcat(new, add);
		s++;
		i++;
	}
	return (new);
}
