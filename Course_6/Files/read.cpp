#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void readFile(string fileName) {
    fstream File;
    File.open(fileName, ios::in);
    if (File.is_open()) {
        string line;
        while(getline(File, line)) {
            cout << line << endl;
        }

        File.close();
    }
}
void readFileToVector(string fileName, vector<string> &content) {
    fstream File;
    File.open(fileName, ios::in);
    if (File.is_open()) {
        string line;
        while(getline(File, line)) {
            content.push_back(line);
        }

        File.close();
    
    }
}
int main(){
    vector<string> content;
    //readFile("file.txt");
    readFileToVector("file.txt", content);
    for (string &line : content) {
        cout << line << endl;
    }

}