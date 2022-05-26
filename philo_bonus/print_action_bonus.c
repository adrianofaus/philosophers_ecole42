/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:44:37 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/26 22:10:01 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_action(t_philo *philo, int action)
{
	long	time_interval;

	sem_wait(philo->table->microphone);
	time_interval = get_time_interval(philo->table->timer);
	if (action == DIED)
	{
		printf("%ld\t%d died\n", time_interval, philo->philo_num);
		sem_post(philo->table->died);
		// exit(1);
	}
	else if (action == EATING)
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
	if (action != DIED)
		sem_post(philo->table->microphone);
}
