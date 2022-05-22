/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:03:19 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/22 20:27:09 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	*philo;

	if (!is_valid_input(argc, argv))
		return (print_err("Invalud input"));
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
