
#include <iostream>
#include <stdio.h>
#include "Algoritmos.h" 
#include<fstream>
#include<sstream>


int Algoritmos::particion(int *array, int menor, int final, int pivote){
    int indice= menor;
    for (int i = menor; i <= final; i++)
    {
        if (array[i] <= pivote)
        {
            std::swap(array[indice], array[i]);
            indice ++;
        }
    indice--;
    return indice;
    }
    
}

int Algoritmos::Quicksort(int *array, int menor, int final){
    if(menor<final ){
        int pivote= array[final];
        int indice = particion(array, menor, final, pivote);
        Quicksort(array,menor,indice -1);
        Quicksort(array, indice+1, final);
    }
    return 0;
}

int Algoritmos::Selectionsort(int *array, int size){

    int min, aux;
    for ( int i = 0; i < size; i++)
    {
        min =i;
        for (int j = 0; j < size; i++)
        {
            if (array[j]<array[min])
            {
                min=j;
            }
            
        }
        aux=array[i];
        array[i] =  array[min];
        array[min]= aux;

    }
    return 0;

}

int Algoritmos::Insertionsort(int *array, int size){
    int temp;
    int aux;
    for ( int i = 0; i < size; i++)
    {
        temp= i;
        int indice = array[i];
        while ((temp>0) && array[temp-1]>aux)
        {
            array[temp] = array[temp-1];
            temp--;
        }
        array[temp] =  aux;

    }
    
    return 0;
}