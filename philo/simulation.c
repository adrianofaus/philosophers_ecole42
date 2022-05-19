/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:05:08 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/19 22:55:26 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, int action);
void	*devour(t_philo *philo);
void	*take_a_nap(t_philo *philo);
void	*philo_algorithm(void *ptr);

void	print_action(t_philo *philo, int action)
{
	long	time_interval;

	pthread_mutex_lock(&(philo->table->microphone));
	time_interval = get_time_interval(philo->table->timer);
	if (action == DIED && !philo->table->waiter.close_the_place)
	{
		philo->table->waiter.close_the_place = 1;
		printf("%ld\t%d died\n", time_interval, philo->philo_num);
	}
	if (!philo->table->waiter.close_the_place)
	{
		if (action == EATING)
		{
			philo->last_meal = get_current_time();
			printf("%ld\t%d is eating\n", time_interval, philo->philo_num);
		}
		else if (action == SLEEPING)
			printf("%ld\t%d is sleeping\n", time_interval, philo->philo_num);
		else if (action == THINKING)
			printf("%ld\t%d is thinking\n", time_interval, philo->philo_num);
		else if (action == HAS_TAKEN_A_FORK)
			printf("%ld\t%d has taken a fork\n", time_interval, philo->philo_num);
	}
	pthread_mutex_unlock(&(philo->table->microphone));
}

void	*devour(t_philo *philo)
{
	pthread_mutex_lock(philo->left_hand);
	print_action(philo, HAS_TAKEN_A_FORK);
	pthread_mutex_lock(philo->right_hand);
	print_action(philo, HAS_TAKEN_A_FORK);
	print_action(philo, EATING);
	usleep((philo->table->time_to_eat * 1000));
	return (NULL);
}

void	*take_a_nap(t_philo *philo)
{
	print_action(philo, SLEEPING);
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_unlock(philo->right_hand);
	usleep(philo->table->time_to_sleep * 1000);
	return (NULL);
}

void	put_in_the_sink(t_philo *philo)
{
	if (!philo->table->waiter.close_the_place)
	{
		pthread_mutex_lock(&(philo->table->meals_count_access));
		(philo->meals_count)++;
		if (philo->meals_count <= philo->table->times_must_eat)
			(philo->table->waiter.sink_capacity)--;
		pthread_mutex_unlock(&(philo->table->meals_count_access));
	}
}

void	*simulation(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (!philo->table->waiter.close_the_place)
	{
		if (philo->philo_num % 2 == 0)
			usleep((42 * 4) / 2);
		if (philo->table->num_of_philos == 1)
		{
			pthread_mutex_lock(philo->left_hand);
			print_action(philo, HAS_TAKEN_A_FORK);
			pthread_mutex_unlock(philo->left_hand);
			break ;
		}
		devour(philo);
		if (philo->table->times_must_eat)
			put_in_the_sink(philo);
		take_a_nap(philo);
		print_action(philo, THINKING);
	}
	return (NULL);
}
