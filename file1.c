#include <stdio.h>

static int skrivena_promennljiva = 10;//definisemo je kao zatvorenu

void postavi_vrednost_file1(int vrednost) {
    skrivena_promennljiva = vrednost;
}


void ispisi_vrednost_file1(void) {
    printf("Vrednost javne promenljive u file2.c = %d\n", skrivena_promennljiva);
}
