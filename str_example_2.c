#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct _my_struct
{
	char text[20];
	uint_least16_t num;
} my_struct;

int main()
{
	my_struct ms;
	char strBuf[100] = "This text is too long for struct member text";
	ms.num = 55555;

	// Error situation (stack problem)
	printf("\nCopying longer string to shorter\n");
	//strcpy(ms.text, strBuf);
	//podaci ce da zauzmu prostor od num jet strBuf nema dovoljno mesta u text-u
	strncpy(ms.text, strBuf, 20);
	printf("my_struct text=%s, num=%"PRIuLEAST16"\n", ms.text, ms.num);


	// Check if strings are equal
	printf("\nComparing two strings\n");
	char str1[20] = "This is text 1";
	char str2[20] = "This is text 2";
	if (strcmp(str1, str2)==0)// dodato ==0 jer nama strcmp vraca 0 ako je uspesno tj. ako su jednaki
	{
		printf("Strings are equal\n");
	}
	else
	{
		printf("Strings are not equal\n");
	}

	// Tokenizing
	printf("\nTokenizing string by space delimiter\n");
	//char* s = "one two three four five";
	//ne moze char* jer je string literal aka konstantan
	char s[] = "one two three four five";
	printf("string for tokenizing: \"%s\" \n", s);

	char* token = strtok(s, " ");// kad je s bio literal on je pokusavao da izmeni staticki podatak
	printf("after 1st step, string is: \"%s\" \n", s);

	printf("token: %s\n", token);
	while (token != NULL)
	{
	    token = strtok(NULL, " ");
	    printf("token: %s\n", token);
	}

	return 1;
}
