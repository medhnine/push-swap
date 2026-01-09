/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhnine <mohhnine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:20:28 by mohhnine          #+#    #+#             */
/*   Updated: 2026/01/09 02:43:34 by mohhnine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clean_up_array(char **ptr)
{
	int	move;

	if (ptr == NULL)
		return ;
	move = 0;
	while (ptr[move])
	{
		free(ptr[move]);
		ptr[move] = NULL;
		move++;
	}
	free(ptr);
}

void	clean_up_node(s_slot **node)
{
	s_slot	*tarck;
	s_slot	*temp;

	if (node == NULL)
		return ;
	tarck = *node;
	while (tarck)
	{
		temp = tarck;
		tarck = tarck->next;
		free(temp);
		temp = NULL;
	}
	*node = NULL;
}
