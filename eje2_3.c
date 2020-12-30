/*
Ejercicio 3: Ordenación de palabras.
Escribe un programa en C que pida al usuario un total de 10 palabras y luego las imprima todas ellas en pantalla por orden alfabético.
Nota: asume que cada palabra puede tener un máximo de 20 caracteres.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // interesting library for handle string
#include <ctype.h> // useful librayu for handle capital letters issue ordering

#define length 20

// Defining neccesary data structure
typedef struct abcde {
    char word[length];
} Abcde;

char aux[length]; // auxiliar string

int main() {

    struct abcde w[length], *p_word; // we use w instance here and a pointer to keep memory space

    p_word = &w[0]; //point to first position

    //Now we need a bucle for to get user's ten words:
    for (int i = 0; i < 10; i++) {
        printf("Please introduce your %i word here: ", i+1);
        scanf(" %s", w[i].word);

        while(getchar() != '\n'); // cleaning entry buffer

        p_word++; //next iteration
    }
    // p_word = &w[0];

    // Now we are going to order our words/strings
    int l = 10; // ten words
    int i, j, k, n; // define different iterators
    for(i = 0; i < l-1; i++) { // initiate burble 
         
        k=i;
        strcpy(aux, w[i].word); // function to copy temporaly in auxiliar string our words, handling transitions 
        for(j=i+1; j<l; j++) {
            n = strcasecmp(w[j].word, aux); // great function to handle capital letters problems
            if(n < 0) {
                k=j;
                strcpy(aux, w[j].word);
            }
        }
        strcpy(w[k].word,w[i].word);
        strcpy(w[i].word,aux);
    }

    for (i = 0; i < l; i++) {
        printf("The word %i is %s \n", i, w[i].word); // now iterating to show ordered words

        p_word++;
    }

    return 0;
}