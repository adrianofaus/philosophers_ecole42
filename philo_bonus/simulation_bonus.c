/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:30:59 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/22 19:38:54 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	simulation(t_philo *philo)
{
	if (philo->philo_num % 2 == 0)
		usleep(300);
	while (1)
	{
		sem_wait(philo->left_hand);
		printf("philo %d has taken a FORK\n", philo->philo_num);
		sem_wait(philo->right_hand);
		printf("philo %d has taken a FORK\n", philo->philo_num);
		printf("philo %d is EATING\n", philo->philo_num);
		usleep(philo->table->time_to_eat * 1000);
		(philo->meals_count)++;
		if (philo->meals_count <= philo->table->times_must_eat)
		{
			printf("philo %d has counted the meal\n", philo->philo_num);
			sem_post(philo->table->must_eat_count);
		}
		sem_post(philo->right_hand);
		sem_post(philo->left_hand);
		printf("philo %d is SLEEPING\n", philo->philo_num);
		usleep(philo->table->time_to_sleep * 1000);
		printf("philo %d is THINKING\n", philo->philo_num);
		usleep(300);
	}
	return (0);
}
