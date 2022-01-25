/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:54:42 by hqureshi          #+#    #+#             */
/*   Updated: 2022/01/21 14:54:43 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	dest = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dest == 0)
		return (0);
	while (*s1 != '\0')
	{
		dest[i++] = *s1++;
	}
	while (*s2 != '\0')
	{
		dest[i++] = *s2++;
	}
	dest[i] = '\0';
	return (dest);
}
