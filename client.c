/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:03:25 by yelatman          #+#    #+#             */
/*   Updated: 2022/01/17 15:46:18 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int bit, int PID)
{
	if (bit == 1)
	{
		if (kill (PID, SIGUSR1) == -1)
		{
			write (2, "Invalid PID\n", 13);
			exit (1);
		}
	}
	if (bit == 0)
	{
		if (kill (PID, SIGUSR2) == -1)
		{
			write (2, "Invalid PID\n", 13);
			exit (1);
		}
	}
}

void	extract_bits(unsigned char byte, int PID)
{
	int	i;
	int	bit;

	i = 0;
	bit = 0;
	while (i < 8)
	{
		bit = byte & 1;
		send_signal (bit, PID);
		byte >>= 1;
		i++;
		usleep(800);
	}
}

void	send_str(char *str, int PID)
{
	int	i;

	i = 0;
	while (str[i])
	{
		extract_bits (str[i], PID);
		i++;
	}
	extract_bits (str[i], PID);
}

int	main(int argc, char *argv[])
{
	int					pid;

	if (argc < 3)
	{
		write (2, "make sure you have 3 arguments !\n", 34);
		exit (1);
	}
	pid = ft_atoi (argv[argc - 2]);
	send_str (argv [argc -1], pid);
	return (0);
}
