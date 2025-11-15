#include <stdio.h>
int main()
{
    int i;
    int x;//ove x i y ispise poslednji printf zato su random vrednosti
    int y;

    for (i = 0; i < 5; i++)
    {
        int x = 0;// x se svaki put kad udjemo u for stavi na nulu
        static int y = 0;//u ovom for-u y se posmatra kao globalna i menja vrednost ali u mainu se ona ne vidi i zato je dole random vrednost
        printf("x=%d, y=%d\n", x++, y++);
    }

    printf("\nx=%d, y=%d\n", x++, y++);
    return 0;
}
