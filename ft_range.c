/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:57:58 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/16 14:58:00 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	r;
	int	*tab;

	if (min >= max)
		return (0);
	r = max - min;
	tab = malloc (sizeof (int) * r);
	while (min != max)
		*(tab++) = min++;
	return (tab - r);
}
