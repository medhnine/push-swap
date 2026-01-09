/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhnine <mohhnine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:20:44 by mohhnine          #+#    #+#             */
/*   Updated: 2026/01/09 02:44:07 by mohhnine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	add_back(s_slot **target, s_slot *node)
{
	s_slot	*track;

	if (!node)
		return ;
	if (!*target)
	{
		*target = node;
		return ;
	}
	track = *target;
	while (track->next)
		track = track->next;
	track->next = node;
}

s_slot	*add_new(int value)
{
	s_slot	*new;

	new = malloc(sizeof(s_slot));
	new->value = value;
	new->next = NULL;
	return (new);
}

void	indexing_nodes(s_slot **head)
{
	s_slot	*track;
	s_slot	*check;
	int		index;

	track = *head;
	while (track)
	{
		check = *head;
		index = 0;
		while (check)
		{
			if (track->value > check->value)
				index++;
			check = check->next;
		}
		track->index = index;
		track = track->next;
	}
}

int	find_current_max(s_slot *b_addr, int max)
{
	int	pos;

	pos = 0;
	while (b_addr)
	{
		if (b_addr->index == max)
		{
			return (pos);
		}
		pos++;
		b_addr = b_addr->next;
	}
	return (0);
}
