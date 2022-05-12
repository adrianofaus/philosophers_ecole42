/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:53:20 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/06 20:27:33 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		ft_free_ptr((void *)philo->table->fork);
		return (print_err("Uninitialized philo"));
	}
	exec_routines(philo);
	ft_free_ptr((void *)philo->table->fork);
	ft_free_ptr((void *)philo);
	return (0);
}
