/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 10:04:58 by exam              #+#    #+#             */
/*   Updated: 2019/03/19 10:28:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		return ;
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
		return ;
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int		ft_atoi(char *str)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - 48;
		else
			return (-1);
		i++;
	}
	return (nb);
}

void	tab_mult(int nb)
{
	int i;

	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putchar('x');
		ft_putchar(' ');
		ft_putnbr(nb);
		ft_putchar(' ');
		ft_putchar('=');
		ft_putchar(' ');
		ft_putnbr(i * nb);
		ft_putchar('\n');
		i++;
	}
}



int		main(int argc, char **argv)
{
	int nb;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	nb = ft_atoi(argv[1]);
	if (nb < 0)
	{
		ft_putchar('\n');
		return (0);
	}
	tab_mult(nb);
	return (0);
}
