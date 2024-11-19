#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define N 100
unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );
void rand_dig(char *);
void rand_DNI (unsigned *);
void rand_DNIs (unsigned [N], char [N]);
void print_DNIs (unsigned [N], char [N]);
void strings_swap(char [9+1], char [9+1]);
void strings_bubbleSort(char [N][9+1]);

void rand_dig(char *dig) {
    *dig = rand() % 10 + '0';
}

void rand_DNI(unsigned *DNI) {
    char dig;
    *DNI = 0;
    for (int i = 0; i < 8; i++) {
        rand_dig(&dig);
        *DNI = *DNI * 10 + (dig - '0');
    }
}

unsigned resto_DNI(unsigned DNI) {
    return DNI % 23;
}

char letra_calculada(unsigned restoDNI) {
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    return letra[restoDNI];
}

void rand_DNIs (unsigned dni[N], char letra[N]) {
    for (int i = 0; i < N; i++) {
        unsigned DNI = 0;
        rand_DNI(&DNI);
        dni[i] = DNI;
        letra[i] = letra_calculada(resto_DNI(dni[i]));
    }

    print_DNIs(dni, letra);
}

void print_DNIs (unsigned dni[N], char letra[N]) {
    for (int i = 0; i < N; i++) {
        printf("| %08u-%c",dni[i], letra[i]);
    }
}

void strings_bubbleSort(char dni[N][9+1]) {
    int ret;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            ret = memcmp(dni[j], dni[j + 1], 10);
            if (ret > 0) {
                strings_swap(dni[j], dni[j + 1]);
            }
        }
    }
}

int main(void)
{
    srand(time(NULL));
    unsigned DNI[N];
    char letra[N];

    printf(" > DNIs\n");
    rand_DNIs(DNI, letra);
    printf("\n");
    printf(" > DNIs ordenados\n");
    print_DNIs (DNI, letra);
    return 0;
}
