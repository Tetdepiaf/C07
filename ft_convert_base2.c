/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:25:50 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/21 15:25:52 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_size(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-'
				|| base[i] < 32 || base[i] == 127)
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (i);
}

int	index_base(char *str, char *base, int i)
{
	int	j;

	j = 0;
	while (base[j])
	{
		if (base[j] == str[i])
			return (j);
		j++;
	}
	return (-1);
}

int	index_start(char *str, int *neg)
{
	int	i;

	i = 0;
	*neg = 1;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			*neg = -1 * *neg;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int		size;
	int		res;
	int		i;
	int		j;
	int		neg;

	size = base_size(base);
	if (size < 2)
		return (0);
	i = index_start(str, &neg);
	res = 0;
	while (str[i] >= 32 && str[i] < 127 && str[i] != '-' && str[i] != '+')
	{
		j = index_base(str, base, i);
		if (j < 0)
			return (res * neg);
		res = res * size + j;
		i++;
	}
	return (res * neg);
}
