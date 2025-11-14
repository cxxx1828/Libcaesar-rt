#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>


int main(void)
{
	printf("================================\n");
	printf("Exercise1                       \n");
	printf("================================\n");

	//--------------------------------------------------

	printf("Question 1:");
	getchar();
	unsigned long long ullVar = 1000000000;//8 bajtova
	int iVar = 0xFF11;// 4 bajta
	//printf("Result is %d bytes long\n", sizeof(ullVar - iVar));//rezultat se 'promovise' na veci
	printf("Result is %lu bytes long\n", sizeof(ullVar - iVar)); //%lu long unsigned

	//--------------------------------------------------

	printf("\nQuestion 2: ");
	getchar();
	unsigned char ucVar1 = 128; // [opseg od 0 do 255]
	char cVar2 = 128; //opseg [-128 do 127] van opsega je, overflow, , predstavice se kao -128 komplementom dvojke, iz signed u unsigned
	char result = ucVar1 + cVar2;// -128+128=0, promocija
	printf("%d + %d = %d\n", ucVar1, cVar2, result);

	//--------------------------------------------------

	printf("\nQuestion 3: ");
	getchar();
	int iVar1 = 2147483647; //signed int [-2^31, 2^31-1]
	int iVar2 = -2147483648;//2^31 = 2147483648
	result = iVar1 - iVar2;//a--b tj. a+b -> premasuje
	printf("%d - %d = %d\n", iVar1, iVar2, result);//integer overflow, result je -1

	//--------------------------------------------------

	printf("\nQuestion 4: ");
	getchar();
	char c = 255; //signed char je opsega [-128,127], ovo premasuje pa ce biti -1 izlaz
	if (c > 128)
	{
		printf("This is unsigned number %d\n", c);
	}
	else
	{
		printf("This is signed number %d\n", c); //This is signed number -1, to je ispis
	}

	//--------------------------------------------------

	printf("\nQuestion 5: ");
	getchar();
	unsigned int i = 5;
	int j = -20;//2^32-20
	if (i + j > 5)
	{
		printf(">5 = %d\n", i + j);// %d radi sa signed vrednostima i zato mi ispise -15 a zna da je vece od 5 jer 2^32-20+5>5, da sam kastovala da radi sa unsigned ispisalo bi kako treba
	}
	else
	{
		printf("<5 = %d\n", i + j);
	}

	//--------------------------------------------------

	printf("\nQuestion 6: ");
	getchar();
	uint16_t u16a = 300000;// [0, 65535] premasuje opseg
	uint16_t u16b = 300000; //  [0,65535]
	uint32_t u32x = u16a + u16b;// nedefinisano ponasanje, ne dobijemo sto ocekujemo od ta dva broja
	printf("Result is %d \n", u32x);
	//--------------------------------------------------

	printf("\nQuestion 7: ");
	float fVal = 5.0;
	double dVal;
	int iVal = -7;//2^32-7, postaje unsigned
	unsigned long ulVal = 1000;
	getchar();
	dVal = iVal * ulVal;// znaci ovo sto se izmnozi ce biti unsigned, a zbpg dVal postaje double
	printf("iVal * ulVal = %lf\n", dVal);
	dVal = iVal + fVal;// int+float, sve postaje float, dobije pokretni zarez, a sve to zbog toga sto je dVal double postaje double
	printf("ulVal + fVal = %lf\n", dVal);

	//--------------------------------------------------

	printf("\nQuestion 8: ");
	getchar();
	printf("Hex -1 is %x\n", -1);// -1 predje u komplement dvojke da bi dobili 32bitnu vrednost i onda u heksadecimalni sto se i ispise


	//--------------------------------------------------

	printf("\nQuestion 9: ");
	getchar();
	float fNumber = 1.1;////skrati dosta mantise, ne moze da se prikaze kao komplement dvojke
	double dNumber = 1.1;//ako je stepen dvojke onda bi bili equal npr 1.25, ima duzu mantisu, takodje ne moze da se prikaze kao stepen dvojke

	if (fNumber == dNumber)
	{
		printf("Float and Double are equal\n");
	}
	else
	{
		printf("Float and Double are NOT equal\n");
	}

	//--------------------------------------------------

	return 0;
}
