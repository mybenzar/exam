/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:04:59 by exam              #+#    #+#             */
/*   Updated: 2019/04/16 11:27:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

# include <stdio.h>

int		count_digits(int value, int base)
{
	int count;

	count = 0;
	while (value != 0)
	{
		value /= base;
		count++;
	}
	return (count);
}

int		ft_strlen(char *s)
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
	if (!(ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_itoa_base(int value, int base)
{
	char	*radix;
	char 	*nb_str;
	int		i;
	unsigned int u_value;
	int		k;

	k = 0;
	radix = ft_strdup("0123456789ABCDEF");
	if (value == 0)
		return ("0");
	if (value < 0 && base == 10)
	{
		u_value = - value;
		k = 1;
	}
	else
		u_value = value;
	i = count_digits(value, base) + k;
	printf("i = %d\n", i);
	if (!(nb_str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (k == 1)
		nb_str[0] = '-';
	nb_str[i] = '\0';
	i--;
	while (i >= k)
	{
		nb_str[i] = radix[u_value % base];
		printf("coucou\n");
		u_value = u_value / base;
		i--;
	}
	return (nb_str);
}

int main(void)
{
	printf("%s\n", ft_itoa_base(0, 2));
	return (1);
}
