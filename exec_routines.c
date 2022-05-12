/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:59:16 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/06 23:43:54 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	give_birth_to_philos(t_philo *philo);
int	bound_philos_together(t_philo *philo);
int	exec_routines(t_philo *philo);

int	give_birth_to_philos(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->num_of_philos)
	{
		if (pthread_create(&philo[i].th, NULL, &philo_algorithm, &philo[i]))
			return (0);
	}
	return (1);
}

int	bound_philos_together(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->num_of_philos)
	{
		if (pthread_join(philo[i].th, NULL))
			return (0);
	}
	return (1);
}

int	exec_routines(t_philo *philo)
{
	if (!give_birth_to_philos(philo))
		return (print_err("Failed to give birth to philos"));
	if (!bound_philos_together(philo))
		return (print_err("Failed to bound philos together"));
	return (1);
}
