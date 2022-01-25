/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:54:27 by hqureshi          #+#    #+#             */
/*   Updated: 2022/01/21 14:54:28 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freemalloc(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

static char	*ft_split_cpy(char *str, char chr)
{
	int		i;
	char	*array;

	i = 0;
	array = 0;
	while (str[i] == chr)
		i++;
	while (str[i] && str[i] != chr)
		i++;
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (!array)
		return (0);
	i = 0;
	while (str[i] && str[i] != chr)
	{
		array[i] = str[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

static	int	ft_count(char const *s, char c)
{
	int		i;
	int		count;
	int		word;

	i = 0;
	count = 0;
	word = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i])
			word = 1;
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				count++;
		}
		else
			i++;
	}
	return (count + word);
}

char	**ft_split(char const *s, char c)
{
	int		counter_length;
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	counter_length = ft_count((char *)s, c);
	arr = ft_calloc(sizeof(char *), counter_length + 1);
	if (!arr)
		return (0);
	while (i < counter_length)
	{
		while (*s == c)
			s++;
		arr[j] = ft_split_cpy((char *)s, c);
		if (!arr[j])
			return (ft_freemalloc(arr));
		j++;
		s = s + ft_strlen(arr[i]);
		i++;
	}
	return (arr);
}
