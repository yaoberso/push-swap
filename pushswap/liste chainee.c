#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct list {
	int data;
	struct list *next;
} list;

int main(int argc, char **argv)
{
	int i;
	list *head = NULL;
	list *current = NULL;

	i = 2;
	head = malloc(sizeof(list));
	head->data = atoi(argv[1]);
	head->next = NULL;
	current = head;
	while(i < argc)
	{
		current->next = malloc(sizeof(list));
		current = current->next;
		current->data = atoi(argv[i]);
		current->next = NULL;
		i++;
	}
	i = 0;
	while(i < (argc - 1))
	{
		printf("%i", head->data);
		if (i != (argc - 2))
		{
			printf(" ");
		}
		head = head->next;
		i++;
	}
	return (0);
}