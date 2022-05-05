/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereda- <rpereda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:06:28 by rpereda-          #+#    #+#             */
/*   Updated: 2022/05/05 14:25:49 by rpereda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//podria hacer el pid int desde fuera usando atoi.
//tengo 2 señales sigusr1 y 2, 1 para enviar 1 y otra para enviar 0
//COMO VERGA HAGO ESO XD
//un byte tiene 8 bits por lo que puedo hacer un bucle de 8 y de alguna manera
//operar con los bits
//ni puta idea de si esto funciona
//diviendo entre 2 y viendo el modulo puedo hacerlo yikes XD!

void send_bits(int pid, char byte){
	
	int i;

	i = 0;
	while(i < 8)
	{
		if(byte % 2 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		byte /= 2;
		i++;
		usleep(100);
	}
}

int main(int argc, char **argv){
    
    int	pid;
	int	i;

    if (argc != 3 || *argv[2] == '\0')
	{
		write(1,"Invalid input\n",15);
		return(1);
	}
	else
	{
		i = 0;
		pid = atoi(argv[1]); //Usar ft_atoi
		// hacer esta funcion basandose en el comment de arriba
		while(argv[2][i])
		{
			send_bits(pid, argv[2][i]);
			i++;
		}
	}
	return (0);
}
