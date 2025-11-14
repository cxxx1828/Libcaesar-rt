#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


enum tresholds_t
{
	TRESHOLDS_FIRST = 10,
	TRESHOLDS_SECOND ,
	TRESHOLDS_THIRD = 20
};


void sort(int_least16_t* values, int_least16_t* indexes, int_least8_t n)
{
	int_least8_t i;
	int_least8_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (values[i] < values[j] ) //stavljeno < u slucaju negativnih vrednosti
			{
				int_least16_t tmp;
				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;

				tmp = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = tmp;
			}
		}
	}
}


void print(int_least16_t* values, int_least16_t* indexes, int_least8_t n)
{
    int_least8_t i;

    printf("Up to the first treshold (<10): ");
    for (i = 0; i < n; i++)
        if (values[i] < TRESHOLDS_FIRST)
            printf("%" PRId16 "(%" PRId16 ") ", values[i], indexes[i]);
    printf("\n");

    printf("Up to the second treshold (<11): ");
    for (i = 0; i < n; i++)
        if (values[i] < TRESHOLDS_SECOND)
            printf("%" PRId16 "(%" PRId16 ") ", values[i], indexes[i]);
    printf("\n");

    printf("Up to the third treshold (<20): ");
    for (i = 0; i < n; i++)
        if (values[i] < TRESHOLDS_THIRD)
            printf("%" PRId16 "(%" PRId16 ") ", values[i], indexes[i]);
    printf("\n");
}


int main(void)//stavljen int , i dodat return 0
{
	int_least16_t values[30000];//moze i manje memorije, mozda malloc
	int_least16_t indexes[30000];
	int_least8_t i;
	int_least8_t n;
	printf("Number of elements: ");

	//scanf("%d", &n);// mozda da se ubaci neka provera da li je manje od 1
	scanf("%" SCNd8, &n);

	printf("\n");
	for (i = 0; i < n; i++)
	{
		//printf("%d. element: ", i);
		printf("%" PRId8 ". element: ", i);

		//scanf("%d", &values[i]);//isto neke provere
		scanf("%" SCNd16, &values[i]);

		indexes[i] = i;
		printf("\n");
	}

	sort(values, indexes, n);

	print(values, indexes, n);

	return 0;
}





