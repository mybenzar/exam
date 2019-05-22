/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:03:45 by exam              #+#    #+#             */
/*   Updated: 2019/04/02 11:26:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		numlen(unsigned int nb)
{
	int i;
	
	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_strcat(char *s1, char *s2)
{
	int i;
	int j;
	char *str;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*uitoa(unsigned int nb)
{
	char *str;
	int i;
	int len;

	len = numlen(nb);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[i] = nb % 10 + 48;
		i--;
		nb /= 10;
	}
	return (str);
}

char	*moment(unsigned int duration)
{
	if (duration == 1)
		return (ft_strcat("1 second ago", "."));
	else if (duration < 60)
		return (ft_strcat(uitoa(duration), " seconds ago."));
	else if (duration < 120)
		return (ft_strcat("1 minute ago", "."));
	else if (duration < 3600)
		return (ft_strcat(uitoa(duration / 60), " minutes ago."));
	else if (duration < 7400)
		return (ft_strcat("1 hour ago", "."));
	else if (duration < 86400)
		return (ft_strcat(uitoa(duration / 3600), " hours ago."));
	else if (duration < 172800)
		return (ft_strcat("1 day ago", "."));
	else if (duration < 2592000)
		return (ft_strcat(uitoa(duration / 86400), " days ago."));
	else if (duration < 5184000)
		return (ft_strcat("1 month ago", "."));
	else
		return (ft_strcat(uitoa(duration / 2592000), " months ago."));
}
