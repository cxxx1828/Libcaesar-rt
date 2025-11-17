#include <stdio.h>
#include <stdint.h>

int_least32_t stringLength(const char str[]){//const jer ga ne menjamo

    int_least32_t duzina = 0;

    if(str[0] == '\0'){
        return 0;
    }

    while(str[duzina] != '\0'){
        duzina++;
    }

    return duzina;
}

void stringTrim(char str[]){

    if(str[0] == '\0'){
        return ;
    }

    int_least32_t pocetak = 0;
    int_least32_t kraj = 0;
    int_least32_t duzina = 0;
    int_least32_t i = 0;

    while(str[duzina] != '\0'){
        duzina++;
    }

    //trazim razmak sa pocetka
    while((str[pocetak] == ' ' || str[pocetak] == '\t' || str[pocetak] == '\n' || str[pocetak] == '\r' )&& pocetak < duzina)
    {
        pocetak++;
    }

     //trazenje razmaka sa kraja
    kraj = duzina - 1;
    while((str[kraj] == ' ' || str[kraj] == '\t' || str[kraj] == '\n' || str[kraj] == '\r')&& kraj >= 0)
    {
        kraj--;
    }

     while(pocetak <= kraj)
    {
        str[i++] = str[pocetak++];//premesta sve karaktere izmedju pocetak i kraj na pocetak stringa
    }

    str[i] ='\0';//bez null pointera ode mast u propast
}


int_least8_t extractSubstring(const char inStr[], char outStr[], uint_least32_t beginning, uint_least32_t end)
{
    uint_least32_t duzina = 0;
    uint_least32_t i = 0;

    // if(beginning < 0 || end <0){
    //     outStr[0] = '\0'; //ako nisu validni uslovi kraj i prazan outstr
    //     return 0;
    // }

    while(inStr[duzina] != '\0'){
        duzina++;
    }

    if(beginning > end || end >= duzina)
    {
        outStr[0] = '\0';
        return 0;
    }

    for(i = beginning; i <= end; i++){
        outStr[i - beginning] = inStr[i];
    }


    outStr[i - beginning] = '\0';//null pointer = dijamant margarin

    return 1;


}

void concatenateStrings(char str1[], const char str2[])
//drugi const jer ga ne menjamo, prvi mora imati dovoljno mesta u memoriji, pretpostavka
{
    if (str2[0] == '\0'){
    	return;
    }

    char *p1 = str1;       // pokazivac na pocetak str1
    const char *p2 = str2; //pokazivac na char ne mozemo menjati str2, pokazuje na pocetak str2
    //5 = x sa predavnja primer

    // idem do kraja str1
    while (*p1 != '\0') {
        p1++;
    }

    // kopiraj sve karaktere sa str2 na kraj str1
    while (*p2 != '\0') {
        *p1++ = *p2++;
    }

    *p1 = '\0'; //null pointer = vegeta

}



int main(void) {

    //stringLength

    // char test1[] = "Svi smo mi gvupavi :)";
    // printf("string: \"%s\"\n", test1);
    // printf("duzina: %u\n\n", stringLength(test1));


     //stringTrim

    // char test2[] = "   napredni c    \n\t";
    // printf("pre trima: \"%s\"\n", test2);
    // printf("stara duzina: %u\n\n", stringLength(test2));
    // stringTrim(test2);
    // printf("posle trima: \"%s\"\n", test2);
    // printf("nova duzina: %u\n\n", stringLength(test2));


    //extractSubstring

    // const char test3[] = "programming language";
    // char substring[50];

    // printf("originalni string: \"%s\"\n", test3);

    // if (extractSubstring(test3, substring, 0, 6)) {
    //     printf("podniz [0-6]: \"%s\"\n", substring);
    // }

    // if (extractSubstring(test3, substring, 12, 19)) {
    //     printf("podniz [12-19]: \"%s\"\n", substring);
    // }


    //concatenateStrings

    char test4[1000] = "Dronovi";
    const char test4b[] = " lete";

    printf("Prvi string: \"%s\"\n", test4);
    printf("Drugi string: \"%s\"\n", test4b);
    printf("Stara duzina: %u\n", stringLength(test4));
    printf("Stara duzina 2: %u\n", stringLength(test4b));


    concatenateStrings(test4, test4b);

    printf("Rezultat: \"%s\"\n", test4);
    printf("Nova duzina: %u\n", stringLength(test4));




    return 0;
}
