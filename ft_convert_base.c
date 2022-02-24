/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:07:04 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/16 20:07:07 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	base_size(char *base);

void	ft_rev_tab(char *tab)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = '0';
	while (tab[i])
		i++;
	while (j < i / 2)
	{
		c = tab[j];
		tab[j] = tab[i - 1 - j];
		tab[i - 1 - j] = c;
		j++;
	}
}

int	ft_putnbr_base(int nbr, char *base, char *dest)
{
	long int	size;
	long int	nbr2;
	int			i;

	i = 0;
	size = base_size(base);
	if (size < 2)
		return (0);
	if (nbr < 0)
	{
		*(dest++) = '-';
		nbr2 = nbr;
		nbr2 = -nbr2;
		i++;
	}
	else
		nbr2 = nbr;
	if (nbr2 >= size)
		ft_putnbr_base(nbr2 / size, base, dest + 1);
	*(dest) = base[nbr2 % size];
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		nb;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * 34);
	while (res[i])
	{
		res[i] = 0;
		i++;
	}
	nb = ft_atoi_base(nbr, base_from);
	i = ft_putnbr_base(nb, base_to, res);
	if (i == 0)
		ft_rev_tab(res);
	else
		ft_rev_tab(res + 1);
	return (res);
}
