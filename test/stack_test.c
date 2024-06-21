#include <stdio.h>
#include "../inc/stack.h"

void stack_new_test()
{
	t_stack *x;

	x = stack_new(1);
	if (x->content == 1 && x->below == NULL)
		printf("STACK_NEW OK\n");
	else
		printf("STACK_NEW KO\n");
	free_stack(x);
}

void push_test()
{
	t_stack *x;

	x = stack_new(1);
	x = push(x, 2);

	if (peek(x) == 2 && x->below->content == 1)
		printf("PUSH OK\n");
	else
		printf("PUSH KO\n");
	free_stack(x);
}

void size_test()
{
	t_stack *x;

	x = stack_new(1);
	x = push(x, 2);
	x = push(x, 3);

	if (size(x) == 3)
		printf("SIZE OK\n");
	else
		printf("SIZE KO\n");
	free_stack(x);
}

void pop_test()
{
	t_stack *x;
	int mid = 2;

	x = stack_new(1);
	x = push(x, mid);
	x = push(x, 3);
	x = pop(x);

	if (x->content == mid)
		printf("POP OK\n");
	else
		printf("POP KO\n");
	free_stack(x);
}

void peek_test()
{
	t_stack *x;
	int value = 2;
	
	x = stack_new(1);
	x = push(x, value);
	if (peek(x) == value)
		printf("PEEK OK\n");
	else
		printf("PEEK KO\n");
	free_stack(x);
}

int main()
{
	stack_new_test();
	push_test();
	size_test();
	pop_test();
	peek_test();
}
