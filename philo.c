/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:53:20 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/18 16:06:09 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_meals_log(t_philo *philo)
{
	int	i;

	i = -1;
	printf("#### MEALS LOG ####\n");
	while (++i < philo->table->num_of_philos)
	{
		printf("----\nPhilo_num\t%d\nMeals\t\t%d\n", philo[i].philo_num, philo[i].meals_count);
	}
}

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
	print_meals_log(philo);
	destroy_all_mutexes(&table);
	ft_free_ptr((void *)philo->table->fork);
	ft_free_ptr((void *)philo);
	return (0);
}
