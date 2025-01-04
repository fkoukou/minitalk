/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakoukou <fakoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:12:44 by fakoukou          #+#    #+#             */
/*   Updated: 2025/01/04 16:56:45 by fakoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char byte)
{
	int	shift;
	int	result;

	shift = 7;
	while (shift >= 0)
	{
		if ((byte >> shift) & 1)
			result = kill(pid, SIGUSR1);
		else
			result = kill(pid, SIGUSR2);
		usleep(400);
		shift--;
		if (result == -1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_signal(pid, message[i]);
		i++;
	}
	send_signal(pid, '\0');
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3 || !ft_isdigit(argv[1]))
	{
		ft_printf("INVALID ARGUMENT\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
