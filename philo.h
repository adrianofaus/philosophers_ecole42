/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:12:11 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/17 22:29:46 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// --------------------------------  INCLUDES  ---------------------------------

# include <stdio.h> //printf
# include <pthread.h> //pthread functions
# include <stdlib.h> //alloc, free functions
# include <unistd.h> //usleep
# include <sys/time.h> //gettimetoday

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

typedef struct s_waiter
{
	pthread_t	th;
	int			rip;
	int			close_the_place;
}				t_waiter;

typedef struct s_table
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	meals_count_access;
	pthread_mutex_t	microphone;
	t_waiter		waiter;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	long			timer;
}				t_table;

typedef struct s_philo
{
	t_table			*table;
	pthread_t		th;
	pthread_mutex_t	*left_hand;
	pthread_mutex_t	*right_hand;
	int				philo_num;
	int				meals_count;
	int				status;
	long			last_meal;
}				t_philo;

// -------------------------------  FUNCTIONS  ---------------------------------

// -------------------------------  init_philo.c  ------------------------------
int		init_table(t_table *table, char **input);
int		init_philo(t_philo **philo, t_table *table);

// -------------------------------  exit_routines.c  ---------------------------
int		ft_free_ptr(void *ptr);
int		ft_free_arr(void **arr, int size);
int		print_err(char *msg);
int		destroy_all_mutexes(t_table *table);

// -------------------------------  exec_routines.c  ---------------------------
int		exec_routines(t_philo *philo);

// -------------------------------  philo_algorithm.c  -------------------------
void	*simulation(void *ptr);
void	print_action(t_philo *philo, int action);

// -------------------------------  validation.c  ------------------------------
int		is_valid_input(int num_of_args, char **input);

// -------------------------------  conversion.c  ------------------------------
long	ft_atol(const char *nptr);

// -------------------------------  time.c  ------------------------------------
long	get_current_time(void);
long	get_time_interval(long old_timestamp);

// -------------------------------  utils.c  -----------------------------------
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

// -------------------------------  waiter.c  ----------------------------------
void	*check_all(void *arg);

#endif
