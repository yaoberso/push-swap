#include "pushswap.h"

int	count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (count);
}

static char	*allocate_word(char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		i;
	int		word_index;
	int		start;
	char	**tab_word;

	if (str == NULL)
		return (NULL);
	tab_word = malloc((count_word(str) + 1) * sizeof(char *));
	if (tab_word == NULL)
		return (NULL);
	i = 0;
	word_index = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > start)
			tab_word[word_index++] = allocate_word(str, start, i);
	}
	tab_word[word_index] = NULL;
	return (tab_word);
}

int	ft_count(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] != NULL)
	{
		i++;
	}
	return (i);
}

void	free_split(char **split)
{
    int	i;

	i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
