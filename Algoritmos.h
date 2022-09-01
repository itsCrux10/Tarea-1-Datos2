class Algoritmos
{
private:
    int particion(int array[],int menor, int final, int pivote);
    int swap(int *a, int*b);
public:
    int Quicksort(int *array, int menor, int final);
    int Selectionsort(int array[],int size);
    int Insertionsort(int array[],int size);
};

