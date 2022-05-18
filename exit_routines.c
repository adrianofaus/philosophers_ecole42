/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:01:25 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/17 21:55:29 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free_ptr(void *ptr);
int	ft_free_arr(void **arr, int size);
int	print_err(char *msg);
int	destroy_all_mutexes(t_table *table);

int	ft_free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
		return (0);
	}
	return (1);
}

int	ft_free_arr(void **arr, int size)
{
	int	i;

	if (arr)
	{
		i = -1;
		while (++i < size)
		{
			if (!ft_free_ptr(arr[i]))
				return (0);
		}
		ft_free_ptr(arr);
		return (1);
	}
	return (0);
}

int	print_err(char *msg)
{
	printf("ERROR - %s\n", msg);
	return (0);
}

int	destroy_all_mutexes(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&table->meals_count_access);
	pthread_mutex_destroy(&table->microphone);
	while (++i < table->num_of_philos)
		pthread_mutex_destroy(&table->fork[i]);
	return (0);
}
