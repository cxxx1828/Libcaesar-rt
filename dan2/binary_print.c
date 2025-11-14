#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

void printBinary(uint8_t* number);
void printSignedChar(int8_t num);


int main()
{
	printf("================================\n");
	printf("Exercise3\n");
	printf("================================\n");

	int i = 0;
	int32_t intNumber= 1;

	printSignedChar(-2);

	return 1;
}


void printBinary(uint8_t* number)
{
	uint8_t small = *number;
	uint8_t mask = 0x80;
	int i = 0;

	for (i = 8; i > 0; i--)
	{
		uint8_t tmp = 0;
		tmp = (small & mask) != 0;
		printf("%d", tmp);
		mask = mask >> 1;
	}
}


void printSignedChar(int8_t num)
{
	int i = 0;
	int32_t b = 0; //mogu da stampam samo po 8bitne vrednosti, a b je 32 bita
	int8_t a = num;

	b = a;

	printf("a = 0x%x\t(signed) c = %d\t(unsigned) c = %u\n", (uint8_t)a, a, (uint8_t)a);
	printf("(binary)\t");
	printBinary((uint8_t*)&a);

	printf("\n\n");

	uint8_t* part = (uint8_t*)&b;

	printf("b = 0x%x\t(signed) b = %d\t(unsigned) b = %u\n", b, b, (uint32_t)b);
	printf("(binary)\t");

	//---------------------------------------------------------
	//This is where you should print 32bit integer b
	//---------------------------------------------------------

	uint32_t value = (uint32_t)b; //signed u unsigned
	int bits[32];//niz gde cuvamo svaki bit


	for (int i = 0; i < 32; i++) {
		bits[i] = value % 2;// uzimamo lsb
		value = value / 2;//pomeramo udesno kao da sam uradila >>
	}


	for (i = 31; i >= 0; i--) {
		printf("%d", bits[i]);// stampam od najznacajnijeg do najmanje znacajnog
	}
	printf("\n");


	printf("Not implemented\n");
}




