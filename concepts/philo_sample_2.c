/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sample_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:37:10 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/04 20:57:52 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef enum e_doing
{
	EATING,
	THINKING,
	SLEEPING,
	DEAD,
};

typedef struct	s_data
{
	pthread_mutex_t	*fork;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}				t_data;

typedef struct s_philo
{
	pthread_t		th;
	pthread_mutex_t	*left_hand;
	pthread_mutex_t	*right_hand;
	int				philo_num;
	int				status;
	t_data			*data;
}				t_philo;

void	*devour(void *data)
{
	struct timeval	current_time;
	t_philo			*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->left_hand);
	pthread_mutex_lock(philo->right_hand);
	printf("Philo %d has started eating...\n", philo->philo_num);
	usleep((philo->data->time_to_eat * 1000));
	printf("Philo %d has started sleeping...\n", philo->philo_num);
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_unlock(philo->right_hand);
}

void	*philo_algorithm(void *data)
{	
	t_philo	*philo;
	
	philo = (t_philo *)data;
	devour(data);
	return (NULL);
}

int	main(void)
{
	t_data	data;
	t_philo	*philos;

	/* INIT DATA */
	data.num_of_philos = 2;
	data.time_to_die = 300;
	data.time_to_eat = 100;
	data.time_to_sleep = 100;
	data.fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data.num_of_philos);
	pthread_mutex_init(&(data.fork[0]), NULL);
	pthread_mutex_init(&(data.fork[1]), NULL);

	/* INIT PHILO */
	philos = (t_philo *)malloc(sizeof(t_philo) * data.num_of_philos);
	philos[0].data = &data;
	philos[1].data = &data;
	philos[0].status = THINKING;
	philos[1].status = THINKING;
	philos[0].philo_num = 0;
	philos[1].philo_num = 1;
	philos[0].left_hand = &data.fork[0];
	philos[0].right_hand = &data.fork[1];
	philos[1].left_hand = &data.fork[1];
	philos[1].right_hand = &data.fork[0];
	
	/*START SIMULATION*/
	pthread_create(&(philos[0].th), NULL, &philo_algorithm, &philos[0]);
	pthread_create(&(philos[1].th), NULL, &philo_algorithm, &philos[1]);
	pthread_join(philos[0].th, NULL);
	pthread_join(philos[1].th, NULL);

	/*END SIMULATION*/
	free(philos);
	free(data.fork);
	return (0);
}