#include <iostream>
#include <fstream>
#include <string>
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
using namespace std;

/*Main Class: Instantiate a FileProcessor, translate the provided input file to Rovarspraket using the file processor, and exit.*/

int main(int argc, char** argv){

    FileProcessor* x = new FileProcessor(argv[1],argv[2]);
    string i = x->getInFile();
    string j = x->getOutFile();
    x->processFile(i,j);
    delete x;
};