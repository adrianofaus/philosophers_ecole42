/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_routines_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:34:42 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/22 19:03:19 by afaustin         ###   ########.fr       */
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
	while (++i < philo->table->total_times_must_eat)
		sem_wait(philo->table->must_eat_count);
	i = -1;
	while (++i < philo->table->num_of_philos)
		kill(philo[i].pid, SIGKILL);
	i = -1;
	while (++i < philo->table->num_of_philos)
		waitpid(philo[i].pid, &philo[i].status, 0);
	return (0);
}