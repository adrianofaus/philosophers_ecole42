/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:24:21 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/12 19:18:14 by adrianofaus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numeric_string(char *str);
int	ft_isdigit(int c);
int	is_valid_input(int num_of_args, char **input);
int	is_valid_int(char *str);

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_numeric_string(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	is_valid_int(char *str)
{
	long	converted_string;

	converted_string = ft_atol(str);
	if (converted_string > INT_MAX)
		return (0);
	return (1);
}

int	is_valid_input(int num_of_args, char **input)
{
	int	i;

	if (num_of_args > 4 && num_of_args < 7)
	{
		i = 0;
		while (input[++i])
		{
			if (!is_numeric_string(input[i]) || !is_valid_int(input[i]))
				return (0);
		}
		return (1);
	}
	return (0);
}
