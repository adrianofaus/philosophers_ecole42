/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:03:19 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/22 22:53:24 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(void)
{
	t_philo	philo[2];
	t_table	table;
	int		i;

	i = -1;
	table.num_of_philos = 2;
	table.num_of_forks = table.num_of_philos;
	table.time_to_eat = 300;
	table.time_to_sleep = 300;
	table.times_must_eat = 1;
	sem_unlink("fork");
	sem_unlink("must_eat");
	table.forks = sem_open("fork", O_CREAT | O_EXCL, 0600, table.num_of_forks);
	table.must_eat_count = sem_open("must_eat", O_CREAT | O_EXCL, 0600, (table.times_must_eat * table.num_of_philos));
	sem_wait(table.must_eat_count);
	sem_wait(table.must_eat_count);
	// sem_wait(table.must_eat_count);
	// sem_wait(table.must_eat_count);

	philo[0].table = &table;
	philo[1].table = &table;
	
	philo[0].philo_num = 1;
	philo[1].philo_num = 2;
	
	philo[0].left_hand = philo->table->forks;
	philo[0].right_hand = philo->table->forks;
	
	philo[1].left_hand = philo->table->forks;
	philo[1].right_hand = philo->table->forks;

	philo[0].meals_count = 0;
	philo[1].meals_count = 0;

	while (++i < 2)
	{
		philo[i].pid = fork();	
		if (philo[i].pid == 0)
		{
			if (philo[i].philo_num % 2 == 0)
				usleep(300);
			while (1)
			{
				sem_wait(philo[i].left_hand);
				printf("philo %d has taken a FORK\n", philo[i].philo_num);
				sem_wait(philo[i].right_hand);
				printf("philo %d has taken a FORK\n", philo[i].philo_num);
				printf("philo %d is EATING\n", philo[i].philo_num);
				usleep(philo[i].table->time_to_eat * 1000);
				(philo[i].meals_count)++;
				if (philo[i].meals_count <= philo->table->times_must_eat)
				{
					printf("philo %d has counted the meal\n", philo[i].philo_num);
					sem_post(philo[i].table->must_eat_count);
				}
				sem_post(philo[i].right_hand);
				sem_post(philo[i].left_hand);
				printf("philo %d is SLEEPING\n", philo[i].philo_num);
				usleep(philo[i].table->time_to_sleep * 1000);
				printf("philo %d is THINKING\n", philo[i].philo_num);
				usleep(300);
			}
		}
	}
	sem_wait(table.must_eat_count);
	printf("#FLAG\n");
	sem_wait(table.must_eat_count);
	printf("#FLAG\n");
	// sem_wait(table.must_eat_count);
	// printf("A philo has eaten a necessary meal\n");
	// sem_wait(table.must_eat_count);
	// printf("A philo has eaten a necessary meal\n");
	kill(philo[0].pid, SIGKILL);
	kill(philo[1].pid, SIGKILL);
	waitpid(philo[0].pid, &philo[0].status, 0);
	waitpid(philo[1].pid, &philo[1].status, 0);
	return (0);
}