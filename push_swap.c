/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhnine <mohhnine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:21:04 by mohhnine          #+#    #+#             */
/*   Updated: 2026/01/09 02:44:27 by mohhnine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_three(s_slot **a_addr)
{
	s_slot	*track;

	int first, (second), (third);
	track = (*a_addr);
	first = track->value;
	second = track->next->value;
	third = track->next->next->value;
	if (first < second && second > third && third < first)
		move_to_exucte("rra", a_addr, NULL, 0);
	else if (first < second && second > third && third > first)
		double_move("rra", "sa", 0, a_addr);
	else if (first > second && second < third && third > first)
		move_to_exucte("sa", a_addr, NULL, 0);
	else if (first > second && second > third)
		double_move("sa", "rra", 0, a_addr);
	else if (first > second && second < third)
		double_move("rra", "rra", 0, a_addr);
}

void	sort_stack_a(s_slot **a_addr, s_slot **b_addr, int max)
{
	int pos, (cost), (size);
	while ((*b_addr))
	{
		pos = find_current_max((*b_addr), max);
		size = size_of_stack((*b_addr));
		cost = size / 2;
		if ((*b_addr)->index == max)
		{
			move_to_exucte("pa", a_addr, b_addr, 0);
			max--;
		}
		else if (pos <= cost)
		{
			move_to_exucte("rb", a_addr, b_addr, 0);
		}
		else
			move_to_exucte("rrb", a_addr, b_addr, 0);
	}
}

void	sort_others(s_slot **a_addr, s_slot **b_addr, int chunk_size)
{
	int	min;

	min = 0;
	while ((*a_addr))
	{
		if ((*a_addr)->index <= min)
		{
			move_to_exucte("pb", a_addr, b_addr, 0);
			move_to_exucte("rb", a_addr, b_addr, 0);
			min++;
		}
		else if (((*a_addr)->index <= min + chunk_size))
		{
			move_to_exucte("pb", a_addr, b_addr, 0);
			min++;
		}
		else
			move_to_exucte("ra", a_addr, b_addr, 0);
	}
}

int	main(int ac, char **av)
{
	s_slot	*head, (*b_addr);

	int size, (chunk_size), (max);
	if (ac == 1)
		exit(1);
	chunk_size = 1;
	head = NULL;
	b_addr = NULL;
	parssing_input(av, &head);
	indexing_nodes(&head);
	size = size_of_stack(head);
	if (size <= 5)
		sort_under_five(&head, &b_addr, size);
	head->largest = size - 1;
	max = head->largest;
	if (size <= 100 && size > 3)
		chunk_size = 15;
	else if (size <= 500 && size > 100)
		chunk_size = 30;
	sort_others(&head, &b_addr, chunk_size);
	sort_stack_a(&head, &b_addr, max);
	clean_up_node(&head);
	return (0);
}
