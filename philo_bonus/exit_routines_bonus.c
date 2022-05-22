/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_routines_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:01:25 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/22 20:29:31 by afaustin         ###   ########.fr       */
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
}
