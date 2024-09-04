#include <stdio.h>
#include "../inc/push_swap.h"

int main()
{
//	t_list *stack_a = parse_numbers(4, ft_split("3 4 2 1", ' '));
	t_list *stack_a = ft_lstnew(3);
	ft_lstadd_back(&stack_a, ft_lstnew(4));
	ft_lstadd_back(&stack_a, ft_lstnew(2));
	ft_lstadd_back(&stack_a, ft_lstnew(1));
	print_stack(&stack_a);
	int size = ft_lstsize(stack_a);
	int *array = list_to_array(stack_a);
	insertion_sort(array, size);
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
	indexer(stack_a, array, size);
	for (int i = 0; i < size; i++)
	{
		printf("value = %d --- index = %d\n", stack_a->content, stack_a->index);
		stack_a = stack_a->next;
	}
	return (0);
}
