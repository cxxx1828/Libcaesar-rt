#include <stdio.h>
#include <stdint.h>

typedef struct _example_struct {
    uint32_t uInt_1;//4
    int32_t sInt_3;//4
    int16_t ssInt_2;//2
    int8_t char_1;//1
    int8_t char_2;//1
    int8_t char_3;//1
} example_struct;

/*
Preraspodelimo raspored u strukturi , minimalan padding 
*/

int main() {
    FILE* file;
    example_struct es = {0};
    char str[20] = "abc";

    es.uInt_1 = 22;
    es.ssInt_2 = 333;
    es.sInt_3 = 4444;
    es.char_1 = str[0];
    es.char_2 = str[1];
    es.char_3 = str[2];

    file = fopen("align2C.dat", "wb");
    fwrite(&es, 1, sizeof(example_struct), file);
    fclose(file);

    file = fopen("align2C.dat", "rb");// sad mozemo da citamo bez obzira sto nema paddinga
    fread(&es, 1, sizeof(example_struct), file);
    fclose(file);

    printf("char_1=%c char_2=%c uInt_1=%d ssInt_2=%d sInt_3=%d char_3=%c\n",
           es.char_1, es.char_2, es.uInt_1, es.ssInt_2, es.sInt_3, es.char_3);


    printf("struct   size %ld  \taddr: %p (4-byte alligned: %s)\n", sizeof(example_struct), &es, ((uintptr_t)(&es)%4) ? "NO" : "YES");

    return 0;
}
