/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:24:27 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/22 06:26:23 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	ft_squipe(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	return (i);
}

int	ft_valid(int ac, char **av)
{
	int	i;
	int	c;

	if (ac > 2)
	{
		i = ((c = 0), ft_squipe(av[2]));
		while (av[2][i])
		{
			if (av[2][i] == '.')
			{
				if (i == 0 || av[2][i - 1] > '9' || av[2][i - 1] < '0'
					|| !av[2][i + 1] || av[2][i + 1] > '9' || av[2][i
					+ 1] < '0')
					return (0);
				c++;
			}
			if (((av[2][i] < '0' || av[2][i] > '9') && av[2][i] != '.')
				|| c > 1)
				return (0);
			i++;
		}
	}
	if (ac == 4)
		return (ft_valid(ac - 1, &av[1]));
	return (1);
}
