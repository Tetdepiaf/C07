/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:09:58 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/17 17:09:59 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	issep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count(char *str, char *charset)
{
	int	i;
	int	nb;
	int	isword;

	i = 0;
	nb = 1;
	isword = 1;
	while (str[i])
	{
		while (issep(str[i], charset) && str[i])
		{
			i++;
			isword = 1;
		}
		if (isword == 1 && str[i])
		{
			nb++;
			isword = 0;
		}
		i++;
	}
	return (nb);
}

char	*ft_strndup(char *src, int size)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc (sizeof (char) * size + 1);
	if (dup == NULL)
		return (0);
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;
	int		ischar;

	i = 0;
	j = 0;
	split = malloc (sizeof(char *) * ft_count(str, charset));
	while (issep(str[i], charset))
		i++;
	while (str[i])
	{
		ischar = 0;
		while (!(issep(str[i], charset)) && str[i])
		{
			ischar++;
			i++;
		}
		if (ischar > 0 && j < ft_count(str, charset))
			split[j++] = ft_strndup((&str[i - ischar]), ischar);
		i++;
	}
	split[j] = 0;
	return (split);
}
