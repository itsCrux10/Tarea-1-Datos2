#include "PagedArray.h"

class Algoritmos
{
private:
    int particion(PagedArray arreglo,int menor, int final, int pivote);
    int swap(int *a, int*b);
public:
    int Quicksort(PagedArray arreglo, int menor, int final);
    int Selectionsort(PagedArray arreglo,int size);
    int Insertionsort(PagedArray arreglo,int size);
};

