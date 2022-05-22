/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:49:52 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/22 01:46:04 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

// --------------------------------  INCLUDES  ---------------------------------

# include <stdio.h> //printf
# include <pthread.h> //pthread functions
# include <stdlib.h> //alloc, free functions
# include <unistd.h> //usleep, fork
# include <sys/time.h> //gettimetoday
# include <sys/wait.h> //waitpid
# include <signal.h> //kill
# include <semaphore.h> //sem_open, sem_close, sem_post, sem_wait, sem_unlink
# include <fcntl.h> //for O_* constants
# include <sys/stat.h> //for mode constants

// --------------------------------  DEFINES  ---------------------------------

# define INT_MAX 2147483647

// --------------------------------  STRUCTS  ----------------------------------

enum e_action
{
	EATING,
	SLEEPING,
	THINKING,
	HAS_TAKEN_A_FORK,
	DIED
};

#endif