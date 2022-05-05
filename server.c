/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereda- <rpereda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:06:33 by rpereda-          #+#    #+#             */
/*   Updated: 2022/05/05 14:22:02 by rpereda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int character;
int position;

void receive_bits(int signal)
{
    if (signal == SIGUSR1)
        character |= 1 << position;
	if (signal == SIGUSR2)
		character |= 0 << position;
    position++;
    if (position == 8)
    {
        position = 0;
        if(!character)
            write(1, "\n", 1);
        else
			write(1,&character,1);
        character = 0;
    }
}

int main(void)
{
    character = 0;
    position = 0;
    //struct  sigaction sig;
    int     pid;

    pid = getpid();
    printf("%d\n",pid);
    //sig.sa_handler = &receive_bits;
	
	signal(SIGUSR1, receive_bits);
	signal(SIGUSR2, receive_bits);
	while(1)
		usleep(100);
}