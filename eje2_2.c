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

typedef struct domicilio {
    char pais[20];
    char ciudad[25];
    char calle[50];
    int numero[4];
    int piso[3];
    char letra[2];
} Domicilio;

typedef struct persona {
    char nobre[10];
    char apellido1[15];
    char apellido2[15];
    struct domicilio
    {
        /* data */
    };
    
    int edad[3];
} Persona;