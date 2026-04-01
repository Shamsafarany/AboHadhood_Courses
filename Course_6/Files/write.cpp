#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void saveVectorToFile(string fileName, vector<string> content){
    fstream File;
    File.open("file2.txt", ios::out); 
    if(File.is_open()) {
        for (string &line : content) {
            if (line != "") {
                File << line << endl;
            }
        }
        File.close();
    }
}
int main(){
    fstream File;

    File.open("file.txt", ios::out | ios::app); //write mode

    if(File.is_open()) {
        File << "NOOOR \n";
        File << "HALALAA \n";
        File.close();
    }

    vector<string> names ={"sham", "hala", "noor"};
    saveVectorToFile("file2.txt", names);
}