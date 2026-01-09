/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhnine <mohhnine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:20:40 by mohhnine          #+#    #+#             */
/*   Updated: 2026/01/08 00:58:53 by mohhnine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	clean_up(char **target, int n_elemets)
{
	int	i;

	i = 0;
	while (i < n_elemets)
	{
		free(target[i]);
		target[i] = NULL;
		i++;
	}
}

static void	fill_in(char *str, char **target)
{
	int n_bytes, (move), (index);
	move = 0;
	index = 0;
	while (str[index])
	{
		n_bytes = 0;
		while (str[index] && is_separtor(str[index]) == 0)
		{
			target[move][n_bytes] = str[index];
			index++;
			n_bytes++;
		}
		if (n_bytes > 0)
		{
			target[move][n_bytes] = '\0';
			move++;
		}
		else
			index++;
	}
}

static int	allocate_n_bytes(char *str, char **target, int n_elemets)
{
	int n_bytes, (move), (index);
	move = 0;
	index = 0;
	while (str[index] && move < n_elemets)
	{
		n_bytes = 0;
		while (str[index] && is_separtor(str[index]) == 0)
		{
			index++;
			n_bytes++;
		}
		if (n_bytes > 0)
		{
			target[move] = malloc(sizeof(char) * n_bytes + 1);
			if (!target[move])
				return (clean_up(target, move), 0);
			move++;
		}
		else
			index++;
	}
	return (1);
}

char	**ft_split(char *str)
{
	char	**hold;
	int		n_word;

	if (!str)
		return (NULL);
	if (str[0] == '\0')
		return (NULL);
	n_word = count_words(str);
	if (n_word == 0)
		write(2, "Error\n", 6);
	hold = malloc(sizeof(char *) * (n_word + 1));
	if (!hold)
		return (NULL);
	if (allocate_n_bytes(str, hold, n_word) == 0)
		return (NULL);
	fill_in(str, hold);
	return (hold);
}
