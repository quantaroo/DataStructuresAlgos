#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include "Translator.h"
using namespace std;

/*FileProcessor Class: Takes a txt file containing English text and produce a html file containing the equivalent Rovarspraket translation that can be viewed in a standard web browser.*/

class FileProcessor{
public:
    FileProcessor();
    FileProcessor(string in, string out);
    virtual ~FileProcessor();
    string getInFile();
    void setInFile(string i);
    string getOutFile();
    void setOutFile(string o);
    string processFile(string in, string out);

private:
    string m_inFile;
    string m_outFile;
    Translator* m_translate;
    
};

#endif