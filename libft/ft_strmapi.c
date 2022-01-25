/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:58:21 by hqureshi          #+#    #+#             */
/*   Updated: 2022/01/21 14:58:22 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	if (!s)
		return (0);
	ptr = ft_strdup(s);
	if (!ptr)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = (*f)(i, ptr[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
