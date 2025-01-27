#include "pushswap.h"

int **set_chunk(int min, int max, int nb_chunk)
{
	int **chunks;
	int interval;
	int i;

	i = 0;
	chunks = malloc((sizeof (int*) * nb_chunk));
	if (!chunks)
        return (NULL);
	interval = (max - min + 1) / nb_chunk;
	while(i < nb_chunk)
	{
		chunks[i] = malloc((sizeof (int*) * 2));
		if (!chunks[i])
		{
			while(i < 0)
			{
				free(chunks[i]);
				i--;
			}
			free(chunks);
			return (NULL);
			if (i == nb_chunk - 1)
				chunks[i][1] = max;
			else
				chunks[i][1] = min + interval;
		}
		min = min + interval;
		i++;
	}
	return (chunks);
}
int find_position(list **stack_a, int value)
{
    list *current = *stack_a;
    int pos = 0;

    while (current != NULL)
    {
        if (current->value == value)
            return pos;
        current = current->next;
        pos++;
    }
    return -1;
}
void first_step(list **stack_a, list **stack_b, int **chunk, int i)
{
	list *current;
	int pos;
	int size_a;

	current = (*stack_a);
	while (current != NULL)
    {
		size_a = stack_size(*stack_a);
        if (current->value >= chunk[i][0] && current->value < chunk[i][1])
        {
            pos = find_position(stack_a, current->value);
            if (pos <= size_a / 2)
            {
                while (pos-- > 0)
                    ra(stack_a);
            }
            else
            {
                pos = size_a - pos;
                while (pos-- > 0)
                    rra(stack_a);
            }
            pb(stack_a, stack_b);
            i++;
            if (i == 5)
                break;
        }
        current = current->next;
    }
}

void free_chunk(int **chunk, int size)
{
    int i;

    if (chunk)
    {
        for (i = 0; i < size; i++)
        {
            free(chunk[i]);
        }
        free(chunk);
    }
}