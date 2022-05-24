/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:14:59 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/24 16:53:36 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_the_place(t_philo *philo);
void	*check_sink(void *arg);
void	is_spotless(t_philo *philo);

void	close_the_place(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->num_of_philos)
		kill(philo[i].pid, SIGKILL);
	philo->table->waiter.close_the_place = 0;
	sem_post(philo->table->died);
}

void	*check_sink(void *arg)
{
	int	i;
	t_philo *philo;

	i = -1;
	philo = (t_philo *)arg;
	while (++i < philo->table->waiter.sink_capacity)
		sem_wait(philo->table->must_eat_count);
	close_the_place(philo);
	return (NULL);
}

void	is_spotless(t_philo *philo)
{
	pthread_create(&philo->table->waiter.th, NULL, &check_sink, philo);
	sem_wait(philo->table->died);
	close_the_place(philo);
}