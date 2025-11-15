#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modifyChar(char* ch);
void modifyString1(const char* sp);
void modifyString2(char const* sp);
void modifyString3(char* const sp);
void modifyString4(const char* const sp);

char globalString[20] = "The global string";

int main()
{
	printf("================================\n");
	printf("Const in function parameter list\n");
	printf("================================\n");

	char string1[20] = "text 1";
	char string2[20] = "text 2";
	char string3[20] = "text 3";
	char string4[20] = "text 4";

	modifyString1(string1);
	modifyString2(string2);
	modifyString3(string3);
	modifyString4(string4);

	printf("modifyString1 -> %s\n", string1);
	printf("modifyString2 -> %s\n", string2);
	printf("modifyString3 -> %s\n", string3);
	printf("modifyString4 -> %s\n", string4);

	return 0;
}


void modifyString1(const char* sp)//ne moze da menja na sta pokazuje
{
	modifyChar(sp + 3);//ovde ne moze da se pozove jer pokusava da menja sp agore je const levo od *
	sp = globalString;
	*(sp + 3) = '\0';
}

void modifyChar(char* ch)// validna funkcija
{
	*ch = '\0';
}

void modifyString2(char const* sp)//ne sme da menja podatke
{
	strcpy(sp, globalString);//pokusava i zato ne moze
	sp = globalString;
	*(sp + 3) = '\0';
}

void modifyString3(char* const sp)//const je desno pokazivac ne sme da pokazuje na druge podatke
{
	*(sp + 3) = '\0';
	sp = globalString;//on je gore string3 a ovde pokusava da bude globalstring
}

void modifyString4(const char* const sp)// zbog oba consta kao read only ne moze da se menja nista
{
	sp = globalString;
	*(sp + 3) = '\0';
}

