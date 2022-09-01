//
// Created by cruz on 31/08/22.
//


#ifndef TAREA_1_DATOS2_PAGEDARRAY_H
#define TAREA_1_DATOS2_PAGEDARRAY_H

#include <iostream>
#include <string>
using  namespace std;

class PagedArray {

public:
    PagedArray(string text_file, string output);

    int* operator [] (int pos);

    void operator = (int a);

    int saveArray();

    int printArray();

    int createOutputFile();
private:

    string textfile;
    string binaryfile;
    string outputpath;
    string pathBinary;
    string output;
    int size;
    int last_page;
    int pagesInMemory[6];

    int Pages[6][256];

    int loadFirstPages();

    int loadPage(int pagePos, int pageNum);

    int writePage(int pagePos, int pageNum);

    int* getNumber(int pos);

};


#endif //TAREA_1_DATOS2_PAGEDARRAY_H
