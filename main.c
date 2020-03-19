#include <stdio.h>

// Pedro Antonio Estévez Pérez

// Ejercicio 14

/* Componer en una variable de tipo unsigned char un dato de 8 bits a
 * partir de los 4 bits de menor peso contenidos en dos variables de tipo
 *  unsigned short int n_low y n_high.*/


int main(void)
{
    unsigned short int alto, bajo;
    unsigned char composicion;
    int contador = 0, i, aux = 0;

    printf("Introduce un numero: ");
    scanf("%hu", &alto); // Los unsigned short int se leen asi
    printf("Introduce otro numero: ");
    scanf("%hu", &bajo);

    /* Al igual que en los ejercicios anteriores, antes de nada imprimimos
     * los números en binario para ver en cuanto acabe el ejercicio que está
     * correcto. Quitaré todos los ceros a la izquierda para ver mejor los
     * últimos 4 bits. */

    printf("El primer numero en binario es: ");
    for(i = 32768; i > 0; i >>= 1)
    {
        if(i & alto)
        {
            printf("1");
            aux = 1;
        }
        else
        {
            if (aux == 0)
            {
                contador++;
                continue;
            }
            else
                printf("0");
        }
    }
    printf("b\n");
    contador = 0;
    aux = 0;

    printf("El segundo numero en binario es: ");
    for(i = 32768; i > 0; i >>= 1)
    {
        if(i & bajo)
        {
            printf("1");
            aux = 1;
        }
        else
        {
            if (aux == 0)
            {
                contador++;
                continue;
            }
            else
                printf("0");
        }
    }
    printf("b\n");

    /* En este caso, en vez de 4 bits como en el caso anterior, tenemos 8 bits para ver su valor
     * por lo que habrá que hacer 4 ifs, cada uno de los cuales puede darnos un 1 o un 0.*/

    alto = alto & 0x000F;
    bajo = bajo & 0x000F;
    composicion = alto;
    composicion = composicion << 4;
    composicion = composicion | bajo;


    /* Por último, imprimimos el binario resultante para comprobar que es correcto.*/

    printf("La composicion es: ");
    for(i = 128; i > 0; i >>= 1)
    {
        if(i & composicion)
            printf("1");
        else
            printf("0");
    }
    printf("b\n");

    printf("Que equivale al caracter: %c\n\n", composicion);

}
