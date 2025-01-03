/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakoukou <fakoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:56:33 by fakoukou          #+#    #+#             */
/*   Updated: 2025/01/03 10:16:32 by fakoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	function_signal(int signal)
{
	static int	bit;
	static char	character;

	bit = 0;
	character = 0;
	character <<= 1;
	if (signal == SIGUSR1)
		character |= 1;
	bit++;
	if (bit == 8)
	{
		if (character == '\0')
			write(1, "\n", 1);
		else
			write(1, &character, 1);
		bit = 0;
		character = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Usage: ./server\n");
		return (1);
	}
	sig.sa_handler = function_signal;
	sig.sa_flags = 0;
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
