/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:49:52 by afaustin          #+#    #+#             */
/*   Updated: 2022/05/23 00:20:43 by afaustin         ###   ########.fr       */
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

// --------------------------------  DEFINES  ----------------------------------

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

typedef struct s_table
{
	sem_t	*forks;
	sem_t	*must_eat_count;
	int		num_of_philos;
	int		num_of_forks;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	int		times_must_eat;
	int		total_times_must_eat;
	long	timer;
}			t_table;

typedef struct s_philo
{
	pid_t		pid;
	sem_t		*left_hand;
	sem_t		*right_hand;
	t_table		*table;
	int			philo_num;
	int			meals_count;
	int			status;
}			t_philo;

// --------------------------------  init_philo_bonus.c  -----------------------
int		init_table(t_table *table, char **input);
int		init_philo(t_philo **philo, t_table *table);

// --------------------------------  conversion.c  -----------------------------
long	ft_atol(const char *nptr);

// --------------------------------  utils.c  ----------------------------------
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

// --------------------------------  exec_routines_bonus.c  --------------------
int		give_birth_to_philos(t_philo *philo);
int		exec_routines(t_philo *philo);

// --------------------------------  simulatin_bonus.c  ------------------------
int		simulation(t_philo *philo);

// --------------------------------  exit_routines.c  --------------------------
int		ft_free_ptr(void *ptr);
int		ft_free_arr(void **arr, int size);
int		print_err(char *msg);
void	close_semaphores(t_table *table);

// --------------------------------  validaton_bonus.c  ------------------------
int		is_numeric_string(char *str);
int		ft_isdigit(int c);
int		is_valid_input(int num_of_args, char **input);
int		is_valid_int(char *str);

// --------------------------------  timer_bonus.c  ----------------------------
long	get_current_time(void);
long	get_time_interval(long old_timestamp);

#endif