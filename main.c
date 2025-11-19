#include "circular_buffer.h"
#include <stdio.h>

int main() {

    // pravimo tri casual bafera
    CircularBuffer cb1, cb2, cb3;
    CircularInit(&cb1);
    CircularInit(&cb2);
    CircularInit(&cb3);

    printf("1\n");
    printf("cb1: "); { CircularDump(&cb1); } printf("\n");
    printf("cb2: "); { CircularDump(&cb2); } printf("\n");
    printf("cb3: "); { CircularDump(&cb3); } printf("\n");

    printf("\npush u cb1\n");
    for (int i = 0; i <= 9; i++) {
        if (!CircularIsFull(&cb1)) {
            CircularPush(&cb1, i);
            printf("ubacujem %d\n", i);
        } else {
            printf("ne mogu da ubacim %d :(\n", i);
        }
    }
    printf("cb1 sada: "); { CircularDump(&cb1); } printf("\n");

    printf("\npop 3 elementa iz cb1\n");
    for (int i = 0; i < 3; i++) {
        if (!CircularIsEmpty(&cb1)) {
            int v = CircularPop(&cb1);
            printf("popujem %d\n", v);
        } else {
            printf("bafer prazan\n");
        }
    }
    printf("cb1 posle popa: "); { CircularDump(&cb1); } printf("\n");

    printf("\nwrap-around push u cb1 \n");
    for (int i = 0; i < 5; i++) {
        if (!CircularIsFull(&cb1)) {
            CircularPush(&cb1, i);
            printf("ubacujem %d\n", i);
        } else {
            printf("ne mogu da ubacim %d :(\n", i);
        }
    }
    printf("cb1 posle wrap-around: "); { CircularDump(&cb1); } printf("\n");

    printf("\ncb2 i cb3 punimo brojevima ===\n");
    for (int i = 0; i < 6; i++) { CircularPush(&cb2, i); }
    for (int i = 0; i < 6; i++) { CircularPush(&cb3, i); }
    printf("cb2: "); { CircularDump(&cb2); } printf("\n");
    printf("cb3: "); { CircularDump(&cb3); } printf("\n");

    printf("\npraznim cb2\n");
    CircularEmptyBuff(&cb2);
    printf("cb2: "); { CircularDump(&cb2); } printf("\n");

    printf("\npop iz praznog cb2\n");
    if (!CircularIsEmpty(&cb2)) {
        int v = CircularPop(&cb2);
        printf("popujem %d\n", v);
    } else {
        printf("bafer prazan, nema sta da se popuje\n");
    }

    CircularBuffer cb4, cb5, cb6;

    CircularInit(&cb4);
    CircularInit(&cb5);
    CircularInit(&cb6);

    for (int i = 0; i < 5; i++) {
        CircularPush(&cb4, i);
        printf("ubacujem %d\n", i);
    }
    printf("cb4: "); CircularDump(&cb4); printf("\n");

    for (int i = 0; i < 2; i++) {
        int v = CircularPop(&cb4);
        printf("popujem %d\n", v);
    }
    printf("cb4 posle popa: "); CircularDump(&cb4); printf("\n");

    for (int i = 10; i < 15; i++) {
        CircularPush(&cb5, i);
        printf("ubacujem %d\n", i);
    }
    printf("cb5: "); CircularDump(&cb5); printf("\n");

    for (int i = 50; i < 55; i++) {
        CircularPush(&cb6, i);
        printf("ubacujem %d\n", i);
    }
    printf("cb6: "); CircularDump(&cb6); printf("\n");

    CircularEmptyBuff(&cb5);
    printf("cb5 posle praznjenja: "); CircularDump(&cb5); printf("\n");


    return 0;
}
//gcc -c circular_buffer.c -o circular_buffer.o
//ar rcs libcircular.a circular_buffer.o
//gcc main.c -L. -lcircular -o boze

/*

gcc -c circular_buffer.c -o circular_buffer.o
ar rcs libcircular.a circular_buffer.o
gcc main.c -L. -lcircular -o boze

gcc main.c -L. -lcircular -o boze

ar t libcircular.a

mv libricular.a libcircular.a

gcc main.c -L. -lcircular -o boze

*/
