
#include <iostream>
#include <stdio.h>
#include "Algoritmos.h" 
#include<fstream>
#include<sstream>


int Algoritmos::particion(PagedArray arreglo, int menor, int final, int pivote){
    int indice= menor;
    for (int i = menor; i <= final; i++)
    {
        if (*arreglo[i] <= pivote)
        {
            std::swap(*arreglo[indice], *arreglo[i]);
            indice ++;
        }
    indice--;
    return indice;
    }
    
}

int Algoritmos::Quicksort(PagedArray arreglo, int menor, int final){
    if(menor<final ){
        int pivote= *arreglo[final];
        int indice = particion(arreglo, menor, final, pivote);
        Quicksort(arreglo,menor,indice -1);
        Quicksort(arreglo, indice+1, final);
    }
    return 0;
}

int Algoritmos::Selectionsort(PagedArray arreglo, int size){

    int min, aux;
    for ( int i = 0; i < size; i++)
    {
        min =i;
        for (int j = 0; j < size; i++)
        {
            if (arreglo[j]<arreglo[min])
            {
                min=j;
            }
            
        }
        aux=*arreglo[i];
        *arreglo[i] =  *arreglo[min];
        *arreglo[min]= aux;

    }
    return 0;

}

int Algoritmos::Insertionsort(PagedArray arreglo, int size){
    int temp;
    int aux;
    for ( int i = 0; i < size; i++)
    {
        temp= i;
        int indice = *arreglo[i];
        while ((temp>0) && *arreglo[temp-1]>aux)
        {
            *arreglo[temp] = *arreglo[temp-1];
            temp--;
        }
        *arreglo[temp] =  aux;

    }
    
    return 0;
}