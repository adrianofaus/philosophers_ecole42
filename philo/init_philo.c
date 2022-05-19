/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:11:08 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/19 22:55:13 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(t_table *table, char **input);
int	init_philo(t_philo **philo, t_table *table);

int	init_table(t_table *table, char **input)
{
	int	fork_num;

	table->num_of_philos = ft_atol(input[0]);
	table->time_to_die = ft_atol(input[1]);
	table->time_to_eat = ft_atol(input[2]);
	table->time_to_sleep = ft_atol(input[3]);
	if (input[4] != NULL)
		table->times_must_eat = ft_atol(input[4]);
	else
		table->times_must_eat = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * table->num_of_philos);
	if (!table->fork)
		return (0);
	fork_num = -1;
	while (++fork_num < table->num_of_philos)
		pthread_mutex_init(&table->fork[fork_num], NULL);
	pthread_mutex_init(&(table->meals_count_access), NULL);
	pthread_mutex_init(&(table->microphone), NULL);
	table->waiter.close_the_place = 0;
	table->waiter.sink_capacity = table->num_of_philos * table->times_must_eat;
	table->timer = get_current_time();
	return (1);
}

int	init_philo(t_philo **philo, t_table *table)
{
	int	philo_num;

	(*philo) = malloc(sizeof(t_philo) * table->num_of_philos);
	if (!(*philo))
		return (0);
	philo_num = -1;
	while (++philo_num < table->num_of_philos)
	{
		(*philo)[philo_num].meals_count = 0;
		(*philo)[philo_num].table = table;
		(*philo)[philo_num].philo_num = philo_num + 1;
		(*philo)[philo_num].left_hand = &table->fork[philo_num];
		if (philo_num == (table->num_of_philos - 1))
			(*philo)[philo_num].right_hand = &table->fork[0];
		else
			(*philo)[philo_num].right_hand = &table->fork[philo_num + 1];
		(*philo)[philo_num].last_meal = table->timer;
	}
	return (1);
}
