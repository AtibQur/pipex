/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:53:48 by hqureshi          #+#    #+#             */
/*   Updated: 2022/01/21 14:53:49 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_char;
	size_t	i;

	s_char = (char *)s;
	i = 0;
	while (i < n)
	{
		if (s_char[i] == (char)c)
			return ((void *)&s_char[i]);
		i++;
	}
	return (NULL);
}
