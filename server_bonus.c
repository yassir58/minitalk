/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:16:33 by yelatman          #+#    #+#             */
/*   Updated: 2022/01/17 14:54:00 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

int	bin_to_ascii(char byte[])
{
	int	length ;
	int	sum ;
	int	multiplier;
	int	i;

	length = 8;
	sum = 0;
	multiplier = 0;
	i = length - 1;
	while (i >= 0)
		sum += ((byte[i--] - 48) * (1 << multiplier++));
	return (sum);
}

char	set_bit(int signo)
{
	if (signo == SIGUSR1)
		return ('1');
	else if (signo == SIGUSR2)
		return ('0');
	return (0);
}

int	print_byte(char *byte, int *indx, int temp, int signo)
{
	char	c;

	byte[temp] = set_bit(signo);
	*indx = 0;
	c = bin_to_ascii (byte);
	if (c == 0)
		return (0);
	write (1, &c, sizeof (char));
	return (1);
}

void	signal_handler(int signo, siginfo_t *siginfo, void *context)
{
	static int	indx;
	static char	byte[8];
	int			temp;
	int			check;

	context = NULL;
	check = 1;
	if (!g_pid)
		g_pid = siginfo->si_pid;
	if (g_pid != siginfo->si_pid)
	{
		g_pid = siginfo->si_pid;
		indx = 0;
	}
	temp = BIT_COUNT - (++indx);
	if (temp == 0)
		check = print_byte (byte, &indx, temp, signo);
	else
		byte[temp] = set_bit(signo);
	if (!check)
	{
		if (kill (siginfo->si_pid, SIGUSR2) == -1)
			write (2, "Error returning signal\n", 24);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig_act;

	pid = getpid ();
	write (1, "server PID: ", 12);
	ft_putnbr (pid);
	write (1, "\n", 1);
	sig_act.sa_sigaction = &signal_handler;
	sig_act.sa_flags = SA_SIGINFO;
	sig_act.sa_flags = SA_NODEFER;
	sigaction (SIGUSR2, &sig_act, NULL);
	sigaction (SIGUSR1, &sig_act, NULL);
	while (1)
		pause ();
	return (0);
}
