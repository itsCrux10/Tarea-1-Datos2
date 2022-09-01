#include <iostream>
#include <stdio.h>
#include "CreacionListas.h"
#include "Algoritmos.h"
#include "PagedArray.h"

using namespace std;

int main(int argc, char **argv)
{
    CreacionListas creacion;
    Algoritmos algoritmos;
    string nombreArch= argv[2];
    string algoritmo = argv[4];
    cout<<argv[1]<<endl;
    if (argc == 7){


        PagedArray pagedArray(argv[2], argv[6]);
        nombreArch.erase(nombreArch.end()-6, nombreArch.end());
        int tamano= stoi(nombreArch);
        creacion.creacionLista(argv[2],tamano );
        if(algoritmo == "SS") {
            algoritmos.Selectionsort(pagedArray, tamano * 256);
        } else if (algoritmo== "IS"){
            algoritmos.Insertionsort(pagedArray,tamano *256);
        }else if(algoritmo =="QS"){
            algoritmos.Quicksort(pagedArray, 0, tamano *256);
        }

    }
    return 0;

}