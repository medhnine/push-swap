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
	return ;
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
	char **hold;
	int n_word;
	if (!str)
		return (NULL);
	n_word = count_words(str);
	hold = malloc(sizeof(char *) * (n_word + 1));
	if (!hold)
		return (NULL);
	if (allocate_n_bytes(str, hold, n_word) == 0)
		return (NULL);
	fill_in(str, hold);
	return (hold);
}