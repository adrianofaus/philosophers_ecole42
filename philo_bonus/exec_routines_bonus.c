/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_routines_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:34:42 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/25 19:07:15 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	give_birth_to_philos(t_philo *philo);
int	exec_routines(t_philo *philo);

int	give_birth_to_philos(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->num_of_philos)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			simulation(&philo[i]);
	}
	return (0);
}

int	exec_routines(t_philo *philo)
{
	int	i;

	i = -1;
	give_birth_to_philos(philo);
	is_spotless(philo);
	while (++i < philo->table->num_of_philos)
		waitpid(philo[i].pid, &philo[i].status, 0);
	pthread_detach(philo->table->waiter.th);
	return (0);
}
