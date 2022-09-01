#include <iostream>
#include <stdio.h>
#include "CreacionListas.h"
#include "Algoritmos.h"

using namespace std;

int main()
{
    CreacionListas creacion;
    cout<<"Hola"<<endl;
    creacion.creacionLista("1kb", 1);
    creacion.convertirBinario("1kb");
    
    //cout<<argv[1]<<endl;
    /*if (string(argv[1])=="QS");
        cout<<"Seleccione el archivo que desea ordenar"<<endl;*/
    
    
 

    return 0;

}