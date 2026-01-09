/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhnine <mohhnine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:21:11 by mohhnine          #+#    #+#             */
/*   Updated: 2026/01/09 02:48:31 by mohhnine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void	push_top_of_a(s_slot **a_addr, s_slot **b_addr, int check)
{
	s_slot	*track;

	if (!(*a_addr))
		return ;
	track = (*a_addr);
	(*a_addr) = (*a_addr)->next;
	track->next = (*b_addr);
	(*b_addr) = track;
	if (check == 0)
		write(1, "pb\n", 3);
}

void	rotate_stack_a(s_slot **a_addr, int check)
{
	s_slot	*track;
	s_slot	*temp;

	if (size_of_stack(*a_addr) <= 1)
		return ;
	temp = (*a_addr);
	track = (*a_addr);
	while (track->next)
		track = track->next;
	track->next = (*a_addr);
	(*a_addr) = (*a_addr)->next;
	temp->next = NULL;
	if (check == 0)
		write(1, "ra\n", 3);
}

void	reverse_rotate_a(s_slot **a_addr, int check)
{
	s_slot	*prev;
	s_slot	*last;

	if (size_of_stack(*a_addr) < 2)
		return ;
	prev = NULL;
	last = (*a_addr);
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = (*a_addr);
	(*a_addr) = last;
	if (check == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_a_and_b(s_slot **a_addr, s_slot **b_addr)
{
	reverse_rotate_a(a_addr, 1);
	reverse_rotate_b(b_addr, 1);
	write(1, "rrr\n", 4);
}

void	double_move(char *fisrt, char *second, int check, s_slot **addr)
{
	move_to_exucte(fisrt, addr, addr, check);
	move_to_exucte(second, addr, addr, check);
}
