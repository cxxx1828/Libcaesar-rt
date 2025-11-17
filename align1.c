#include <stdio.h>
#include <stdint.h>
//#pragma pack(push)  /* push current alignment to stack */
//#pragma pack(2)     /* set alignment to 1 byte boundary */

typedef struct _example_struct
{
	uint8_t   char_a;//1
	uint32_t  uint_b;//4
	uint16_t  short_c;//2
	uint16_t  short_d;//2
} example_struct;
//} __attribute__ ((packed)) example_struct; //nema padding

//#pragma pack(pop)   /* restore original alignment from stack */


int main(void)
{
	int8_t arr1[3]; //3 bajta
	int8_t arr2[1]; //1 bajt
	example_struct ex_struct;

	printf("arr1     size %d  \taddr: %p (4-byte alligned: %s)\n", sizeof(arr1),  &arr1,      ((uintptr_t)(&arr1)%4)      ? "NO" : "YES");
	printf("arr2     size %d  \taddr: %p (4-byte alligned: %s)\n", sizeof(arr2),  &arr2,      ((uintptr_t)(&arr2)%4)      ? "NO" : "YES");
	printf("struct   size %d  \taddr: %p (4-byte alligned: %s)\n", sizeof(example_struct), &ex_struct, ((uintptr_t)(&ex_struct)%4) ? "NO" : "YES");

	return 0;
}

/*
Покрените програм у „align1.c” датотеци и прокоментаришите резултате.
//} __attribute__ ((packed)) example_struct; pravi lokalnu granicu da nema poravnanja u strukturi

dan5/ $ ./r
arr1     size 3         addr: 0x7ffeb1f3e825 (4-byte alligned: NO)
arr2     size 1         addr: 0x7ffeb1f3e824 (4-byte alligned: YES)
struct   size 9         addr: 0x7ffeb1f3e81b (4-byte alligned: NO)
//nema paddinga minimalna velicina, sporiji CPU, nije umnozak od 4, pack radi to globalno nema poravnanja u fajlu



Уклоните атрибут, а откоментаришите #pragma pack(1) и повезане линије. Преведите и покрените.
arr1     size 3         addr: 0x7ffc0e8105e5 (4-byte alligned: NO)
arr2     size 1         addr: 0x7ffc0e8105e4 (4-byte alligned: YES)
struct   size 9         addr: 0x7ffc0e8105db (4-byte alligned: NO)
//nema paddinga minimalna velicina, sporiji CPU, nije umnozak od 4
multiple of 4 = оптимална брзина приступа на x86



Поставите #pragma pack(2) и поново преведите покрените.
arr1     size 3         addr: 0x7ffd16647005 (4-byte alligned: NO)
arr2     size 1         addr: 0x7ffd16647004 (4-byte alligned: YES)
struct   size 10        addr: 0x7ffd16646ffa (4-byte alligned: NO)
//1 bajt paddinga



Уклоните #pragma pack(2) и повезане линије. Опет преведите и покрените.
arr1     size 3         addr: 0x7ffd18b8a4f5 (4-byte alligned: NO)
arr2     size 1         addr: 0x7ffd18b8a4f4 (4-byte alligned: YES)
struct   size 12        addr: 0x7ffd18b8a4e8 (4-byte alligned: YES)

bez packinga on dodaje posle char a sto je jedan bajt 3 bajta da bi b poceo na 4, onda dodaje c sto je 2 i d 2 ukupno 12
*/
