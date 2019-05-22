/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:42:12 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 11:38:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Écrire la fonction suivante:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

Cette fonction doit trier la liste passée en premier paramètre, en utilisant le
pointeur sur fonction cmp pour déterminer l'ordre à appliquer, et
renvoyer un pointeur vers le premier élément de la liste triée.

Les doublons doivent être préservés.

Les entrées seront toujours cohérentes.

Vous devez utiliser le type t_list décrit dans le fichier list.h qui vous est
fourni. Vous devrez inclure (#include "list.h") ce fichier, mais ne pas le
rendre. Nous utiliserons le notre pour compiler votre exercice.

Les fonctions passées en tant que cmp renverront toujours une valeur
différente de 0 si a et b sont dans le bon ordre,
dans le cas contraire elles renverront 0.

Par exemple, la fonction suivante utilisée en tant que cmp devra
permettre de trier la liste par ordre croissant:

int croissant(int a, int b)
{
			return (a <= b);
}
*/

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
		t_list	*head;
		t_list	*end;
		int		tmp;
		int		sorted;

		if (lst == NULL || cmp == NULL)
				return (NULL);
		head = lst;
		end = NULL;
		sorted = 1;
		while (lst && lst->next != end)
		{
				if ((*cmp)(lst->data, (lst->next)->data) == 0)
				{
						sorted = 0;
						tmp = lst->data;
						lst->data = (lst->next)->data;
						(lst->next)->data = tmp;
				}
				lst = lst->next;
				if (lst->next == end && sorted == 0)
				{
						end = lst;
						lst = head;
						sorted = 1;
				}
		}
		return (head);
}
