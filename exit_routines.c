/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:01:25 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/12 19:19:07 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free_ptr(void *ptr);
int	ft_free_arr(void **arr, int size);
int	print_err(char *msg);

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
