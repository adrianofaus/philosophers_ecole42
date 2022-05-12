/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:05:08 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/06 23:43:34 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, int action);
void	*devour(t_philo *philo);
void	*take_a_nap(t_philo *philo);
void	*philo_algorithm(void *ptr);

void	print_action(t_philo *philo, int action)
{
	pthread_mutex_lock(&(philo->table->microphone));
	if (action == EATING)
		printf("Philo %d has started eating...\n", philo->philo_num);
	else if (action == SLEEPING)
		printf("Philo %d has started sleeping...\n", philo->philo_num);
	else if (action == THINKING)
		printf("Philo %d has started thinking...\n", philo->philo_num);
	else if (action == HAS_TAKEN_A_FORK)
		printf("Philo %d has taken a fork\n", philo->philo_num);
	pthread_mutex_unlock(&(philo->table->microphone));
}

void	*devour(t_philo *philo)
{
	pthread_mutex_lock(philo->left_hand);
	print_action(philo, HAS_TAKEN_A_FORK);
	pthread_mutex_lock(philo->right_hand);
	print_action(philo, HAS_TAKEN_A_FORK);
	usleep((philo->table->time_to_eat * 1000));
	print_action(philo, EATING);
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_unlock(philo->right_hand);
	return (NULL);
}

void	*take_a_nap(t_philo *philo)
{
	print_action(philo, SLEEPING);
	usleep(philo->table->time_to_sleep * 1000);
	return (NULL);
}

void	*philo_algorithm(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (philo->meals_count < philo->table->times_must_eat)
	{
		if (philo->philo_num % 2 == 0)
			usleep((42 * 4) / 2);
		devour(philo);
		pthread_mutex_lock(&(philo->table->meals_count_access));
		(philo->meals_count)++;
		pthread_mutex_unlock(&(philo->table->meals_count_access));
		take_a_nap(philo);
		if (philo->meals_count < (philo->table->times_must_eat - 1))
			print_action(philo, THINKING);
	}
	return (NULL);
}
