/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:25:48 by hchahid           #+#    #+#             */
/*   Updated: 2022/01/21 04:19:31 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

//	Debug
//void	ft_putstr(char *str);
//void	ft_putchar(char c);
// ENd of debug

char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
int		boucle(int fd, int *rd, char *buff, char **s);
char	*line(char *s);
char	*new_s(char *s);
int		len_n(char *s);

#endif
