/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:22:18 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/23 00:23:23 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_current_time(void);
long	get_time_interval(long old_timestamp);

long	get_current_time(void)
{
	struct timeval	current_time;
	long			time_stamp;

	gettimeofday(&current_time, NULL);
	time_stamp = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time_stamp);
}

long	get_time_interval(long old_timestamp)
{
	struct timeval	current_time;
	long			timestamp;
	long			time_interval;

	gettimeofday(&current_time, NULL);
	timestamp = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	time_interval = timestamp - old_timestamp;
	return (time_interval);
}
