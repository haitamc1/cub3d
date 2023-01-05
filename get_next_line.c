/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:08:36 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/04 16:14:37 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_n(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}

char	*new_s(char *s)
{
	char	*cp;
	int		i;
	int		j;

	i = len_n(s) + 1;
	j = 0;
	cp = (char *)malloc((ft_strlen(s) - i + 1) * sizeof (char ));
	if (!cp)
		return (NULL);
	while (i <= ft_strlen(s))
		cp[j++] = s[i++];
	free(s);
	return (cp);
}

char	*line(char *s)
{
	return (ft_substr(s, 0, len_n(s) + 1));
}

int	boucle(int fd, int *rd, char *buff, char **s)
{
	buff = (char *)malloc((100 + 1) * sizeof(char ));
	if (!buff)
		return (0);
	while (*rd != 0 && !ft_strchr(*s, '\n'))
	{
		*rd = read(fd, buff, 100);
		if (*rd <= 0 && ft_strlen(*s) <= 0)
		{
			free(*s);
			*s = NULL;
			free(buff);
			return (0);
		}
		buff[*rd] = '\0';
		*s = ft_strjoin(*s, buff);
	}
	free (buff);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buff;
	char		*r;
	int			rd;

	rd = 1;
	if (fd < 0)
		return (0);
	r = NULL;
	if (ft_strchr(s, '\n'))
	{
		r = line(s);
		s = new_s(s);
		return (r);
	}
	buff = NULL;
	if (boucle(fd, &rd, buff, &s) == 0)
		return (NULL);
	if (ft_strchr(s, '\n') != NULL || !rd)
		r = line(s);
	s = new_s(s);
	return (r);
}
