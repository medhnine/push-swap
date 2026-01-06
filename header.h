#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct stack_slot
{
	int					value;
	int					index;
	int					largest;
	int					min;
	int					max;	
	struct stack_slot   *next;
}                       s_slot;

typedef struct la_balena
{
	int     size;
	s_slot  *top;
}       s_container;

// void    push_swap(int ac, char **av);
void    make_structure(s_slot **head, char **av);
int     count_words(char *str);
char    **ft_split(char *str);
int     is_separtor(char c);
void    move_to_exucte(char *move_name, s_slot **a_addr, s_slot **b_addr, int check);
#endif