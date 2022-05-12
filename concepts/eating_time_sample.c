/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_time_sample.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:18:02 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/02 17:36:32 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct	s_philo
{
	pthread_t		th_philo;
	pthread_mutex_t	fork;
	int				eating_time;
	int				philo_num;
}			t_philo;

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
			write(fd, s++, 1);
	}
}


void	*devour(void *arg)
{
	t_philo	*tmp;
	struct timeval	current_time;
	long	started_eating = 0;
	long	finished_eating = 0;

	tmp = (t_philo *)arg;
	gettimeofday(&current_time, NULL);
	started_eating = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	ft_putstr_fd("Start eating\n", 1);
	usleep((tmp->eating_time * 1000));
	gettimeofday(&current_time, NULL);
	finished_eating = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	ft_putstr_fd("Start sleeping\n", 1);
	printf("eating time >: %ld\n", (finished_eating - started_eating));
}

int	main(void)
{
	t_philo	philo;

	philo.philo_num = 1;
	philo.eating_time = 100;
	
	pthread_create(&philo.th_philo, NULL, &devour, &philo);
	pthread_join(philo.th_philo, NULL);
	return (0);
}