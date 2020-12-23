/*
Ejercicio 3: Ordenación de palabras.
Escribe un programa en C que pida al usuario un total de 10 palabras y luego las imprima todas ellas en pantalla por orden alfabético.
Nota: asume que cada palabra puede tener un máximo de 20 caracteres.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 20

// Defining neccesary data structure
typedef struct abcde {
    char word[length];
} Abcde;

// Global definition of show information function
//void showAbcde (struct abcde);

int main() {

    struct abcde w[length], *p_word; // we use w instance here and pointer

    p_word = &w[0]; //point to first position

    //Now we need a bucle for to get user's ten words:
    for (int i = 0; i < 10; i++) {
        printf("Please introduce your %i word here: ", i+1);
        scanf(" %s", w[i].word);

        while(getchar() != '\n'); // cleaning entry buffer

        p_word++; //next iteration
    }
    p_word = &w[0];

    for (int i = 0; i < 10; i++) {
        printf("The word is %s \n", w[i].word);

        p_word++;
    }

    return 0;
}