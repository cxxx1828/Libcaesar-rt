#include <stdio.h>

void postavi_vrednost_file1(int vrednost);
void ispisi_vrednost_file2(void);
void ispisi_vrednost_file1(void);

extern int javna_promennljiva;

int main(void) {
    ispisi_vrednost_file2();

    postavi_vrednost_file1(100);//poprimi vrednost 100, ne bismo mogli samo da napisemo ovde skrivena_promennljiva=100 ne bi poprimilo vrednost

    ispisi_vrednost_file1();//ispis

    javna_promennljiva = 200;//javna je pa preuzima vr 200 i ovde tj. u ovom fajlu
    ispisi_vrednost_file2();

    return 0;
}
