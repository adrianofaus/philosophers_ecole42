/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:30:59 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/25 18:25:25 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_action(t_philo *philo, int action)
{
	long	time_interval;

	sem_wait(philo->table->microphone);
	time_interval = get_time_interval(philo->table->timer);
	// if (is_dead(philo))
	// {
	// 	printf("%ld\t%d died\n", time_interval, philo->philo_num);
	// 	// pthread_detach(philo->table->waiter.th);
	// 	// sem_close(philo->table->must_eat_count);
	// 	sem_post(philo->table->died);
	// 	exit(1);
	// }
	if (action == DIED)
		printf("%ld\t%d died\n", time_interval, philo->philo_num);
	if (action == EATING)
	{
		philo->last_meal = get_current_time();
		printf("%ld\t%d is eating\n", time_interval, philo->philo_num);
	}
	else if (action == SLEEPING)
		printf("%ld\t%d is sleeping\n", time_interval, philo->philo_num);
	else if (action == HAS_TAKEN_A_FORK)
		printf("%ld\t%d has taken a fork\n", time_interval, philo->philo_num);
	else if (action == THINKING)
		printf("%ld\t%d is thinking\n", time_interval, philo->philo_num);
	sem_post(philo->table->microphone);
}

void	take_a_nap(t_philo *philo)
{
	print_action(philo, SLEEPING);
	// usleep(philo->table->time_to_sleep * 1000);
	if (!check_status(philo, philo->table->time_to_sleep))
		exit(1);
}

void	put_in_the_sink(t_philo *philo)
{
	(philo->meals_count)++;
	if (philo->meals_count <= philo->table->times_must_eat)
		sem_post(philo->table->must_eat_count);
}

void	devour(t_philo *philo)
{
	sem_wait(philo->left_hand);
	print_action(philo, HAS_TAKEN_A_FORK);
	sem_wait(philo->right_hand);
	print_action(philo, HAS_TAKEN_A_FORK);
	print_action(philo, EATING);
	if (!check_status(philo, philo->table->time_to_eat))
		exit(1);
	put_in_the_sink(philo);
	sem_post(philo->left_hand);
	sem_post(philo->right_hand);
}

void	start_thinking(t_philo *philo)
{
	print_action(philo, THINKING);
	while (*(int *)philo->table->forks < 2)
	{
		if (get_time_interval(philo->last_meal) > philo->table->time_to_die)
		{
			print_action(philo, DIED);
			sem_post(philo->table->died);
			exit(1);
		}
		usleep(500);
	}
}

int	simulation(t_philo *philo)
{
	if (philo->philo_num % 2 == 0)
		usleep(300);
	while (1)
	{
		devour(philo);
		take_a_nap(philo);
		
		start_thinking(philo);
	}
	return (0);
}
