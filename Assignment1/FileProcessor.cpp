#include "FileProcessor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*FileProcessor Class: Takes a txt file containing English text and produce a html file containing the equivalent Rovarspraket translation that can be viewed in a standard web browser.*/

//Default constructor
FileProcessor::FileProcessor(){
    m_inFile = "";
    m_outFile = "";
};

FileProcessor::FileProcessor(string in, string out){
    m_inFile = in;
    m_outFile = out;
};

//Setters and Getters
string FileProcessor::getInFile(){
    return m_inFile;
};

void FileProcessor::setInFile(string i){
    m_inFile = i;
};

string FileProcessor::getOutFile(){
    return m_outFile;
};

void FileProcessor::setOutFile(string o){
    m_outFile = o;
;}

//Default destructor
FileProcessor::~FileProcessor(){
    if(m_translate != NULL){
        delete m_translate;
    }
};

//processFile - takes a string representing the input file and a string representing the output file. Bold english sentence followed by an empty line. After, intalics Rovarspraket empty line. 
string FileProcessor::processFile(string in, string out){
    //Initiate files
    ifstream inFile;
    ofstream outFile;
    inFile.open(m_inFile);
    outFile.open(m_outFile);

    //chekc for Error
    if (inFile.fail()){
        cerr << "Error Opening File" << endl;
        exit(1);
    }

    //translate inpute file, save translation into variable, and output english sentence
    string item;
    string item2;
    for(string line; getline(inFile, line);){
        Translator* x = new Translator(line);
        string i = x->getSentence();
        item = x->translateEnglishSentence(i+" ");
        item2 += item;
        outFile << "<b>" + line +"</b><br><br>";
    };

    //Output the tranlation sentence
    outFile << "<br>";
    outFile << item2;
    inFile.close();
    outFile.close();
    return "done";
};
