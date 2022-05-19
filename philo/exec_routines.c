/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:59:16 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/19 22:54:50 by afaustin         ###   ########.fr       */
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
		if (pthread_create(&philo[i].th, NULL, &simulation, &philo[i]))
			return (0);
	}
	return (1);
}

int	give_birth_to_waiter(t_philo *philo)
{
	if (pthread_create(&(philo->table->waiter.th), NULL, &is_spotless, philo))
		return (0);
	return (1);
}

int	bound_waiter_together(t_philo *philo)
{
	if (pthread_join(philo->table->waiter.th, NULL))
		return (0);
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
	if (!give_birth_to_waiter(philo))
		return (print_err("Failed to give birth to waiter"));
	if (!bound_philos_together(philo))
		return (print_err("Failed to bound philos together"));
	if (!bound_waiter_together(philo))
		return (print_err("Failed to bound waiter together"));
	return (1);
}
