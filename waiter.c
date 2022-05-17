/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:39:37 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/16 23:43:41 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_table *table, long last_meal)
{
	if (get_time_interval(last_meal) >= table->time_to_die)
		return (0);
	return (1);
}

void	*check_all(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (!philo->table->waiter.close_the_place)
	{
		i = -1;
		while (++i < philo->table->num_of_philos && !philo->table->waiter.close_the_place)
		{
			if (!is_dead(philo->table, philo[i].last_meal))
				print_action(&philo[i], DIED);
		}
	}
	return (NULL);
}