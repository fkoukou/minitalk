/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakoukou <fakoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:56:33 by fakoukou          #+#    #+#             */
/*   Updated: 2025/01/03 17:57:58 by fakoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	function_signal(int signal)
{
	static int	bit;
	static char	character;

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

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("Process ID: %d\n", pid);
	printf("Waiting for messages...\n");
	signal(SIGUSR1, function_signal);
	signal(SIGUSR2, function_signal);
	while (1)
		pause();
	return (0);
}
