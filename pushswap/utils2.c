#include "pushswap.h"

int find_max(list **stack)
{
	list *curent;
	int max;

	curent = (*stack);
	max = curent->value;
	while(curent->next != NULL)
	{
		if (curent->next->value > max)
		{
			max = curent->next->value;
		}
		curent = curent->next;
	}
	return (max);
}

int find_min(list **stack)
{
	list *curent;
	int min;

	curent = (*stack);
	min = curent->value;
	while(curent->next != NULL)
	{
		if (curent->next->value < min)
		{
			min = curent->next->value;
		}
		curent = curent->next;
	}
	return (min);
}

int find_max_position(list *stack)
{
    int max_pos = 0;
    int pos = 0;
    int max_value = stack->value;
    list *current = stack;

    while (current)
    {
        if (current->value > max_value)
        {
            max_value = current->value;
            max_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return max_pos;
}

int find_min_position(list *stack)
{
    int min_pos = 0;
    int pos = 0;
    int min_value = stack->value;
    list *current = stack;

    while (current)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return min_pos;
}

int stack_size(list *stack)
{
    int size = 0;
    list *current = stack;

    while (current != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}