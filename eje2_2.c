/* 
Ejercicio 2: estructuras
Implementa un programa en C que defina las siguientes estructuras:
- Domicilio. Con los campos: País, Ciudad, Calle, Número, Piso, Letra.
- Persona. Con los campos: Nombre, Apellido1, Apellido2, Domicilio, Edad.
El programa debe solicitar al usuario la información completa de una persona e imprimirla en pantalla.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 30

//Defining neccesary structures 
typedef struct address {
    char country[length];
    char city[length];
    char street[length];
    int number;
    int flat;
    char letter[length];
} Address;

// nested structure
typedef struct person {
    char name[length];
    char surname1[length];
    char surname2[length];
    int age;
    struct address address_person;
} Person;

// Global definition of functions which are going to used then to make operations
void showPerson (Person* person);

int main() {

    struct person p;
    struct address a;
    
    printf( "Please, introduce your name here: \n" );
	scanf( " %s", &p.name );
    printf( "Please, introduce your first surname here: \n" );
	scanf( " %s", &p.surname1 );
    printf( "Please, introduce your second surname here: \n" );
	scanf( " %s", &p.surname2 );
    printf( "Please, introduce your age here: \n" );
	scanf( " %d", &p.age );
    printf( "Please, introduce your country: \n" );
	scanf( " %s", &a.country );
    printf( "Please, introduce your city: \n" );
	scanf( " %s", &a.city );
    printf( "Please, introduce your street: \n" );
	scanf( " %s", &a.street );
    printf( "Please, introduce your street number: \n" );
	scanf( " %d", &a.number );
    printf( "Please, introduce your flat number: \n" );
	scanf( " %d", &a.flat );
    printf( "Please, introduce your flat letter: \n" );
	scanf( " %s", &a.letter );

    //showPerson(Person person);
    return 0;
}

void showPerson (Person* person){ 
    printf("There is your personal information: \n%s %s %s %s \n",
    (*person).name, (*person).surname1, (*person).surname2, (*person).address_person);
    printf("Your age is: %d \n", (*person).age);
}