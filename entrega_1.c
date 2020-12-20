/* 
Este es el archivo unico con los 6 ejercicios del laboratorio 1 de Urtzi Arana
Cada ejercicio tiene comentarios para entender mejor el codigo utilizado
*/

#include <stdio.h>
#include <math.h> // I am using this library to use squirt & pow functions
#include <ctype.h> // I am using this library to resolve if the input is a letter or a number

int main() {
    /*
    First, define global variables
    */
    char option; // this is a exercise selector 
    char option1; // this is a calculator operation selector
    char option2; // this is a geometric operation selector
    double num1, num2;  //variables for some exercises
    double PI = 3.141592; //Pi 
    int tallTree,trunkTree; //defining tree sizes
    int j,k,m,i; // iterators
    char formatTree; // defining tree
    double realNum; // decimal numbers
    int userInput_1, userInput_2; // Define user inputs like integers
    int pairs; // Define a variable to get pairs numbers  
    char userInput; // Define variable like a char

    do {
        printf( "--Choose an exercise to review-- \n\n" );
        printf( "1. exercise \n");
        printf( "2. exercise \n");
        printf( "3. exercise \n");
        printf( "4. exercise \n");
        printf( "5. exercise \n" );
        printf( "6. exercise \n" );
        printf( "7) Exit \n\n" );

        do {
            printf( "Introduce an exercise (1-7): \n\n"); // Filter user choosen operation
            scanf( " %c", &option);

        } while ( option < '1' || option > '7' ); // It has to be between 1-6

         switch ( option ){

             case '1':  printf("\nHello user!, Please, enter only a letter or a number \n");
                        scanf(" %c", &userInput); // read the user input
                        if (isalpha(userInput)){  //conditional for validation of the user input as a letter
                            printf("This is a letter, and is: %c\n", userInput);
                        } else if (isdigit(userInput)){ //next conditional for validation of the user input as a number
                            printf("This is a number, and is: %c\n", userInput);
                        } else { // in other cases
                            printf("Did you read the Question? It was a letter or a number! and not this: %c\n", userInput);
                        }
                        break;

              case '2': printf("\nHello user!, Please, enter two integers \n");
                        if (!scanf("%d", &userInput_1)){ // read the user input to make a conditional if her is introducing not an integer
                            printf("Sorry I asked two natural numbers \n"); // 
                        } else if (!scanf("%d", &userInput_2)){
                            printf("Sorry I asked two integers \n"); // 
                        } else {
                        int sum = userInput_1 + userInput_2; // new output with the sum of both numbers
                        if (userInput_1 < userInput_2){  //conditional for validation if first input is lower than second one
                            for (pairs = userInput_1; pairs <= userInput_2; pairs++){ //the loop for pairs numbers
                                if (pairs %2 == 0){ //validation for pairs number 
                                    printf("These are pairs in range: %d \n", pairs);
                                }
                            }
                        } else {
                            for (pairs = userInput_2; pairs <= userInput_1; pairs++){
                                if (pairs %2 == 0){
                                    printf("These are: %d \n", pairs);
                                }
                            }
                        } 
                        printf("The sum of both number is: %d \n", sum); // finally getting the sum
                        }
                        break;

              case '3': printf("\nHello user! Please enter a real number \n");
                        printf("Remember that this program will finish with a 0 \n");
                        scanf("%lf", &realNum); // read user input
                        do { // start the loop
                            if(realNum < 0){  
                                printf("Negative \n");
                            } else if (realNum > 0){
                                printf("Positive \n");
                            } else // the loop finish with a 0
                            {
                                break;
                            }
                        } while (scanf("%lf", &realNum));
                        break;

              case '4': do {

                            printf( "\n--Choose an operation to do-- \n\n" );
                            printf( "1) Sum two numbers \n");
                            printf( "2) Rest two numbers \n");
                            printf( "3) Multiply two numbers \n");
                            printf( "4) Divide two number \n");
                            printf( "5) Square root of two numbers \n" );
                            printf( "6) Exit \n\n" );

                            do{
                                printf( "Introduce an option (1-6): \n"); // Filter user choosen operation
                                scanf( " %c", &option1);
                            } while ( option1 < '1' || option1 > '6' ); // It has to be between 1-6

                            switch ( option1 ){
                                case '1': printf( "Introduce first number: \n" ); //Option 1: Sum
                                        scanf( "%lf", &num1);
                                        printf( "Introduce second number: \n" );
                                        scanf( "%lf", &num2);
                                        printf( "%lf + %lf = %lf\n", num1, num2, num1 + num2 );
                                        break;

                                case '2': printf( "Introduce first number: \n" ); //Option 2: Rest
                                        scanf( "%lf", &num1);
                                        printf( "Introduce second number: \n" );
                                        scanf( "%lf", &num2);
                                        printf( "%lf - %lf = %lf\n", num1, num2, num1 - num2 );
                                        break;

                                case '3': printf( "Introduce first number: \n" ); //Option 3: Multiply
                                        scanf( "%lf", &num1);
                                        printf( "Introduce second number: \n"  );
                                        scanf( "%lf", &num2);
                                        printf( "%lf * %lf = %lf\n", num1, num2, num1 * num2 );
                                        break;

                                case '4': printf( "Introduce first number: \n"  ); //Option 4: Divide
                                        scanf( "%lf", &num1);
                                        printf( "Introduce second number: \n" );
                                        scanf( "%lf", &num2);
                                        if ( num2 != 0 )
                                            printf( "%lf div %lf = %lf \n", num1, num2, num1 / num2);
                                        else
                                            printf( "Wrong! You cannot divide by 0 \n" );
                                        break;

                                case '5': printf( "Introduce a number: \n"  ); //Option 5: Square root
                                        scanf( "%lf", &num1);
                                        printf( "%lf  sqrt is %lf \n", num1, sqrt(num1)); //you will need gcc ... -lm
                                        break;
                            }

                        } while ( option1 != '6' ); // Option 6: exit from the calculator
                        break;

              case '5': do {
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
                            break;

              case '6': do {
                            printf( "\n--Choose an operation to do-- \n\n" );
                            printf( "1) Calculate area and perimeter of a square \n");
                            printf( "2) Calculate area and perimiter of a circle \n");
                            printf( "3) Calculate area and perimeter of a triangule \n");
                            printf( "4) Calculate area and perimeter of a rectangle \n");
                            printf( "5) Calculate area and perimeter of a hexagon \n" );
                            printf( "6) Exit \n\n" );

                            do{
                                printf( "Introduce an option (1-6): \n"); // Filter user choosen operation
                                scanf( " %c", &option2);
                            } while ( option2 < '1' || option2 > '6' ); // It has to be between 1-6

                            switch ( option2 ){
                                case '1': printf( "Introduce square height in meters: \n" ); //Option 1: Square
                                        scanf( "%lf", &num1);
                                        printf( "Introduce square width in meters: \n" );
                                        scanf( "%lf", &num2);
                                        if(num1 == num2){
                                        printf( "The perimeter of the square is: %lf meters \n", num1*2+num2*2 );
                                        printf( "The area of the square is: %lf meters \n\n", num1*num2 );
                                        } else {
                                            printf("This is not a square my friend \n\n");
                                        }
                                        break;

                                case '2': printf( "Introduce circle radius in meters: \n" ); //Option 2: Circle
                                        scanf( "%lf", &num1);
                                        printf( "The perimeter of the circle is: %lf meters \n", num1*2*PI );
                                        printf( "The area of the circle is: %lf meters \n\n", pow(num1, 2)*PI );
                                        break;

                                case '3': printf( "Introduce triangule height in meters: \n" ); //Option 3: Triangule
                                        scanf( "%lf", &num1);
                                        printf( "Introduce triangule base in meters: \n" );
                                        scanf( "%lf", &num2);
                                        printf( "The perimeter of the triangule is: %lf meters \n", (num2*3)/2 );
                                        printf( "The area of the triangule is: %lf meters \n\n", (num1*num2)/2 );
                                        break;

                                case '4': printf( "Introduce rectangule height in meters: \n"  ); //Option 4: Rectangule
                                        scanf( "%lf", &num1);
                                        printf( "Introduce rectangule width in meters: \n" );
                                        scanf( "%lf", &num2);
                                        if(num1 != num2){
                                        printf( "The perimeter of the square is: %lf meters \n", num1*2+num2*2 );
                                        printf( "The area of the square is: %lf meters \n\n", num1*num2 );
                                        } else {
                                            printf("This is a square my friend \n\n");
                                        }
                                        break;

                                case '5': printf( "Introduce hexagon side lenght in meters: \n"  ); //Option 5: Hexagon
                                        scanf( "%lf", &num1);
                                        printf( "Introduce hexagon height in meters: \n" );
                                        scanf( "%lf", &num2);
                                        printf( "The perimeter of the hexagon is: %lf meters \n", num1*6 );
                                        printf( "The area of the square is: %lf meters \n\n", (num1*(num2/2))/2 );
                                        break;
                            }

                        } while ( option != '6' ); // Option 6: exit from the calcutor
                        break;
                    
                    }

    } while ( option != '7' ); // Option 7: exit 
    
    return 0;
}
