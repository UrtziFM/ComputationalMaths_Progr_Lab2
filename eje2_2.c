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

// Global definition of show information function
void showPerson (struct person);

int main() {

    struct person p; // we use p instance here
    
    printf( "Please, introduce your name here: \n" );
    fgets(p.name, 30, stdin); // better use fgets function here to avoid blanks
    p.name[strcspn(p.name, "\r\n")]= 0; // this function avoid line break of fgets
    printf( "Please, introduce your first surname here: \n" );
    fgets(p.surname1, 30, stdin);
    p.surname1[strcspn(p.surname1, "\r\n")]= 0;
    printf( "Please, introduce your second surname here: \n" );
	fgets(p.surname2, 30, stdin);
    p.surname2[strcspn(p.surname2, "\r\n")]= 0;
    printf( "Please, introduce your country: \n" );
	fgets(p.address_person.country, 30, stdin ); // we nesting in the structures of person and address
    p.address_person.country[strcspn(p.address_person.country, "\r\n")]= 0;
    printf( "Please, introduce your city: \n" );
	fgets(p.address_person.city, 30, stdin); 
    p.address_person.city[strcspn(p.address_person.city, "\r\n")]= 0;
    printf( "Please, introduce your street: \n" );
	fgets(p.address_person.street, 30, stdin);
    p.address_person.street[strcspn(p.address_person.street, "\r\n")]= 0;
    printf( "Please, introduce your street number: \n" );
	scanf( " %d", &p.address_person.number );
    printf( "Please, introduce your flat number: \n" );
	scanf( " %d", &p.address_person.flat );
    printf( "Please, introduce your flat letter: \n" );
	scanf( " %s", p.address_person.letter );
    printf( "Please, introduce your age here: \n" );
	scanf( " %d", &p.age );

    showPerson(p); //calling function with the instance
    return 0;
}

void showPerson (struct person data){ //defining fnction
    printf("There is your personal information: \n %s %s %s \nyour address is:\n %s %d - %dº%s, %s (%s)\nand you are: \n%d years old\n",
    data.name, data.surname1, data.surname2, data.address_person.street, data.address_person.number, data.address_person.flat, data.address_person.letter, 
    data.address_person.city, data.address_person.country, data.age);
}