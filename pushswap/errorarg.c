#include "pushswap.h"

void checkdbl(char **argv)
{
	int i;
	int j;

	i = 1;
	while(argv[i] != NULL)
	{
		j = i;
		while(argv[j] != NULL)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
			{
				ft_printf("Error\n");
				exit (1);
			}
			i++;
		}
		j++;
	}
}

void checkifalph(char **argv)
{
	int i;
	int j;

	i = 1;
	while(argv[i] != NULL)
	{
		j = 0;
		while(argv[i][j] != '\0')
		{
			if (!(argv[i][j] <= '9' && argv[i][j] >= '0'))
			{
				ft_printf("Error\n");
				exit (1);
			}
			i++;
		}
		j++;
	}
}
void check_error(char **argv)
{
	checkdbl(argv);
	checkifalph(argv);
}