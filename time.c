/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:22:18 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/12 20:50:24 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
