/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:48:58 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/24 14:20:08 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int			init_table(t_table *table, char **input);
int			init_philo(t_philo **philo, t_table *table);
static int	init_semaphores(t_table *table);

static int	init_semaphores(t_table *table)
{
	int	c;

	sem_unlink("fork");
	sem_unlink("must_eat");
	sem_unlink("died");
	sem_unlink("microphone");
	table->forks = sem_open("fork", O_CREAT, 0600, table->num_of_forks);
	table->must_eat_count = \
	sem_open("must_eat", O_CREAT, 0600, table->waiter.sink_capacity);
	table->died = sem_open("died", O_CREAT, 0600, 1);
	sem_wait(table->died);
	table->microphone = sem_open("microphone", O_CREAT, 0600, 1);
	if (table->must_eat_count)
	{
		c = -1;
		while (++c < table->waiter.sink_capacity)
			sem_wait(table->must_eat_count);
	}
	return (0);
}

int	init_table(t_table *table, char **input)
{
	table->num_of_philos = ft_atol(input[0]);
	table->time_to_die = ft_atol(input[1]);
	table->time_to_eat = ft_atol(input[2]);
	table->time_to_sleep = ft_atol(input[3]);
	if (input[4] != NULL)
		table->times_must_eat = ft_atol(input[4]);
	else
		table->times_must_eat = 0;
	table->num_of_forks = table->num_of_philos;
	table->waiter.close_the_place = 1;
	table->waiter.sink_capacity = table->times_must_eat * table->num_of_philos;
	init_semaphores(table);
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
		(*philo)[philo_num].table = table;
		(*philo)[philo_num].meals_count = 0;
		(*philo)[philo_num].philo_num = philo_num + 1;
		(*philo)[philo_num].left_hand = (*philo)->table->forks;
		(*philo)[philo_num].right_hand = (*philo)->table->forks;
		(*philo)[philo_num].last_meal = table->timer;
		(*philo)[philo_num].status = 0;
	}
	return (1);
}
