#include <iostream> 
#include <iomanip> 
#include <cstdlib>
#include <fstream>

using namespace std;

void copyFile(ifstream &inStream, ofstream &outStream);

int main(){
    ifstream inStream;
    ofstream outStream;

    copyFile(inStream, outStream);
    return 0;
}

void copyFile(ifstream &inStream, ofstream &outStream){
    string inFileName, outFileName;
    string line;

    cout << "Enter the input file name (including the file extension): ";
    cin >> inFileName;
    inStream.open(inFileName.c_str());
    if(inStream.fail()){
        cout << "Failed to open the input file!" << endl;
        exit(1);
    }

    cout << "Enter the output file name (including the file extension): ";
    cin >> outFileName;
    outStream.open(outFileName.c_str());
    if(outStream.fail()){
        cout << "Failed to open the output file!" << endl;
        exit(1);
    }

    getline(inStream, line);
    while(!inStream.eof()){
        outStream << line << "\n";
        getline(inStream, line);
    }

    inStream.close();
    outStream.close();
}