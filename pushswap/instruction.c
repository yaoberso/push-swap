typedef struct list {
	value;
	struct list *next;
} list;

void sa(list *current)
{
	if (!current || !current->next)
		return ;
	int temp;
	temp = current->value;
	current->value = current->next->pile_a;
	current->next->pile_a = temp;
}

void sb(list *current)
{
	if (!current || !current->next)
		return ;
	int temp;
	temp = current->pile_b;
	current->pile_b = current->next->pile_b;
	current->next->pile_b = temp;
}
void ss(list *current)
{
	sb(current);
	sa(current);
}
void pa(list **stack_a, list **stack_b)
{
	list *temp;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}
void pb(list *current)
{
	
}
void ra(list *current)
{
	
}
void rb(list *current)
{
	
}
void rr(list *current)
{
	
}
void rra(list *current)
{
	
}
void rrb(list *current)
{
	
}
void rrr(list *current)
{
	
}