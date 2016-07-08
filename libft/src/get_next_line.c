/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 14:50:18 by eruffieu          #+#    #+#             */
/*   Updated: 2015/03/15 09:41:40 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"

static char	*ft_read(int const fd, char *end, int *r)
{
	char		*buf;
	char		*str;

	str = (char *)malloc(sizeof(char));
	buf = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
	if (!buf && !str)
		return (NULL);
	str = ft_strjoin(str, end);
	while (!ft_strchr((const char *)str, '\n') && *r != 0)
	{
		*r = read(fd, buf, BUFF_SIZE);
		if (*r == -1)
			return (NULL);
		buf[*r] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	if (*r > 1)
		*r = 1;
	return (str);
}

static char	*ft_getline(char *str)
{
	char		*s;
	int			i;

	i = 0;
	while (str[i] != 10 && str[i])
		i++;
	s = (char *)malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != 10 && str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_clear(char *str)
{
	int			i;
	int			j;
	char		*s;

	i = 0;
	j = 0;
	while (str[i] != 10 && str[i])
		i++;
	i++;
	s = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (str[i])
	{
		s[j] = str[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}

int			get_next_line(int const fd, char **line)
{
	static char	*end = "";
	int			r;
	char		*str;

	if (!line || fd < 0)
		return (-1);
	r = 1;
	if (!ft_strchr((const char *)end, '\n'))
	{
		str = (char *)malloc(sizeof(char));
		str = ft_read(fd, end, &r);
		if (str == NULL)
			return (-1);
		*line = ft_strdup(ft_getline(str));
		end = ft_strdup(ft_clear(str));
		free(str);
	}
	else
	{
		*line = ft_strdup(ft_getline(end));
		end = ft_strdup(ft_clear(end));
	}
	if (*line[0] == '\0' && r == 0)
		return (0);
	return (1);
}
