/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:15:16 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/30 09:41:23 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char 	*ret;
	int		i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		count_digits(int nb, int base)
{
	int count;

	count = 0;
	while (nb != 0)
	{
		nb /= base;
		count++;
	}
	return (count);
}

char	*ft_itoabase(int nb, int base)
{
	char			*radix;
	char			*ret;
	unsigned int	u_value;
	int				k;
	int				i;

	k = 0;
	radix = ft_strdup("0123456789abcdef");
	if (nb == 0)
		return ("0");
	if (nb < 0 && base == 10)
	{
		u_value = -nb;
		k = 1;
	}
	i = count_digits(nb, base) + k;
	if (!(ret = (char *)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	if (k == 1)
		ret[0] = '-';
	ret[i] = '\0';
	i--;
	while (i >= k)
	{
		ret[i] = radix[u_value % base];
		u_value /= base;
		i--;
	}
	return (ret);
}

/* without itoabase */

char *radix = "0123456789abcdef";

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putaff(unsigned char c)
{
	if (c > 31 && c < 127)
		ft_putchar(c);
	else
		ft_putchar('.');
}

void	ft_puthexa(unsigned char c)
{
		ft_putchar(radix[c / 16]);
		ft_putchar(radix[c % 16]);
}

void	print_line(const void *addr, size_t size)
{
	size_t i;
	size_t end;
	const char *ptr = addr;

	i = 0;
	while (i < size)
	{
		while (j < 16 && i + j < size)
		{
			ft_puthexa(addr[i]);
			if (i % 2)
		}
	}
}
