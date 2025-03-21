#include "fractol_bonus.h"

int	ft_valid(int ac, char **av)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (ac == 2)
		return (1);
	if (ac > 2)
	{
        while ((av[2][i] >= 9 && av[2][i] <= 13) || av[2][i] == ' ')
            i++;
        while (av[2][i] == '-' || av[2][i] == '+')
			i++;
		while (av[2][i])
		{
			if (av[2][i] == '.')
            {
                if (i == 0 || av[2][i - 1] > '9' || av[2][i - 1] < '0' || !av[2][i + 1] || av[2][i + 1] > '9' || av[2][i + 1] < '0')
                    return (0);
				c++;
            }
			if (((av[2][i] < '0' || av[2][i] > '9') && av[2][i] != '.')  || c > 1)
				return (0);
			i++;
		}
	}
	if (ac == 4)
		return (ft_valid(ac - 1, &av[1]));
	return (1);
}
