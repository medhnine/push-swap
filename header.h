/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhnine <mohhnine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:21:27 by mohhnine          #+#    #+#             */
/*   Updated: 2026/01/09 02:50:20 by mohhnine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_slot
{
	int					value;
	int					index;
	int					largest;
	int					min;
	int					max;
	struct stack_slot	*next;
}						s_slot;

int						ft_strcmp(const char *s1, const char *s2);
int						size_of_stack(s_slot *start);
void					make_structure(s_slot **head, char **av);
int						count_words(char *str);
char					**ft_split(char *str);
int						is_separtor(char c);
void					move_to_exucte(char *move_name, s_slot **a_addr,
							s_slot **b_addr, int check);
void					parssing_input(char **av, s_slot **a_addr);
void					clean_up_array(char **ptr);
void					clean_up_node(s_slot **node);
int						find_current_max(s_slot *b_addr, int max);
void					indexing_nodes(s_slot **head);
int						size_of_stack(s_slot *start);
int						ft_atoi(char *str, s_slot **head, char **ptr);
void					move_to_exucte(char *move_name, s_slot **a_addr,
							s_slot **b_addr, int check);
void					add_back(s_slot **target, s_slot *node);
s_slot					*add_new(int value);
void					swap_stack_a(s_slot **a_addr, int check);
void					swap_stack_b(s_slot **b_addr, int check);
void					swap_stack_a_and_b(s_slot **a_addr, s_slot **b_addr);
void					push_top_of_a(s_slot **a_addr, s_slot **b_addr,
							int check);
void					push_top_of_b(s_slot **a_addr, s_slot **b_addr,
							int check);
void					rotate_stack_a(s_slot **a_addr, int check);
void					rotate_stack_b(s_slot **b_addr, int check);
void					rotate_stack_a_and_b(s_slot **a_addr, s_slot **b_addr);
void					reverse_rotate_a(s_slot **a_addr, int check);
void					reverse_rotate_b(s_slot **b_addr, int check);
void					reverse_rotate_a_and_b(s_slot **a_addr,
							s_slot **b_addr);
void					double_move(char *fisrt, char *second, int check,
							s_slot **addr);
void					sort_five(s_slot **a_addr, s_slot **b_addr);
void					sort_three(s_slot **a_addr);
void					sort_four(s_slot **a_addr, s_slot **b_addr);
void					sort_under_five(s_slot **a_addr, s_slot **b_addr,
							int size);
#endif