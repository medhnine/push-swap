/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhnine <mohhnine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:20:52 by mohhnine          #+#    #+#             */
/*   Updated: 2026/01/09 02:49:31 by mohhnine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	size_of_stack(s_slot *start)
{
	int	count;

	count = 0;
	while (start)
	{
		count++;
		start = start->next;
	}
	return (count);
}

void	swap_stack_a(s_slot **a_addr, int check)
{
	s_slot	*temp;

	if (!(*a_addr) || !(*a_addr)->next)
		return ;
	temp = (*a_addr)->next;
	(*a_addr)->next = temp->next;
	temp->next = (*a_addr);
	(*a_addr) = temp;
	if (check == 0)
		write(1, "sa\n", 3);
}

void	swap_stack_b(s_slot **b_addr, int check)
{
	s_slot	*temp;

	if (size_of_stack(*b_addr) == 1)
		return ;
	temp = (*b_addr)->next;
	(*b_addr)->next = temp->next;
	temp->next = (*b_addr);
	(*b_addr) = temp;
	if (check == 0)
		write(1, "sb\n", 3);
}

void	swap_stack_a_and_b(s_slot **a_addr, s_slot **b_addr)
{
	if (size_of_stack(*a_addr) == 1 && size_of_stack(*b_addr) == 1)
		return ;
	swap_stack_a(a_addr, 1);
	swap_stack_b(b_addr, 1);
	write(1, "ss\n", 3);
}

void	move_to_exucte(char *move_name, s_slot **a_addr, s_slot **b_addr,
		int check)
{
	if (ft_strcmp(move_name, "sa") == 0)
		swap_stack_a(a_addr, check);
	else if (ft_strcmp(move_name, "sb") == 0)
		swap_stack_b(b_addr, check);
	else if (ft_strcmp(move_name, "pb") == 0)
		push_top_of_a(a_addr, b_addr, check);
	else if (ft_strcmp(move_name, "pa") == 0)
		push_top_of_b(a_addr, b_addr, check);
	else if (ft_strcmp(move_name, "ra") == 0)
		rotate_stack_a(a_addr, check);
	else if (ft_strcmp(move_name, "rb") == 0)
		rotate_stack_b(b_addr, check);
	else if (ft_strcmp(move_name, "rr") == 0)
		rotate_stack_a_and_b(a_addr, b_addr);
	else if (ft_strcmp(move_name, "rra") == 0)
		reverse_rotate_a(a_addr, check);
	else if (ft_strcmp(move_name, "rrb") == 0)
		reverse_rotate_b(b_addr, check);
	else if (ft_strcmp(move_name, "rrr") == 0)
		reverse_rotate_a_and_b(a_addr, b_addr);
}
