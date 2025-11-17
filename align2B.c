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
    uint32_t uInt_1 = 22;
    int16_t ssInt_2 = 333;
    int32_t sInt_3 = 4444;
    uint8_t pad = 0;

    file = fopen("align2B.dat", "wb");
    fwrite(&pad, 1, 1, file);
    fwrite(&str[0], 1, 1, file);
    fwrite(&pad, 1, 1, file);
    fwrite(&str[1], 1, 1, file);
    fwrite(&pad, 1, 1, file);
    fwrite(&uInt_1, 1, 4, file);
    fwrite(&ssInt_2, 1, 2, file);
    fwrite(&pad, 1, 1, file);
    fwrite(&sInt_3, 1, 4, file);
    fwrite(&str[2], 1, 1, file);
    fwrite(&pad, 1, 1, file);
    fclose(file);
    /*
    dan5/ $ gcc align2B.c -o zzz
    dan5/ $ ./zzz
    char_1=a char_2=b uInt_1=1291845632 ssInt_2=1 sInt_3=6488064 char_3=
    dan5/ $ gcc align2B.c -o zzz
    dan5/ $ ./zzz
    char_1=a char_2= uInt_1=22 ssInt_2=333 sInt_3=1660944401 char_3=
    dan5/ $ gcc align2B.c -o zzz
    dan5/ $ ./zzz
    char_1= char_2=a uInt_1=5632 ssInt_2=19712 sInt_3=4444 char_3=c ovde sam stavila padding iznad citanja str[0] i stavio je char_2=a
    dan5/ $

    Kako sam ubacivala random padding bajtove menjao se redosled i dobijao nasumicne vrednosti pri citanju
    */

    file = fopen("align2B.dat", "rb");
    fread(&es, 1, sizeof(example_struct), file);// mogu fread jer imam umetnute bajtove
    fclose(file);

    printf("char_1=%c char_2=%c uInt_1=%d ssInt_2=%d sInt_3=%d char_3=%c\n",
           es.char_1, es.char_2, es.uInt_1, es.ssInt_2, es.sInt_3, es.char_3);

    return 0;
}
