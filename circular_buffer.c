#include "circular_buffer.h"
#include <stdio.h>


void CircularInit(CircularBuffer *cb) {
    cb->glava = cb->buffer;
    cb->rep = cb->buffer;
}

/*
CircularIsFull – Проверава да ли је бафер скроз пун. Враћа „тачно“ ако јесте, а „нетачно“ ако није.
*/
bool CircularIsFull(const CircularBuffer *cb) {
    if (cb->rep + 1 == cb->glava) return true;
    if (cb->rep == &cb->buffer[BUFFER_SIZE - 1] && cb->glava == cb->buffer) return true;
    return false;
}

/*
CircularIsEmpty – Исто као пређашња функција, само обрнуто. Враћа „тачно“ ако је бафер празан, а „нетачно“ ако није.
*/
bool CircularIsEmpty(const CircularBuffer *cb) {
    return (cb->glava == cb->rep);
}

/*
CircularPush – Додаје елемент у кружни бафер. Не проверава попуњеност!
*/
void CircularPush(CircularBuffer *cb, buffer_type vr) {
    if (CircularIsFull(cb)) {
        printf("bafer pun%d :(\n", vr);
        return;
    }

    *(cb->rep) = vr; // ubacujemo vrednost
    if (cb->rep == &cb->buffer[BUFFER_SIZE - 1])
        cb->rep = cb->buffer; // wrap around, start over
    else
        cb->rep++;
}

/*
CircularPop – Узима елемент из бафера. Не проверава да ли је бафер већ празан!
*/
buffer_type CircularPop(CircularBuffer *cb) {
    if (CircularIsEmpty(cb)) {
        printf("bafer prazan\n");
        return -1;
    }

    buffer_type val = *(cb->glava);
    if (cb->glava == &cb->buffer[BUFFER_SIZE - 1])
        cb->glava = cb->buffer; // wrap around
    else
        cb->glava++;
    return val;
}

/*
CircularEmptyBuff – Празни бафер комплетно. Као ресетовање.
*/
void CircularEmptyBuff(CircularBuffer *cb) {
    cb->glava = cb->buffer;
    cb->rep = cb->buffer;
}

/*
CircularDump – Исписује садржај бафера на стандардни излаз. Водити рачуна да елементи бафера могу бити различитог типа.
*/
void CircularDump(const CircularBuffer *cb) {
    if (CircularIsEmpty(cb)) {
        printf("[empty]\n");
        return;
    }

    const buffer_type *p = cb->glava;
    while (p != cb->rep) {
        printf("%d ", *p);//ispisem sve sto je izmedju glave i rep-a
        if (p == &cb->buffer[BUFFER_SIZE - 1])//Fora sa wrap-around je tu, pa ide lepo dok ne dodjemo do repa
            p = cb->buffer; // wrap-around, kreni opet od pocetka, buffer[0]
        else
            p++;
    }
    printf("\n");
}



















// #include "circular_buffer.h"
// #include <stdio.h>

// /*
// CircularInit – Иницијализација бафера. Мора бити позвана пре прве употребе бафера.
// */

// void CircularInit(CircularBuffer *cb) {
//     cb->glava = cb->buffer;
//     cb->rep = cb->buffer;
// }

// /*
// CircularIsFull – Проверава да ли је бафер скроз пун. Враћа „тачно“ ако јесте, а „нетачно“ ако није.
// */
// bool CircularIsFull(const CircularBuffer *cb) {
//     bool check = false;
// 	if (cb->rep == (cb->glava + 1))//proveravamo da li je prazan ako je glava+1=rep, jer po specifikaciji ostavljamo prazno mesto
// 	{
// 		check =  true;
// 	}

// 	return check;
// }

// /*
// CircularIsEmpty – Исто као пређашња функција, само обрнуто. Враћа „тачно“ ако је бафер празан, а „нетачно“ ако није.
// */
// bool CircularIsEmpty(const CircularBuffer *cb) {
//     bool check = false;
// 	if (cb->glava == cb->rep)//prazan samo ako pokazuju na isti
// 	{
// 		check = true;
// 	}
// 	return check;
// }

// /*
// CircularPush – Додаје елемент у кружни бафер. Не проверава попуњеност!
// */
// // void CircularPush(CircularBuffer *cb, buffer_type vr) {

// //     // if (CircularIsFull(cb)) {
// //     //     printf("bafer je pun kao brod :)\n");
// //     //     return;
// //     // }

// //     *(cb->glava) = vr;//rep pokazuje na vrednost
// //     if (cb->glava == &(cb->buffer[BUFFER_SIZE - 1])) {//proveravamo da li glava pokazuje na poslednji element
// //         cb->glava = &(cb->buffer[0]);//ako je tako radimo wrap around gde pokazivac vracamo na pocetak sturkture, cela logika kruznog bafera
// //     } else {
// //         cb->glava++;//inace smo dodali novi element +1 za glavu :)
// //     }
// // }

// /*
// CircularPop – Узима елемент из бафера. Не проверава да ли је бафер већ празан!
// */
// // buffer_type CircularPop(CircularBuffer *cb) {

// //     // if (CircularIsEmpty(cb)) {
// //     //     printf("bafer je prazniji od prazne kese \n");
// //     //     return 777;
// //     // }

// //     buffer_type poper = *(cb->rep);
// //     if (cb->rep == &(cb->buffer[BUFFER_SIZE - 1])) {//proveravamo da li rep pokazuje na poslednji element
// //         cb->rep = &(cb->buffer[0]);//ako je tako radimo wrap around gde pokazivac vracamo na pocetak sturkture, cela logika kruznog bafera
// //     } else {
// //         cb->rep++;//ako smo ga obrisali +1 rep
// //     }

// //     return poper;

// // }

// void CircularPush(CircularBuffer *cb, buffer_type vr) {
//     *(cb->rep) = vr; // rep je mesto za ubacivanje
//     if (cb->rep == &(cb->buffer[BUFFER_SIZE - 1]))
//         cb->rep = &(cb->buffer[0]);
//     else
//         cb->rep++;
// }

// buffer_type CircularPop(CircularBuffer *cb) {
//     buffer_type poper = *(cb->glava); // glava je mesto za čitanje
//     if (cb->glava == &(cb->buffer[BUFFER_SIZE - 1]))
//         cb->glava = &(cb->buffer[0]);
//     else
//         cb->glava++;
//     return poper;
// }



// void CircularEmptyBuff(CircularBuffer *cb) {
//     cb->glava =  &(cb->buffer[0]);
//     cb->rep =  &(cb->buffer[0]);
// }

// void CircularDump(const CircularBuffer *cb) {

//     const buffer_type *p = cb->glava;//citam iz glave

//     if (CircularIsEmpty(cb)) {
//         return;
//     }

//     while (p != cb->rep) {
//         printf("%d ", *p);
//         if (p == &(cb->buffer[BUFFER_SIZE - 1]))
//             p = &(cb->buffer[0]);// vracamo na pocetak kruzna logika
//         else
//             p++;
//     }

// }
