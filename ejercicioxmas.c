#include <stdio.h>      // printf()
#include <math.h>       // ceil()
#include <stdlib.h>     // rand(), srand()
#include <time.h>       // time()

// gcc -std=c99  ejercicioxmas.c -o ejercicioxmas -lm && ./ejercicioxmas && rm ejercicioxmas

// la función nos obliga a tener una variable global innecesaria ya
// que siempre es la anchura del árbol, n
int ARRAY_MAX = 0;

void imprime(char* matrix, int m, int n) {
    for( int i = 0; i <m; i++) {
        for( int j = 0; j <n; j++ ){
            printf("%c",*(matrix+i*ARRAY_MAX+j));
        }
        printf("\n");
    }
}

int main()
{
    // Necesitamos renovar la semilla del random
    srand(time(NULL));

    printf("Especifique la altura de la copa:\n");

    int niveles;
    scanf("%d", &niveles);

    // siendo n = número de niveles del árbol
    // Cada nivel tiene 2n-1 carácteres
    // Por lo tanto la matrix se calcula con anchura: 2n-1 y altura: 2n-1 + tronco
    // Donde tronco es n/4 

    // Redondeamos al siguiente entero
    int alturaTronco = ceil((double)(niveles)/4);
    int alturaArbol  = niveles + alturaTronco;
    int anchuraArbol = 2*niveles-1;

    printf("======== Parámetros ======================\n");
    printf("alturaCopa: %d\n", niveles);
    printf("alturaTronco: %d\n", alturaTronco);
    printf("alturaArbol: %d\n", alturaArbol);
    printf("anchuraArbol: %d\n", anchuraArbol);
    printf("==========================================\n");

    char arbol[alturaArbol][anchuraArbol];

    ARRAY_MAX = anchuraArbol;

    int i = 0;

    // Rellenamos niveles
    for(; i <niveles; i++) {

        // Rellenamos todo vacío 
        for( int j = 0; j <anchuraArbol; j++ ){
            arbol[i][j] = ' ';
        }

        // Primer nivel es copa
        if(i==0) {
            arbol[i][niveles-1] = '^';    
        } else {
            arbol[i][niveles-1] = '*';
        }

        // Resto de niveles rellenamos a ambos lados en función del nivel i
        for( int j = 0; j < i; j++ ){
            arbol[i][niveles-1-j-1] = '*';
            arbol[i][niveles-1+j+1] = '*';
        }

        // Luces
        // 1er nivel no tiene
        // 2do nivel puede tener en ninguna posición, 1a, 2a o 3a
        if(i>0) {
            // (2*(i+1)-1)+1 =
            // i+1 => nivel 
            // 2*(i+1)-1 => numero * por nivel
            // (2*(i+1)-1)+1 => sumamos 1 para representar la posibildiad de que no haya luz
            int numeroAstericos = 2*(i+1)-1;
            int posicionLuz = rand() % (numeroAstericos+1);

            // Si es 0 no hay luz
            if(posicionLuz != 0) {
                // Calculamos la posicion en Luz en funcion de la posicion intermedia
                int mitadNumeroAstericos = ceil((double)(numeroAstericos)/2);
                int posicionLuzRelativa = posicionLuz - mitadNumeroAstericos;    

                printf("nivel: %d, posicion luz: %d, posicion relativa a la mitad: %d, mod: %d \n", i,posicionLuz,posicionLuzRelativa,numeroAstericos+1);

                arbol[i][niveles-1+posicionLuzRelativa] = '+';

            } else {
                 printf("nivel: %d, posicion luz: %d, mod: %d -> no hay luz\n", i,posicionLuz,numeroAstericos+1);
            }      
        }
    }

    // Rellenamos tronco
    for(;i<alturaArbol; i++) {

        // Rellenamos todo vacío
        for( int j = 0; j <anchuraArbol; j++ ){
            arbol[i][j] = ' ';
        }

        arbol[i][niveles-1] = 'M';  
    }

    printf("==========================================\n");
    imprime((char*)arbol,alturaArbol,anchuraArbol);
    printf("\n Merry xMas!\n");

    return 0;
}

