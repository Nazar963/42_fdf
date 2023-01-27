/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:00:19 by naal-jen          #+#    #+#             */
/*   Updated: 2022/11/06 20:51:02 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include   <stdio.h>
# include   <stdlib.h>
# include   <stddef.h>
# include   <sys/types.h>
# include   <sys/stat.h>
# include   <fcntl.h>
# include   <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*process_str(int fd, char *buff, char *str);
char	*process_line(char *str);
char	*delete(char *str);

char	*ft_strchr1(char *s, int c);
char	*ft_strjoin1(char *str, char *buff);
size_t	ft_strlen1(char *s);

#endif