#include "../inc/push_swap.h"
#include <stdio.h>

int is_number(char *str);
int is_duplicated(int num, int *array, int tam);
int valid_input(int argc, char **argv);
//t_stack **parse(int argc, char **argv);

void valid_input_test(int argc, char **argv)
{
	//char *test = "valid normal input";
	//printf("%s\n", test);
	if (valid_input(argc, argv))
		printf("OK\n");
	else
		printf("KO\n");
}

int main(int argc, char **argv)
{
	valid_input_test(argc, argv);
	return (0);
}
