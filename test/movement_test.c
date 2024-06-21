#include "../inc/push_swap.h"
#include <stdio.h>

void swap_test()
{
	t_stack	*x;
	int init = 2;

	x = stack_new(init);
	x = push(x, 3);
	x = swap(x);
	if (peek(x) == init)
		printf("SWAP OK\n");
	else
		printf("SWAP KO\n");
	free(x);
}

void rotate_test()
{
	t_stack	*x;
	int subinit = 3;

	x = stack_new(2);
	x = push(x, subinit);
	x = push(x, 4);
	x = rotate(x);
	if (peek(x) == subinit)
		printf("ROTATE OK\n");
	else
		printf("ROTATE KO\n");
}

void rrotate_test()
{
	t_stack	*x;
	int first = 2;

	x = stack_new(first);
	x = push(x, 3);
	x = push(x, 4);
	x = reverse_rotate(x);
	if (peek(x) == first)
		printf("REVERSE ROTATE OK\n");
	else
		printf("REVERSE ROTATE KO\n");
}

int main()
{
	swap_test();
	rotate_test();
	rrotate_test();
	return 0;	
}
