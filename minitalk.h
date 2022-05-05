/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereda- <rpereda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:31:08 by rpereda-          #+#    #+#             */
/*   Updated: 2022/03/14 19:31:09 by rpereda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
 #define MINITALK_H

 #include <stdio.h>
 #include <signal.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>

 void send_bits(int pid, char byte);
 void receive_bits(int signal);
#endif