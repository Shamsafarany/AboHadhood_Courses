#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void printFile(string fileName) {
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
void loadDataFromFileToVector(string fileName, vector<string>& content){
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
void loadVectorToFile(string fileName, vector<string> content) {
    fstream File;
    File.open(fileName, ios::out);
    if (File.is_open()) {
        for (string &line : content) {
           if (line != "")
            {
              File << line << endl;
            }
        }
        File.close();
    }
}   
void deleteRecord(string fileName, string record) {
    vector<string> content;
    loadDataFromFileToVector(fileName, content);
    for (string& line : content) {
        if (line == record) {
            line = "";
        }
    }
    loadVectorToFile(fileName, content);
}
void updateRecord(string fileName, string Precord, string Nrecord) {
    vector<string> content;
    loadDataFromFileToVector(fileName, content);
    for (string& line : content) {
        if (line == Precord) {
            line = Nrecord;
        }
    }
    loadVectorToFile(fileName, content);
}


int main(){
    cout <<"File before delete: " << endl;
    printFile("file.txt");
    
    deleteRecord("file.txt", "NOOOR ");
    cout <<"File After delete: " << endl;
    printFile("file.txt");
    updateRecord("file.txt", "ALI", "SARA");
    cout <<"File After update: " << endl;
    printFile("file.txt");

}