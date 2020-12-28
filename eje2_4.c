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
#include <stdlib.h>     // rand(), srand()
#include <time.h>       // time()

int tallTree,trunkTree; //defining tree sizes
int j,k,m,i; // iterators
int Array_Max;

void print(char * matrix , int m, int n){
    for (int i = 0; i < m; i++ ){
        for (int j = 0; j < n; j++){
            printf("%c", *(matrix + i*Array_Max + j));
        }
        printf("\n");
    }
}

int main() {

            int totalTree  = tallTree + trunkTree;
            int widthTree = 2*tallTree-1;
            char tree[totalTree][widthTree];
            Array_Max = widthTree;

            
            do {
                printf ("\nHello user! Give me a number over 3 and I will drawn a christmas tree for you \n");
                scanf ("%d", &tallTree); //reading user inputs
                    }
                        
                while (tallTree < 3); //limiting tree dimensions
                    
                for (i=0;i<tallTree; i++) { // bucle to drawn left side of the tree
                    for( int j = 0; j <widthTree; j++ ){
                        tree[i][j] = ' ';
                        }
                        for( int j = 0; j < i; j++ ){
                            tree[i][tallTree-j-1] = '*';
                            tree[i][tallTree+j+1] = '*';
                            }

                                printf ("\n");
                            }
                            trunkTree = tallTree/3; //defining trunk tree size
                    
                            for(j=1; j<=trunkTree; j++){  // bucle to drawn the trunk tree
                                for(i=0; i<tallTree; i++)
                                printf(" ");
                                printf(" M\n");
                            }

            printf("==========================================\n");
            print((char*)tree,totalTree,widthTree);
            printf("\n Merry xMas!\n");
                            

        return 0;
}

