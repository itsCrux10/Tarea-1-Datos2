#include <iostream>
#include <stdlib.h>
#include <string>
#include "CreacionListas.h" 
#include<fstream>
#include <sstream>
using namespace ::std;


int CreacionListas::creacionLista(string filename, int kb){
    filename+=".csv";
    fstream archivo;
    string direccion= "/home/cruz/Desktop/Tarea-1-Datos2/Listas/" + filename ;
    int maxNum= 256*kb;
    int tmp;
    archivo.open(direccion.c_str(),ios::app);

    if (archivo.fail()){
        cout<<"Error al crear el archivo"<<endl;
        exit(1);
    }
    for(int i = 0; i <= maxNum; i++){
        tmp =  rand()%(1-10000);
        if (i == maxNum){
            archivo<<tmp;
        }else{
            archivo<<tmp<<",";
        }

    }

    return 0;
}


int CreacionListas::convertirBinario(string filename){
    string direccion= "/home/cruz/Desktop/Tarea-1-Datos2/Listas/" + filename+".csv" ;
    string direccion2= "/home/cruz/Desktop/Tarea-1-Datos2/Listas/" + filename+"Binario.bin" ;
    string line,word;
    fstream intFile(direccion, ios::in);
    ofstream binFile(direccion2, ios::binary);
    if (intFile.is_open()){
        while (getline(intFile, line)) {
            stringstream str(line);
            while (getline(str, word, ',')) {
                //cout << word << " ";
                int num = stoi(word);
                binFile.write(reinterpret_cast<const char *>(&num), sizeof(num));
            }
        }
    }
    binFile.close();

}