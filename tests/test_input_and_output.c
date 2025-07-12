#include <getstr.h>

#include <stdio.h>



int main()

{

	// Get Input With Prompt

	printf("----Using Prompt----\n");

	str string = getstrf("Prompt: ");

	printf("Input: %s\n", string);

	

	// Get Input Without Prompt

	printf("----Without Prompt----\n");

	str string2 = getstrf(NULL);

	printf("Input: %s\n", string2);

	

	// Using Single Format Specifire

	printf("----Using Single Format Specifire----\n");

	str string3 = getstrf("Prompt %d: ", 1);

	printf("Input: %s\n", string3);

	

	// Using Multiple Format Specifire

	printf("----Using Multiple Format Specifire----\n");

	str string4 = getstrf("%dst prompt (%s)%c%c", 1, "is", ':', ' ');

	printf("Input: %s\n", string4);

	

	return 0;

}
