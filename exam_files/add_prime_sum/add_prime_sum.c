/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:06:34 by exam              #+#    #+#             */
/*   Updated: 2019/03/12 11:12:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb == 0 || nb == 1)
		return (0);
	while (i <= nb && nb % i != 0)
			i++;
	if (i != nb)
		return (0);
	else
		return (1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
		return ;
	}
	if (nb >= 10) 
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	ft_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb);
}

int	add_prime_sum(int nb)
{
	int i;
	int sum;

	i = 2;
	sum = 0;
	while (i <= nb)
	{
		if (ft_is_prime(i))
			sum = sum + i;
		i++;
	}
	return (sum);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !ft_isdigit(argv[1]))
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (0);
	}
	ft_putnbr(add_prime_sum(ft_atoi(argv[1])));
	ft_putchar('\n');
	return (1);
}
