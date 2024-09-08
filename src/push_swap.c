#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (current == NULL)
	{
		printf("A pilha está vazia.\n");
		return ;
	}
	while (current != NULL)
	{
		printf("%d\n", current->number);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (!validate_arguments(argc, argv))
	{
		if (argc < 2)
			return (0);
		ft_error();
	}
	stack_a = init_stack(argc, argv);
	if (check_stack_duplicates(stack_a))
	{
		ft_free_stack(&stack_a);
		ft_error();
	}
	if (!stack_is_sorted(stack_a))
	{
		ft_sorted(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	return (0);
}