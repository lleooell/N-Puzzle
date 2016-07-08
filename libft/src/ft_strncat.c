/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:08:28 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/10 18:35:38 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, char const *src, size_t len)
{
	ft_bzero((void *)dst + ft_strlen(dst), len + 1);
	ft_strncpy(dst + ft_strlen(dst), src, len);
	return (dst);
}
