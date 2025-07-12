#include <getstr.h>
#include <stdio.h>

int main()
{
	str string = getstrf("Prompt: ");
	printf("Input: %s\n", string);
	
	return 0;
}

// gcc -I .\include -L .\lib .\main.c -o main -lgetstr
// .\main
