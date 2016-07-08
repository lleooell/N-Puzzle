/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:07:10 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/05 20:22:07 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if ((dst_len = ft_strlen(dst)) >= size)
		return (size + src_len);
	ft_strncpy(dst + dst_len, src, size - dst_len - 1);
	dst[size - 1] = '\0';
	return (dst_len + src_len);
}
