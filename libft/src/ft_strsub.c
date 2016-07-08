/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 03:08:26 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/13 16:58:52 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*new;

	if (!str || !(new = ft_strnew(len)))
		return (NULL);
	ft_strncpy(new, str + start, len);
	return (new);
}
