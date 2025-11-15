#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int_least8_t x;//globalna promenljiva


void foo(void);//mora da bude void oba tipa,jer ne vraca vrednost

int main(void)
{
	printf("Local variable scope\n");

	x = 42;//svuda vidljiva
	foo();//sad ce svuda biti 101
	printf("After calling foo: x = %d\n", x);

	return EXIT_SUCCESS;
}

void foo(void)//ovde se proseldi 42, ali ga odmah dole defisnisemo u 101, sto mu postaje nova vrednost
{
	x = 101;// za foo funkciju x nam je uvek 100
	printf("Inside foo: x = %d\n", x);
	//i ovde je izbrisan return jer je svuda vidljiva
}
