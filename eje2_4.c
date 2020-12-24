/*
Ejercicio 4: Árbol de navidad.
La siguiente función es capaz de recibir e imprimir por pantalla cualquier matriz de caracteres. Sabiendo esto, adapta el ejercicio del árbol de navidad del Laboratorio 1
del siguiente modo:
- Pedimos al usuario solo la altura de la copa del árbol.
- La copa se imprime con el carácter ‘^’
- El trono se imprime con el carácter ‘M’
- En cada fila de la copa se imprimirá aleatoriamente una luz (o ninguna) con el carácter ‘+’
- Sólo utilizaremos la siguiente función para imprimir el resultado en pantalla:
*/


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int tallTree,trunkTree; //defining tree sizes
int j,k,m,i; // iterators
int Array_Max;
int number;

int main() {
            
            do {
                printf ("\nHello user! Give me a number over 3 and I will drawn a christmas tree for you \n");
                scanf ("%d", &tallTree); //reading user inputs
                number = randomize();
                printf("%d", &number);
                    }
                        
                while (tallTree < 3); //limiting tree dimensions
                    
                for (i=0, j=tallTree; i<tallTree; i++, j--) { // bucle to drawn left side of the tree
                    for(k=0; k<j; k++){
                        printf(" ");
                        }
                        for(m=tallTree; m>=j; m--){ // bucle to drawn the tree
                            printf(" "); //a space in each iteration
                            printf ("^"); //a character in each iteration
                                }
                                printf ("\n");
                            }
                            trunkTree = tallTree/3; //defining trunk tree size
                    
                            for(j=1; j<=trunkTree; j++){  // bucle to drawn the trunk tree
                                for(i=0; i<tallTree; i++)
                                printf(" ");
                                printf(" M\n");
                            }
                            

        return 0;
}

void print(char * matriz , int m, int n){
    for (int i = 0; i < m; i++ ){
        for (int j = 0; j < n; j++){
            printf("%c", *(matriz + i*Array_Max + j));
        }
        printf("\n");
    }
}
