#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


static const int_least32_t treshold1 = 20;
static const int_least32_t treshold2 = 30;
static const int_least32_t treshold3 = 40;

// koristi niz:
//static const int_least32_t tresholds[3] = {20, 30, 40};

typedef struct _s
{
	int_least32_t value;
	int_least16_t index;
} val_ind_struct_t;

static val_ind_struct_t struct_array[4000];


static void bubble_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (str_array[i].value < str_array[j].value)
			{
				val_ind_struct_t tmp;

				tmp = str_array[i];
				str_array[i] = str_array[j];
				str_array[j] = tmp;
			}
		}
	}
}


// static int compare(const void* p, const void* q){

// 	int_least32_t arg1 = *(const int_least32_t*)p;
// 	int_least32_t arg2 = *(const int_least32_t*)q;

// 	if(arg1 < arg2){
// 		return -1;
// 	}else if(arg1 > arg2){
// 		return 1;
// 	}else{
// 		return 0;
// 	}

// }



static int compare(const void* p, const void* q)
{
	// kastovanje iz void* u nas tip strukture
	val_ind_struct_t* prvi = (val_ind_struct_t*)p;
	val_ind_struct_t* drugi = (val_ind_struct_t*)q;

	// sad mozes da se pristupi poljima strukture
	// if(prvi->value < drugi->value)
	// 	return 1;
	// if(prvi->value > drugi->value)
	// 	return -1;
	// return 0;
	//opadajuci - oduzmi obrnuto
	return (drugi->value - prvi->value);
}

// qsort prima void* jer ne zna koji tip sortira
static void quick_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	// sort using qsort standard function
	// ja mu kazem da sortira val_ind_struct_t tako sto ga kastujem
	qsort(str_array, n , sizeof(val_ind_struct_t),compare);
}


static void print(const val_ind_struct_t* str_array, int_least16_t n, int_fast8_t tr_index)
{
	int_least16_t i = 0;
	int_least32_t treshold;
	printf("Up to the %"PRIdFAST8". treshold: ", tr_index);

	// switch (tr_index)
	// {
	// case 1:
	// 	treshold = treshold1;
	// 	break;
	// case 2:
	// 	treshold = treshold2;
	// 	break;
	// case 3:
	// 	treshold = treshold3;
	// 	break;
	// }

	if(tr_index == 1)
	{
		treshold = treshold1;
	}
	else if(tr_index == 2)
	{
		treshold = treshold2;
	}
	else if(tr_index == 3)
	{
		treshold = treshold3;
	}
	else
	{
		printf("Invalid operation\n");
	}
	// - 1 jer niz ide od 0
	//treshold = tresholds[tr_index - 1];

	while (str_array[i].value > treshold && i < n)
	{
		printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", str_array[i].value, str_array[i].index);
		i++;
	}
	printf("\n");
}


void main()
{
	int_least16_t i;
	int_least16_t n;
	int_fast8_t treshold_index;
	int_fast8_t sort_index;
	printf("Number of elements: ");
	scanf("%"SCNdLEAST16, &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%"PRIdLEAST16". element: ", i);
		scanf("%"SCNdLEAST32, &(struct_array[i].value));
		struct_array[i].index = i;
		printf("\n");
	}
	printf("Trashold you want to use (1, 2, or 3): ");
	scanf("%"SCNdFAST8, &treshold_index);
	printf("\n");
	printf("Sorting algorithm you want to use (1- bubble, 2- quick): ");
	scanf("%"SCNdFAST8, &sort_index);
	printf("\n");

	// switch (sort_index)
	// {
	// case 1:
	// 	bubble_sort(struct_array, n);
	// 	break;
	// case 2:
	// 	quick_sort(struct_array, n);
	// 	break;
	// }

	//sa predavanja, moglo je i samo fptr[2]
	void (*fptr[2])(val_ind_struct_t* struct_array, int_least16_t n) = {bubble_sort, quick_sort};

	fptr[sort_index - 1](struct_array, n);


	print(struct_array, n, treshold_index);
}

/*BubbleSort Up to the 1. treshold: 79(7) 55(1) 50(9) 41(0) 33(5) 33(3) 33(4) 27(2) 27(6)
Quicksort Up to the 1. treshold: 79(7) 55(1) 50(9) 41(0) 33(3) 33(4) 33(5) 27(2) 27(6)
oba sortiraju niz opadajuce i daju isti rezultat za razlicite
vrednosti, ali se razlikuju u redosledu jednakih elemenata - BubbleSort
je stabilan algoritam koji cuva originalni redosled 33 sa indeksima 5,3,4,
dok je QuickSort nestabilan pa redosled jednakih elemenata nije garantovan, predvidiv etc
,33 sa indeksima 3,4,5*/
