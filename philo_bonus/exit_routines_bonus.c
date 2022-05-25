/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_routines_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:01:25 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/25 19:04:29 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int		ft_free_ptr(void *ptr);
int		ft_free_arr(void **arr, int size);
int		print_err(char *msg);
void	close_semaphores(t_table *table);

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

void	close_semaphores(t_table *table)
{
	sem_close(table->forks);
	sem_close(table->must_eat_count);
	sem_close(table->died);
	sem_close(table->microphone);
}
