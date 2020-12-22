/* 
Este es el primer ejercicio del laboratorio 2: Implementa un programa que ofrezca un menú al usuario para realizar las siguientes operaciones con matrices 
de números reales de tamaño 3x3:
1.Suma de dos matrices,A y B
2.Resta de dos matrices, A y B
3.Multiplicación de dos matrices, A y B
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of rows and columns size (3 x 3) of matrix
#define rows 3
#define colms 3

// Global definition of functions which are going to used then to make operations

void matrixUser (double [rows][colms]); // this is the function which ask to the user the matrix 
void showMatrix (double [rows][colms]); // this the function which will show to the user selected matrix
void sumMatrix (double [rows][colms], double [rows][colms]); // this the function which will sum both matrix
void restMatrix (double [rows][colms], double [rows][colms]); // this the function which will rest both matrix
void prodMatrix (double [rows][colms], double [rows][colms]); // this the function which will get the product both matrix


int main() {
    // Local definition of variables related to user matrix
    double matrixA[rows][colms];
    double matrixB[rows][colms];
    char option1;

    // Asking the user first matrix
    printf("Please, Enter your first matrix of 3 rows and columns \n");
    matrixUser(matrixA);
     // Asking the user second matrix
    printf("Please, Enter your second matrix of 3 rows and columns \n");
    matrixUser(matrixB);
    // Showing to the user selected matrix A & B 
    showMatrix(matrixA);
    showMatrix(matrixB);
    
    do {
        printf( "\n--Choose an operation to do-- \n\n" );
                    printf( "1) Sum two matrix \n");
                    printf( "2) Rest two matrix \n");
                    printf( "3) Multiply two matrix \n");
                    printf( "4) Exit \n\n" );
        do {
             printf( "Introduce an option (1-4): \n"); // Filter user choosen operation
             scanf( " %c", &option1);
            } while ( option1 < '1' || option1 > '4' ); // It has to be between 1-6
        
        switch ( option1 ){

            case '1':  // Matrix's Sum
                        printf("\n This is the sum of your selected matrix \n");
                        sumMatrix(matrixA, matrixB);
                        break;
            case '2':  // Matrix' Rest
                        printf("\n This is the rest of your selected matrix \n");
                        restMatrix(matrixA, matrixB);
                        break;
            case '3':   // Matrix' product
                        printf("\n This is the product of your selected matrix \n");
                        prodMatrix(matrixA, matrixB);
            } 
        } while ( option1 != '4' ); // Option 6: exit from the calculator
       

    return 0;
}

void matrixUser(double Matrix[rows][colms]) {
    int row;
    int colm;
    printf("\n");
    for (row = 0; row < rows; row ++) {
        for (colm = 0; colm < colms; colm ++) {
            printf("Position %d - %d :", row, colm);
            scanf(" %lf", &Matrix[row][colm]);
        }
    }
    printf("\n");
}

void showMatrix(double Matrix[rows][colms]) {
    int row;
    int colm;
    printf("\n");
    for (row = 0; row < rows; row ++) {
        for (colm = 0; colm < rows; colm ++) {
            printf("%6.1lf", Matrix[row][colm]);
        }
    printf("\n");
    }
}

void sumMatrix (double matrixA[rows][colms], double matrixB[rows][colms]) {
    int row;
    int colm;
    double result[rows][colms];
    for (row = 0; row < rows; row ++) {
        for (colm = 0; colm < colms; colm ++) {
            result[row][colm] = matrixA[row][colm] + matrixB[row][colm];
        }
    }
    showMatrix(result);
}

void restMatrix (double matrixA[rows][colms], double matrixB[rows][colms]) {
    int row;
    int colm;
    double result[rows][colms];
    for (row = 0; row < rows; row ++) {
        for (colm = 0; colm < colms; colm ++) {
            result[row][colm] = matrixA[row][colm] - matrixB[row][colm];
        }
    }
    showMatrix(result);
}

void prodMatrix (double matrixA[rows][colms], double matrixB[rows][colms]) {
    int row;
    int colm;
    double result[rows][colms];
    for (int colB = 0; colB < colms; colB ++) {
        for (int rowA = 0; rowA < rows; rowA ++) {
            int sum = 0;
            for (int colA = 0; colA < colms; colA++) {
                sum += matrixA[rowA][colA] * matrixB[colA][colB]; 
            }
            
            result[rowA][colB] = sum;
        }
    }
    showMatrix(result);
}