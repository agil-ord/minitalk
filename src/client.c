/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:01:56 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/30 19:15:20 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_mutex;

/*
void	send_signal(char c, int pid)
{
	int	i;
	int	bit;

	i = 8;
	while (i-- > 0)
	{
		g_mutex = 0;
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_mutex == 0)
			usleep(1);
	}
}
*/
void	send_signal(unsigned char c, int pid)
{
	int	i;
	int	bit;

	i = 8;
	while (i > 0)
	{
		i--;
		g_mutex = 0;
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_mutex == 0)
			usleep(1);
	}
}

/*
void	signal_handler(int signal)
{
	static int	bits = 0;

	if (signal == SIGUSR2)
	{
		bits++;
		g_mutex = 1;
	}
	else
		exit(ft_printf("Bits received %d\n", bits));
}
*/
void	signal_handler(int signal)
{
	static int	character = -1;
	static int	bits = 0;

	if (signal == SIGUSR2)
	{
		bits++;
		if (bits % 8 == 0)
			character++;
		g_mutex = 1;
	}
	else
		exit(ft_printf("Character recived %d\n", character));
}

int	main(int argc, char **argv)
{
	size_t				i;
	char				*str;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (ft_printf("Arguments is incorrect\n"), 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	i = 0;
	str = argv[2];
	while (ft_strlen(str) >= i)
	{
		send_signal(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	while (1)
		pause();
}
