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


#include <stdio.h>      // printf()
#include <math.h>       // ceil()
#include <stdlib.h>     // rand(), srand()
#include <time.h>       // time()

int Array_Max;
int tallTree;
int i,j;

void printTree(char* matrix , int m, int n){ // Global function, it prints our tree matrix 
    for (int i = 0; i < m; i++ ){
        for (int j = 0; j < n; j++){
            printf("%c", *(matrix + i*Array_Max + j));
        }
        printf("\n");
    }
}

int main() {

            srand(time(NULL)); // We are reactivating random lights with this seed function, avoiding repeating in each try from user get the same output

            do {
                printf ("\nHello user! Give me a number over 3 and I will drawn a christmas tree for you \n");
                scanf ("%d", &tallTree); //reading user inputs
                } while (tallTree < 3); //at least we need 4 levels to draw correctly a christmas tree 

            int trunkTree = ceil((double)(tallTree)/4); // using ceil function we are helping to have correct dimensions of the trunk, easier than in the first lab. 
            int totalTree  = tallTree + trunkTree;
            int widthTree = 2*tallTree-1; // we can use maths to calculate width and tall proportional relationship in a tree.
            
            char tree[totalTree][widthTree]; // this is a our matrix, initializated without prefixed rows and columns, as it was asked in the last class 
            Array_Max = widthTree;

                for (i = 0; i < tallTree; i++) { 

                    for(j = 0; j < widthTree; j++ ){
                        tree[i][j] = ' ';
                        }

                       if(i==0) {
                            tree[i][tallTree-1] = '+';  // you always need a Christ' Star light on the top of a Tree.  
                            } else {
                            tree[i][tallTree-1] = '*';  // Drawing rest of the tree
                            }
                        
                        for(j = 0; j < i; j++ ){   // Drawing rest of the tree
                            tree[i][tallTree-1-j-1] = '*';
                            tree[i][tallTree-1+j+1] = '*';
                                }
                            
                        if(i>0) { // now we randomize lights 
                    
                        int dots = 2*(i+1)-1; // total dots by level
                        int lightposition = rand() % (dots+1); // rand() function give us position of the light randomize module dots+1 (pair)

                        if(lightposition != 0) { // drawing lights... if there are lights (!=0) 
                        int halftree = ceil((double)(dots)/2); // taking to start counting half of the tree level where we are drawing
                        int lightsituation = lightposition - halftree;  // from this halftree, get the right (>0) or left (<0) situation  

                        tree[i][tallTree-1+lightsituation] = '+';
                            } 
                        }
                    }        
                            
                        for(; i < totalTree; i++) { // drawing the trunk
 
                        for( int j = 0; j < widthTree; j++ ){ // first empty drawn
                            tree[i][j] = ' ';
                            }
                            tree[i][tallTree-1] = 'M';  // finally trunk drawn
                        }
                          
            printTree((char*)tree, totalTree, widthTree);
            printf("\nThere here is, your desired christmas tree, happy new year my friend!!\n");
                            
 
        return 0;
}

