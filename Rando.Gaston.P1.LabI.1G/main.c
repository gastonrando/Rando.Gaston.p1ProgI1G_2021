#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 5

typedef struct
{
    int id;
    char nombre [20];
    char tipo;
    float efectividad;

} eVacuna;


float aplicarAumento (float precio);
int ordenarVacunaTipoEfectividad(eVacuna lista[], int largo);
int remplazarCaracter (char cadenaCaracter[], char caracterDos, char caracterTres);


int main()
{


    //Calcular Descuento
    float precio;

    printf("Ingrese el precio: ");
    scanf("%f", &precio);

    printf("el producto cuesta $ %.2f y con un Aumento del 5%% queda en %.2f \n", precio, aplicarAumento(precio));


   /*//caracteres
   char cadena[10];
   char caracterDos;
   char caracterTres;

    printf("Ingrese cadena de caracteres: ");
    gets(cadena);
    strlwr(cadena);

    printf("Ingrese el caracter que quiere buscar en la cadena de caracteres: ");
    fflush(stdin);
    scanf("%c", &caracterDos);
    caracter=tolower(caracterDos);

    printf("Ingrese el caracter por el que quiere remplazar en la cadena de caracteres: ");
    fflush(stdin);
    scanf("%c", &caracter);
    caracter=tolower(caracter);
*/



 //Structura vacuna:

    eVacuna lista[TAM] =
    {
        {1,"AZTRAZENECA",'f',90.5},
        {4,"COVISHIELD",'m',80.5},
        {2,"SPUTNIK",'f',50},
        {3,"PFIZER",'g',60},
        {5,"MODERNA",'m',72.5}
    };

    printf("\n --------------------------------------- \n\n");

    for(int i= 0; i<TAM; i++ )
    {
        printf("  %d     %-20s    %-10c     %10.2f \n", lista[i].id, lista[i].nombre, lista[i].tipo, lista[i].efectividad);
    }

    ordenarVacunaTipoEfectividad(lista, TAM);
    printf("\n --------------------------------------- \n\n");

    for(int i= 0; i<TAM; i++ )
    {
        printf("  %d     %-20s    %-10c     %10.2f \n", lista[i].id, lista[i].nombre, lista[i].tipo, lista[i].efectividad);
    }

    system("pause");

    return 0;
}


float aplicarAumento (float precio)
{

    float precioFinal;

    precioFinal = precio + (precio*0.05);

    return precioFinal;
}


int ordenarVacunaTipoEfectividad(eVacuna lista[], int largo)
{

    int todoOk=0;
    eVacuna auxLista;



    if(lista != NULL && largo >0)
    {
        for(int i=0; i < largo-1; i++)
        {
            for(int j= i + 1; j < largo ; j++)
            {

                if((lista[i].tipo > lista[j].tipo) ||
                        (lista[i].tipo == lista[j].tipo && lista[i].efectividad > lista[j].efectividad))
                {


                    auxLista= lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxLista;
                }

            }
        }
        todoOk=1;
    }
    return todoOk;
}




int remplazarCaracter (char cadenaCaracter[], char caracterDos, char caracterTres)
{

    int cantidad =0;
    int i = 0;
    int contador=0;

    if(cadenaCaracter != NULL && caracterDos != NULL && caracterTres != NULL)
    {
        while(cadenaCaracter[i] != '\0')
        {
            if(cadenaCaracter[i] == caracterDos)
            {

                cadenaCaracter[i]=caracterTres;
                contador++;
            }
            i++;
        }

    }
    return cantidad;
}

