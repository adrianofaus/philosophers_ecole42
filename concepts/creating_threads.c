/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:48:15 by afaustin          #+#    #+#             */
/*   Updated: 2022/04/27 14:35:45 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/*
	CREATING THREADS:
	O que é: Uma thread é a menor unidade de código que pode ser gerenciado por um sistema operacional.
	Utilidade: Com as threads é possivel que diversas partes de um código sejam rodadas em paralelo,
	compartilhando os mesmo recursos, isso pode agilizar muito a execução de um programa.
	Exemplo: Duas funções são criadas, estas funções são executadas em paralelo, porém, para que seja possível
	ler a troca de mensagens, um intervalo de 100ms é colocado em uma função e, 200ms é colocado em outra.
*/

void	*my_turn(void *arg)
{
	while (1)
	{
		usleep(100000);
		printf("My turn\n");
	}
	return (NULL);
}

void	*your_turn(void)
{
	while (1)
	{
		usleep(200000);
		printf("Your turn\n");
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	new_thread;
	
	pthread_create(&new_thread, NULL, my_turn, NULL);
	your_turn();
	
	return (0);
}