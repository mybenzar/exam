/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:19:08 by exam              #+#    #+#             */
/*   Updated: 2019/03/12 12:00:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_white_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f' || c == ' ')
		return (1);
	else
		return (0);
}

int		count_words(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (is_white_space(str[i]))
			i++;
		if (!is_white_space(str[i]) && str[i])
			j++;
		while (!is_white_space(str[i]) && str[i])
			i++;
	}
	return (j);
}

char	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **tab;

	i = 0;
	k = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 2064)))
		return (NULL);
	while (str[i] != '\0' && k < count_words(str))
	{
		j = 0;
		if (!(tab[k] = (char *)malloc(sizeof(char) * 258)))
			return (NULL);
		while (is_white_space(str[i]))
			i++;
		while (!is_white_space(str[i]) && str[i])
		{
			tab[k][j] = str[i];
			j++;
			i++;
		}
		tab[k][j] = '\0';
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
