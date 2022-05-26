/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:30:59 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/27 01:29:20 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_a_nap(t_philo *philo)
{
	print_action(philo, SLEEPING);
	if (!check_status(philo, philo->table->time_to_sleep))
		print_action(philo, DIED);
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
		print_action(philo, DIED);
	sem_post(philo->left_hand);
	sem_post(philo->right_hand);
	put_in_the_sink(philo);
}

void	start_thinking(t_philo *philo)
{
	print_action(philo, THINKING);
	while (*(int *)philo->table->forks < 2)
	{
		if (get_time_interval(philo->last_meal) > philo->table->time_to_die)
			print_action(philo, DIED);
		usleep(500);
	}
	usleep(500);
}

int	simulation(t_philo *philo)
{
	if (philo->table->num_of_philos == 1)
	{
		sem_wait(philo->left_hand);
		print_action(philo, HAS_TAKEN_A_FORK);
		while (1)
		{
			if (get_time_interval(philo->last_meal) > philo->table->time_to_die)
				print_action(philo, DIED);
			usleep(500);
		}
	}
	if (philo->philo_num % 2 == 0)
		usleep(2000);
	while (1)
	{
		devour(philo);
		take_a_nap(philo);
		start_thinking(philo);
	}
	return (0);
}
