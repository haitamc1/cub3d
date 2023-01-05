/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:26:37 by hchahid           #+#    #+#             */
/*   Updated: 2022/01/21 04:19:03 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	ft_putchar(char c)
// {
// 	write(1,&c,1);
// }

// void	ft_putstr(char *str)
// {
// 	int	i = 0;

// 	while(str[i])
// 		ft_putchar(str[i++]);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		l;
	int		i;
	int		j;

	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	l = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc((l + 1) * sizeof(char));
	if (!p)
		return (0);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free (s1);
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	int		i;
	int		x;

	if (!s || len == 0)
		return (0);
	x = ft_strlen(s);
	if (x < len)
		len = x;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (len-- != 0 && start < x)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
