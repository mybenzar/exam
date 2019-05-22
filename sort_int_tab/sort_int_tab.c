/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 10:32:57 by exam              #+#    #+#             */
/*   Updated: 2019/03/19 11:27:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int tmp;
	unsigned int j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (i + j < size)
		{
			if (tab[i] > tab[i + j])
			{
				tmp = tab[i];
				tab[i] = tab[i + j];
				tab[i + j] = tmp;
			}
			j++;
		}
		i++;
	}
}
