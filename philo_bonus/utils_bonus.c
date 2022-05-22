/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:12:24 by adrianofaus       #+#    #+#             */
/*   Updated: 2022/05/22 18:04:26 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dst)
		return (0);
	i = 0;
	while (n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		size;

	size = ft_strlen(s);
	cpy = (char *)malloc(((size + 1) * sizeof(char)));
	if (!cpy)
		return (NULL);
	cpy = ft_memcpy(cpy, s, size + 1);
	return (cpy);
}
