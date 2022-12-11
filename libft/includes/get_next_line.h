/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:28 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/11/22 10:16:43 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/**********************
	LIBS
**********************/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
/**********************
 FUNCTIONS PROTOTYPES
**********************/

char	*get_next_line(int fd);
char	*ft_strjoin_alt(char *s1, char *s2);
char	*get_line(char *str);
char	*get_rest(char *str);
char	*get_buffer(char *str, int fd);

#endif
