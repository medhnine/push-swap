/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhnine <mohhnine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:20:58 by mohhnine          #+#    #+#             */
/*   Updated: 2026/01/09 01:28:04 by mohhnine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_sorted(s_slot *a_addr)
{
	s_slot	*track;
	s_slot	*check;

	track = a_addr;
	while (track->next)
	{
		check = track;
		while (check->next)
		{
			check = check->next;
			if (track->value > check->value)
				return (1);
		}
		track = track->next;
	}
	return (0);
}

static int	check_duplicated_number(s_slot *head)
{
	s_slot	*track;
	s_slot	*check;

	track = head;
	while (track->next)
	{
		check = track;
		while (check->next)
		{
			check = check->next;
			if (check->value == track->value)
				return (1);
		}
		track = track->next;
	}
	return (0);
}

void	make_structure(s_slot **head, char **av)
{
	s_slot	*track;
	char	**ptr;

	int move, (i), (value);
	*head = NULL;
	move = 1;
	while (av[move])
	{
		i = 0;
		ptr = ft_split(av[move]);
		if (!ptr || ptr[i] == NULL || ptr[i][0] == '\0')
		{
			if (move > 1)
				clean_up_array(ptr);
			exit(1);
		}
		while (ptr[i])
		{
			value = ft_atoi(ptr[i++], head, ptr);
			track = add_new(value);
			add_back(head, track);
		}
		clean_up_array(ptr);
		move++;
	}
}

static int	check_validty(char **av)
{
	int i, (x);
	i = 1;
	while (av[i])
	{
		x = 0;
		if (av[i][x] == '\0')
			return (0);
		while (av[i][x])
		{
			if (av[i][x] == '-' || av[i][x] == '+')
			{
				x++;
				if ((av[i][x] >= '0' && av[i][x] <= '9'))
					x++;
				else
					return (0);
			}
			else if ((av[i][x] >= '0' && av[i][x] <= '9')
				|| is_separtor(av[i][x]) == 1)
				x++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	parssing_input(char **av, s_slot **a_addr)
{
	int	size;

	if (av[1][0] == '\0' || check_validty(av) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	make_structure(a_addr, av);
	size = size_of_stack((*a_addr));
	if (check_duplicated_number((*a_addr)) == 1)
	{
		clean_up_node(a_addr);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (size <= 1 || is_sorted((*a_addr)) == 0)
	{
		clean_up_node(a_addr);
		exit(1);
	}
	if (is_sorted((*a_addr)) == 0)
		exit(1);
	indexing_nodes(a_addr);
}
