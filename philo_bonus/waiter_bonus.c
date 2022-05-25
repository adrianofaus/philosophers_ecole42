/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:14:59 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/25 19:58:06 by adrianofaus      ###   ########.fr       */
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
	int		i;
	t_philo	*philo;

	i = -1;
	philo = (t_philo *)arg;
	while (++i < philo->table->waiter.sink_capacity)
		sem_wait(philo->table->must_eat_count);
	close_the_place(philo);
	return (NULL);
}

int	check_status(t_philo *philo, int end_time)
{
	int		interval;
	long	start_time;

	interval = 0;
	start_time = get_current_time();
	while (interval < end_time)
	{
		interval += get_time_interval(start_time);
		start_time = get_current_time();
		if (get_time_interval(philo->last_meal) > philo->table->time_to_die)
			return (0);
		usleep(500);
	}
	return (1);
}

void	is_spotless(t_philo *philo)
{
	if (philo->table->times_must_eat)
		pthread_create(&philo->table->waiter.th, NULL, &check_sink, philo);
	sem_wait(philo->table->died);
	close_the_place(philo);
}
