/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:53:56 by hqureshi          #+#    #+#             */
/*   Updated: 2022/01/21 14:53:57 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	int		count;
	char	*src_char;
	char	*dest_char;

	src_char = (char *) src;
	dest_char = (char *) dest;
	count = 0;
	if (dest == src)
		return (dest_char);
	while (num--)
	{
		dest_char[count] = src_char[count];
		count++;
	}
	return (dest_char);
}
