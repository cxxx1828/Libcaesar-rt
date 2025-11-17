#include <stdio.h>
#include <stdint.h>

typedef struct _example_struct {
    int8_t char_1;//1
    int8_t char_2;//1
    uint32_t uInt_1;//4
    int16_t ssInt_2;//2
    int32_t sInt_3;//4
    int8_t char_3;//1
} example_struct;

int main() {
    FILE* file;
    example_struct es;
    char str[20] = "abc";
    uint32_t uInt_1 = 22;//4
    int16_t ssInt_2 = 333;//2
    int32_t sInt_3 = 4444;//4

    file = fopen("align2A.dat", "wb");
    fwrite(&str[0], 1, 1, file); //str[0] = a
    fwrite(&str[1], 1, 1, file); //str[1] = b
    fwrite(&uInt_1, 1, 4, file);
    fwrite(&ssInt_2, 1, 2, file);
    fwrite(&sInt_3, 1, 4, file);
    fwrite(&str[2], 1, 1, file);//str[2] = c
    fclose(file);

    //posto sam upisala tacnu velicinu svakog elementa strukture sad samo citam iz datoteke

    file = fopen("align2A.dat", "rb");
    //citam rucno, ne smem da koristim fwrite(&es, sizeof(es), 1) jer nemam padding
    fread(&es.char_1, 1, 1, file);
    fread(&es.char_2, 1, 1, file);
    fread(&es.uInt_1, 1, 4, file);
    fread(&es.ssInt_2, 1, 2, file);
    fread(&es.sInt_3, 1, 4, file);
    fread(&es.char_3, 1, 1, file);
    fclose(file);

    printf("char_1=%c char_2=%c uInt_1=%d ssInt_2=%d sInt_3=%d char_3=%c\n",
           es.char_1, es.char_2, es.uInt_1, es.ssInt_2, es.sInt_3, es.char_3);

    return 0;
}
