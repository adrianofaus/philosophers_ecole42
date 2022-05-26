/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:03:19 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/26 00:14:23 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	*philo;

	if (!is_valid_input(argc, argv))
		return (print_err("Invalid input"));
	if (!init_table(&table, &argv[1]))
		return (print_err("Uninitialized data"));
	if (!init_philo(&philo, &table))
	{
		close_semaphores(&table);
		return (print_err("Uninitialized philo"));
	}
	exec_routines(philo);
	ft_free_ptr(philo);
	return (0);
}
