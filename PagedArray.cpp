#include "PagedArray.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

PagedArray::PagedArray(string text_file, string out_put) {
    textfile = text_file;
    output = out_put;
    textfile.erase(textfile.end()-4, textfile.end());
    binaryfile = textfile + "Binary.bin";
    textfile.erase(textfile.end()-2, textfile.end());
    size = stoi(textfile);
    cout << "Size of text file is: " << size << " Kilobytes" << endl;
    pathBinary = "/home/itsrichard/Documentos/Proyectos C++/Tarea Extraclase 1/Paginated Array/FilesBinary/" + binaryfile;
    outputpath = "/home/itsrichard/Documentos/Proyectos C++/Tarea Extraclase 1/Paginated Array/ResultFiles/" + output;
    last_page = 0;
    for (int i = 0; i < 6; ++i) {
        pagesInMemory[i] = 0;
    }
    loadFirstPages();
}

int PagedArray::loadFirstPages(){
    for (int i = 0; i < 6 && i < size; ++i) {
        pagesInMemory[i] = i + 1;
        loadPage(i, i + 1);
    }
}

int PagedArray::loadPage(int pagePos, int pageNum) {
    ifstream binary;
    binary.open(pathBinary, ios::in | ios::binary);
    streampos pos = binary.tellg();
    pagesInMemory[pagePos] = pageNum;
    int num;
    int pageStart = (pageNum-1) * 256 * 4;
    binary.seekg(pageStart, ios::beg);
    pos = binary.tellg();
    cout << "The read pointer is now at location: " << pos << endl;
    cout << "Page " << pageNum << " saved in Array Slot: " << (pagePos + 1) << endl;
    for (int i = 0; i < 256 ; ++i) {
        binary.read((char*)&num, sizeof(int));
        Pages[pagePos][i] = num;
    }
    binary.close();
    if (last_page < 5){
        last_page++;
    } else{
        last_page = 0;
    }
    return 0;
}

int PagedArray::writePage(int pagePos, int pageNum){
    ofstream binary;
    binary.open(binaryfile, ios::binary | ios::out);
    int pageStart = (pageNum-1) * 256 * 4;
    binary.seekp(pageStart, ios::beg);
    streampos pos = binary.tellp();
    cout << "The write pointer is now at location: " << pos << endl;
    for (int i = 0; i < 256; ++i) {
        binary.write(reinterpret_cast<const char *>(&Pages[pagePos][i]), sizeof(int));
    }
    cout << "Page " << pageNum << " successfully saved in local memory" << endl;
    return 0;
}

int* PagedArray::getNumber(int pos){
    int page = ((int) (pos / 256)) + 1;
    //cout << "Position: " << page << endl;
    int position = pos % 256;
    int slot = last_page;
    for (int i = 0; i < 6; ++i) {
        if (pagesInMemory[i] == page){
            return &Pages[i][position];
        }
    }
    writePage(last_page, pagesInMemory[last_page]);
    loadPage(last_page, page);
    return &Pages[slot][position];
}

int* PagedArray::operator [] (int pos){
    //cout << "[" << pos << "," << num << "]" << endl;
    return getNumber(pos);
}

int PagedArray::saveArray() {
    for (int i = 0; i < 6; ++i) {
        if (pagesInMemory[i] != 0){
            writePage(i, pagesInMemory[i]);
        }
    }
    return 0;
}

int PagedArray::printArray() {
    for (int i = 0; i < 6; ++i) {
        cout << endl;
        for (int j = 0; j < 256; ++j) {
            cout << Pages[i][j] << " ";
        }
    }
    return 0;
}

int PagedArray::createOutputFile() {
    ofstream csvfile;
    csvfile.open(outputpath);
    csvfile.close();
    cout << "The file: " << output << " was successfully created" << endl;
    ifstream binaryfile;
    binaryfile.open(pathBinary, ios::in | ios::binary);
    fstream writeFile;
    writeFile.open(outputpath, ios::app);
    int num;
    for (int i = 0; i < size * 256 ; ++i) {
        binaryfile.read((char*)&num, sizeof(int));
        if (i == size * 256){
            writeFile << num;
        } else{
            writeFile << num << ",";
        }
    }
    return 0;
}