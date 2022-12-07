/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:05:12 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/07 14:56:40 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/includes/libft.h"

static void	received_from_server(int signal)
{
	static int	received_chars;

	if (signal == SIGUSR1)
	{
		ft_printf("Bytes received at server: ");
		received_chars++;
	}
	ft_printf("%d\n", received_chars);
}

static void	send_kill(int pid, char *str)
{
	char	c;
	int		bits;
	int		i;

	bits = 0;
	i = 0;
	while (str[i] != '\0')
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
