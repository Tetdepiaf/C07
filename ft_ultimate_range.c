/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:25:40 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/16 16:25:42 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	r;
	int	i;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	r = max - min;
	*range = malloc (sizeof (int) * r);
	if (*range == NULL)
	{
		range = NULL;
		return (-1);
	}
	i = 0;
	if (*range == NULL)
		return (-1);
	while (min < max)
		(*range)[i++] = min++;
	return (r);
}
