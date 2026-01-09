/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhnine <mohhnine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:20:34 by mohhnine          #+#    #+#             */
/*   Updated: 2026/01/09 02:42:36 by mohhnine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_words(char *str)
{
	int i, (count);
	i = 0;
	while (is_separtor(str[i]) == 1)
		i++;
	count = 0;
	while (str[i])
	{
		if ((is_separtor(str[i]) == 1 && is_separtor(str[i + 1]) == 0) || str[i
			+ 1] == '\0')
			count++;
		i++;
	}
	return (count);
}
