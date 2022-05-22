/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:03:19 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/22 19:18:48 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	*philo;
	
	if (argc == 0)
		return (1);
	init_table(&table, &argv[1]);
	init_philo(&philo, &table);
	exec_routines(philo);
	return (0);
}
