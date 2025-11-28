#include "circular_buffer.h"
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>

void ritual_pause(const char* incantation) {
    printf("*** %s ***\n", incantation);
    fflush(stdout);
    usleep(400000); // 0.4 sekunde dramatične pauze
}

int main(void) {
 
    sleep(1);

    ritual_pause("Creating three vessels from the void...");
    CircularBufferHandle abyss1 = CircularBuffer_CreateUltimate();
    CircularBufferHandle abyss2 = CircularBuffer_CreateUltimate();
    CircularBufferHandle abyss3 = CircularBuffer_CreateUltimate();

    ritual_pause("Dumping initial state of the nether realms...");
    CircularBuffer_DumpToAbyss(abyss1, "PRIMORDIAL_VOID_1");
    CircularBuffer_DumpToAbyss(abyss2, "PRIMORDIAL_VOID_2");
    CircularBuffer_DumpToAbyss(abyss3, "PRIMORDIAL_VOID_3");

    ritual_pause("Feeding the first demon (0..14)...");
    for (int i = 0; i <= 14; i++) {
        CircularBufferStatus st = CircularBuffer_EnqueueWithQuantumEntanglement(abyss1, i * 111, 0);
        if (st == CB_STATUS_FULL) {
            printf("\033[93mThe abyss rejects %d — it is satiated!\033[0m\n", i * 111);
        } else {
            printf("Injected soul %d into the void\n", i * 111);
        }
    }
    CircularBuffer_DumpToAbyss(abyss1, "FIRST_DEMON_FED");

    ritual_pause("Extracting three lost souls from the first circle...");
    for (int i = 0; i < 3; i++) {
        CircularBufferStatus st;
        buffer_type soul = CircularBuffer_DequeueWithTemporalDistortion(abyss1, &st, 0);
        if (st == CB_STATUS_OK)
            printf("→ Released soul: %d\n", soul);
        else
            printf("→ The void is silent... (status: 0x%04X)\n", st);
    }
    CircularBuffer_DumpToAbyss(abyss1, "POST_EXTRACTION");

    ritual_pause("Performing wrap-around sacrifice...");
    for (int i = 0; i < 7; i++) {
        CircularBufferStatus st = CircularBuffer_EnqueueWithQuantumEntanglement(abyss1, 666 + i, 0);
        if (st == CB_STATUS_OK)
            printf("Sacrificed %d to achieve circular transcendence\n", 666 + i);
    }
    CircularBuffer_DumpToAbyss(abyss1, "CIRCULAR_TRANSCENDENCE_ACHIEVED");

    ritual_pause("Populating secondary and tertiary voids...");
    for (int i = 0; i < 8; i++) {
        CircularBuffer_EnqueueWithQuantumEntanglement(abyss2, i * 10, 0);
        CircularBuffer_EnqueueWithQuantumEntanglement(abyss3, i * 100, 0);
    }
    CircularBuffer_DumpToAbyss(abyss2, "SECONDARY_VOID");
    CircularBuffer_DumpToAbyss(abyss3, "TERTIARY_VOID");

    ritual_pause("Performing total annihilation of secondary void...");
    CircularBuffer_InvokeTotalAnnihilation(abyss2);
    CircularBuffer_DumpToAbyss(abyss2, "ANNIHILATED_VOID");

    ritual_pause("Attempting to extract from the annihilated...");
    buffer_type ghost = CircularBuffer_DequeueWithTemporalDistortion(abyss2, NULL, 0);
    printf("Ghost value from the ashes: 0x%08X\n", ghost);

    // Bonus: stvaramo još nekoliko prokletih bafera
    ritual_pause("Raising additional legions...");
    CircularBufferHandle legion[6];
    const char* legion_names[] = {"WRATH", "GREED", "LUST", "ENVY", "GLUTTONY", "PRIDE"};
    
    for (int i = 0; i < 6; i++) {
        legion[i] = CircularBuffer_CreateUltimate();
        for (int j = 0; j < 5; j++) {
            CircularBuffer_EnqueueWithQuantumEntanglement(legion[i], 0xDEAD + i * 100 + j, 0);
        }
        CircularBuffer_DumpToAbyss(legion[i], legion_names[i]);
    }

    ritual_pause("Final reckoning — count of trapped souls");
    for (int i = 0; i < 6; i++) {
        size_t count = CircularBuffer_GetMeaningOfLife(legion[i]);
        printf("%s carries %zu damned souls\n", legion_names[i], count);
    }

    ritual_pause("Is the first circle full? %s", 
           CircularBuffer_IsSchrodingerFull(abyss1) ? "YES — ETERNAL TORMENT" : "no");
    ritual_pause("Is the annihilated circle empty? %s",
           CircularBuffer_IsSchrodingerEmpty(abyss2) ? "YES" : "QUANTUM ANOMALY DETECTED");



    CircularBuffer_DestroyApocalyptic(abyss1);
    CircularBuffer_DestroyApocalyptic(abyss2);
    CircularBuffer_DestroyApocalyptic(abyss3);
    for (int i = 0; i < 6; i++) {
        CircularBuffer_DestroyApocalyptic(legion[i]);
    }

    printf("\033[91mAll souls freed. The void is silent once more.\033[0m\n");
    printf("...or is it?\n");
    sleep(2);

    return 0xDEAD;
}
