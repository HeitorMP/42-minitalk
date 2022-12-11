/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:28 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/11/21 18:04:26 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/**********************
	LIBS
**********************/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/**********************
 FUNCTIONS PROTOTYPES
**********************/

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*get_line(char *str);
char	*get_rest(char *str);
char	*get_buffer(char *str, int fd);

#endif
