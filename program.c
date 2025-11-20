#pragma CHECK_MISRA("none")
#include <stdio.h>
#pragma CHECK_MISRA("all")

#define TRESHOLD 2000000000L /* unsigned su samo pozitivni brojevi sto nam ne pokriva problem i kod bubble sorta kod negattivnog rezultata*/

typedef signed int int32_t;/*MISRA 6.4 pravilo*/

/*dodate deklaracije i umesto * u []*/
static void sort(int32_t values_drugacije[], int32_t indexes_drugacije[], int32_t n_drugacije);
static void print(const int32_t values[], const int32_t indexes[], int32_t n);


/* Sortira niz values i niz indexes, koji sadrzi prvobitne indekse vrednosti
 Niz se uredjuje u nerastucem poretku, koricenjem "bubble sort" algoritma*/
static void sort(int32_t values_drugacije[], int32_t indexes_drugacije[], int32_t n_drugacije)
{
	int32_t i_drugacije;
	int32_t j_drugacije;
	for (i_drugacije = 0; i_drugacije < (n_drugacije - 1); i_drugacije++)
	{
		for (j_drugacije = (i_drugacije + 1); j_drugacije < n_drugacije; j_drugacije++)
		{
			if ((values_drugacije[i_drugacije] - values_drugacije[j_drugacije] )< 0) /* i > j*/
			{
				int32_t tmp;
				tmp = values_drugacije[i_drugacije];
				values_drugacije[i_drugacije] = values_drugacije[j_drugacije];
				values_drugacije[j_drugacije] = tmp;

				tmp = indexes_drugacije[i_drugacije];
				indexes_drugacije[i_drugacije] = indexes_drugacije[j_drugacije];
				indexes_drugacije[j_drugacije] = tmp;
			}
		}
	}
}


/* stampa na ekran vrednosti i njihove prvobitne indekse
 dokle god su vece od vrednosti definisane simbolom TRESHOLD*/
static void print(const int32_t values[], const int32_t indexes[], int32_t n)
{
	int32_t i = 0;

    #pragma CHECK_MISRA("-20.9")
	printf("Up to the first treshold: ");
    #pragma CHECK_MISRA("20.9")

	while (values[i] > TRESHOLD)
	{
        #pragma CHECK_MISRA("-20.9")
		printf("%d(%d) ", values[i], indexes[i]);
        #pragma CHECK_MISRA("20.9")

		i++;
	}
    #pragma CHECK_MISRA("-20.9")
	printf("\n");
    #pragma CHECK_MISRA("20.9")
}


#pragma CHECK_MISRA("none")
void main(void)
#pragma CHECK_MISRA("all")
{
	int32_t values_razlicitije[10] = {2123874386, -2047433648, 2147287536, 2147000000, -2000021030, 2107487649, 2137433633, 2113426428, 2012345678, 2147182248};
	int32_t indexes_razlicitije[10];
	int32_t n_drugo = 10;
	int32_t i_drugo;

	for (i_drugo = 0; i_drugo < n_drugo; i_drugo++)
	{
        #pragma CHECK_MISRA("-20.9")
		printf("%d. element: %d", i_drugo, values_razlicitije[i_drugo]);
        #pragma CHECK_MISRA("20.9")

		indexes_razlicitije[i_drugo] = i_drugo;

        #pragma CHECK_MISRA("-20.9")
		printf("\n");
        #pragma CHECK_MISRA("20.9")
	}

	sort(values_razlicitije, indexes_razlicitije, n_drugo);

	print(values_razlicitije, indexes_razlicitije, n_drugo);
}

