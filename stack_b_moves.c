/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhnine <mohhnine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:21:14 by mohhnine          #+#    #+#             */
/*   Updated: 2026/01/09 02:49:21 by mohhnine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_top_of_b(s_slot **a_addr, s_slot **b_addr, int check)
{
	s_slot	*track;

	if (!(*b_addr))
		return ;
	track = (*b_addr);
	(*b_addr) = (*b_addr)->next;
	track->next = (*a_addr);
	(*a_addr) = track;
	if (check == 0)
		write(1, "pa\n", 3);
}

void	rotate_stack_b(s_slot **b_addr, int check)
{
	s_slot	*track;
	s_slot	*temp;

	if (size_of_stack(*b_addr) <= 1)
		return ;
	temp = (*b_addr);
	track = (*b_addr);
	while (track->next)
		track = track->next;
	track->next = (*b_addr);
	(*b_addr) = (*b_addr)->next;
	temp->next = NULL;
	if (check == 0)
		write(1, "rb\n", 3);
}

void	reverse_rotate_b(s_slot **b_addr, int check)
{
	s_slot	*prev;
	s_slot	*last;

	if (size_of_stack((*b_addr)) < 2)
		return ;
	prev = NULL;
	last = (*b_addr);
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = (*b_addr);
	(*b_addr) = last;
	if (check == 0)
		write(1, "rrb\n", 4);
}

void	rotate_stack_a_and_b(s_slot **a_addr, s_slot **b_addr)
{
	rotate_stack_a(a_addr, 1);
	rotate_stack_b(b_addr, 1);
	write(1, "rr\n", 3);
}
