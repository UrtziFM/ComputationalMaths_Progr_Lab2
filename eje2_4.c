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

int tallTree,trunkTree; //defining tree sizes
int j,k,m,i; // iterators
char formatTree; // defining tree

int main() {
            
            do {
                printf ("\nHello user! Give me a number and I will drawn a christmas tree for you \n");
                printf("Your selected number it has to be between 4 and 20 \n");
                printf("Then, select your tree's type: number, letter or symbol \n");
                scanf ("%d %c", &tallTree, &formatTree); //reading user inputs
                    }
                        
                while (tallTree < 3 || tallTree > 20); //limiting tree dimensions
                    
                for (i=0, j=tallTree; i<tallTree; i++, j--) { // bucle to drawn left side of the tree
                    for(k=0; k<j; k++){
                        printf(" ");
                        }
                        for(m=tallTree; m>=j; m--){ // bucle to drawn the tree
                            printf(" "); //a space in each iteration
                            printf ("%c", formatTree); //a character in each iteration
                                }
                                printf ("\n");
                            }
                            trunkTree = tallTree/3; //defining trunk tree size
                    
                            for(j=1; j<=trunkTree; j++){  // bucle to drawn the trunk tree
                                for(i=0; i<tallTree; i++)
                                printf(" ");
                                printf(" %c\n", formatTree);
                            }
                            

        return 0;
}
