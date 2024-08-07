#include "../inc/push_swap.h"
#include <stdio.h>

void	swap_ideal_test()
{
	t_list *stack_a = parse_numbers(4, ft_split("3 4 2 1", ' ')); //FIX THIS AWFUL TEST
	print_stack(&stack_a);
	printf("-------------AFTER-------------\n");
	swap(&stack_a, 'a');
	print_stack(&stack_a);
}

//TEST INVALID STACK SIZES OR BIG NUMBERS

int main()
{
	swap_ideal_test();
	return (0);
}
