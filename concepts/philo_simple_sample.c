/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simple_sample.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:41:29 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/06 23:45:13 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo
{
	int				count;
	pthread_t		philo;
	pthread_mutex_t	fork;
}				t_philo;

void	*philo_behavior(void *arg)
{
	int	i;
	t_philo	*tmp;

	i = -1;
	tmp = (t_philo *)arg;
	while (++i < 1)
	{
		pthread_mutex_lock(&(tmp->fork));
		printf("Philo %d is eating\n", tmp->count);
		// usleep(100);
		printf("Philo %d stop eating\n", tmp->count);
		pthread_mutex_unlock(&(tmp->fork));
	}
	return (NULL);
}

int	main(void)
{
	t_philo	philosophers[2];

	philosophers[0].count = 1;
	philosophers[1].count = 2;
	pthread_mutex_init(&(philosophers[0].fork), NULL);
	pthread_mutex_init(&(philosophers[1].fork), NULL);
	pthread_create(&(philosophers[0].philo), NULL, &philo_behavior, &(philosophers[0]));
	pthread_create(&(philosophers[1].philo), NULL, &philo_behavior, &(philosophers[1]));
	pthread_join(philosophers[0].philo, NULL);
	pthread_join(philosophers[1].philo, NULL);
	return (0);
}