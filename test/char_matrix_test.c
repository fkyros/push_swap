#include "../inc/push_swap.h"
#include <stdio.h>
#include <string.h>

void test_get_input_as_char_matrix()
{
	char *arr0 = "./push_swap";
	char *arr1 = "23";
	char *arr2 = " +45 ";
	char *arr3 = "  1j   7 ";

	int argc = 4;
	char *argv[] = {arr0, arr1, arr2, arr3};
	char **res = get_input_as_char_matrix(argc, argv);
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", res[i]);
		/*if (!strcmp(res[i], "23"))
			printf("%s == 23 ✅\n", res[i]);
		else
			printf("%s == 23 ✅\n", res[i]);*/ //TODO: make expected result to compare
		free(res[i]);
	}
	free(res);
}

int main()
{
	test_get_input_as_char_matrix();
	return (0);
}
