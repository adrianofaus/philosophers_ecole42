/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:32:37 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/12 19:52:13 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

/*
	TIME_STAMPS:
	Gettimeofday é uma função que vai pegar quantos segundos se passaram
	desde meia-noite de 01/01/1970
	Esta função recebe dois argumentos, um é relativo a estrutura que vai
	armazenar os dados referentes ao tempo de sistema e a outra é chamada de
	timezone, porém, é obsolete e não utilizada.
	Dentro da estrutura existe o tempo em segundos e em microsegundos e são
	estes os tempos que devem ser considerados
	Exemplo: Dois tempos são registrados no programa abaixo e diferença entre
	eles é de 10ms por conta da função usleep.
*/

int	main(void)
{
	struct timeval	current_time;
	long	time1;
	long	time2;
	long	diff_time;
	
	gettimeofday(&current_time, NULL);
	time1 = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	printf("%ld\n", time1);
	gettimeofday(&current_time, NULL);
	time2 = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	printf("%ld\n", time2);
	diff_time = time2 - time1;
	printf("%ld\n", diff_time);
	return (0);
}