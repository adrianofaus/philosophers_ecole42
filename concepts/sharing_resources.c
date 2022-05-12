/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharing_resources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:54:44 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/01 22:41:13 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void	*your_turn(void *arg)
{
	int	i;
	int	*value;
	int	*result;

	i = -1;
	value = (int *)arg;
	result = (int *)malloc(sizeof(int));
	while (++i <= 5)
	{
		// printf(">> %d - Your turn\n", i);
		usleep(100000);
		(*value)++;
	}
	*result = (*value) + 5;
	return (result);
}

void	*my_turn(void *arg)
{
	int	i;

	i = -1;
	while (++i <= 3)
	{
		usleep(200000);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	new_thread;
	int			*i;
	int			*result;

	*i = 0;
	pthread_create(&new_thread, NULL, your_turn, i);
	my_turn(NULL);
	pthread_join(new_thread, (void *)&result);
	printf("%d %d\n", *i, *result);

	return (0);
}

