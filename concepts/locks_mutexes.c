/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks_mutexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:01:19 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/01 01:33:16 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;

void	*count_to_big(void *arg)
{
	int	i;
	int	*counter;
	
	i = -1;
	counter = (int *)arg;
	while (++i < 10000000)
	{
		pthread_mutex_lock(&lock);
		(*counter)++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	t1, t2;
	int			counter;
	
	counter = 0;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&t1, NULL, &count_to_big, &counter);
	pthread_create(&t2, NULL, &count_to_big, &counter);
	// count_to_big(NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);	
	printf("%d\n", counter);
	return (0);
}