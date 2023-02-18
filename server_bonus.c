/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:01:39 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/02/18 22:00:44 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/includes/libft.h"

char	*join_char(char *str, char c)
{
	char	*new_str;
	int		i;
	int		size;

	i = 0;
	if (!str)
	{
		new_str = ft_calloc(sizeof(char), 2);
		new_str[0] = c;
		free(str);
		return (new_str);
	}
	size = ft_strlen(str);
	new_str = ft_calloc(sizeof(char), (size + 2));
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	free(str);
	return (new_str);
}

static void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static char				*str;
	int						client_pid;
	static int				bits;

	(void)context;
	client_pid = info->si_pid;
	if (sig == SIGUSR2)
		c |= 1;
	if (bits == 7)
	{
		if (c == '\0')
		{
			ft_printf("%s", str);
			kill(client_pid, SIGUSR1);
			free(str);
		}
		bits = -1;
		str = join_char(str, c);
		c = 0;
	}
	else
		c <<= 1;
	bits++;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
