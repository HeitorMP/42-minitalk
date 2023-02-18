/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:05:12 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/02/18 20:43:57 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/includes/libft.h"

static void	received_from_server(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("String received!");
		exit(0);
	}
}

static void	send_kill(int pid, char *str)
{
	char	c;
	int		bits;
	size_t	i;

	bits = 0;
	i = 0;
	while (i <= ft_strlen(str))
	{
		bits = 8;
		c = str[i];
		while (bits--)
		{
			if (c >> bits & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (!pid || !argv[2])
		return (1);
	signal(SIGUSR1, received_from_server);
	send_kill(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
