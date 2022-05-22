/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:49:26 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/22 18:04:40 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_atol(const char *nptr)
{
	long	result;
	int		signal;

	result = 0;
	signal = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\r' || \
			*nptr == '\f' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (*nptr - '0') * signal;
		nptr++;
	}
	return (result);
}
