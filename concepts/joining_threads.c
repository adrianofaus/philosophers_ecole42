/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joining_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:31:17 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/02 14:42:01 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

/*
	JOINING THREADS:
	O que é: Juntar uma thread permite que a main thread não finalize enquanto 
	a thread a ser agregada não tenha sido finalizada também. Além disso, através
	do segundo argumento da funçõa é possivel receber um retorno da thread
	que se encerrou.
	Exemplo: Duas funções são criadas, em uma delas temos um loop maior que o outro,
	a thread da main executa o menor loop, e espera pelo maior loop sera encerrado
	através da função 'pthread_join', além disso, é feito uma alocação de memória
	na thread que tem o maior loop e o valor retornado será somado com o da thread
	da main.
*/

void	*my_turn(void *arg)
{
	int	*i;

	i = (int *)arg;
	while ((*i) <= 2)
	{
		(*i)++;
	}
	return (NULL);
}

void	*your_turn(void *arg)
{
	int	*j;
	
	j = (int *)malloc(sizeof(int));
	*j = 0;
	while ((*j) <= 4)
	{
		(*j)++;
	}
	return (j);
}

int	main(void)
{
	pthread_t	th;
	int			i;
	int			*j;
	int			sum;

	i = 0;
	my_turn(&i);
	pthread_create(&th, NULL, &your_turn, NULL);
	pthread_join(th, (void *)&j);
	sum = i + *j;
	free(j);
	printf("sum of counts %d\n", sum);
	return (0);
}