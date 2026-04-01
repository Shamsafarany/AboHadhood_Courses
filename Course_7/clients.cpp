#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Client{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance;
};
Client getInfo(){
    Client c1;
    cout <<"Account Number: ";
    getline(cin >> ws, c1.accountNumber);
    cout <<"Pin Code: ";
    getline(cin, c1.pinCode);
    cout <<"Name: ";
    getline(cin, c1.name);
    cout <<"Phone: ";
    getline(cin, c1.phone);
    cout <<"Balance: ";
    cin >> c1.balance;
    return c1;
}

string convertRecToLine(Client c1, string delim) {
    string res;
    res+= c1.accountNumber + delim;
    res+= c1.pinCode + delim;
    res+= c1.name + delim;
    res+= c1.phone + delim;
    res+= to_string(c1.balance);
    return res;
}

void writeLineToFile(string fileName, string line) {
    fstream File;
    File.open(fileName, ios::out | ios::app);
    if (File.is_open()) {
        File<< line << endl;
        File.close();
    }
}
void addClient() {
    Client c1 = getInfo();
    writeLineToFile("clients.txt", convertRecToLine(c1, "//"));
    cout << "Client added successfully!" << endl;
}

void addClients(){
    char more = 'y';

    do{
        cout <<"Add new client: " << endl;
        addClient();
        cout<<"Add more clients? ";
        cin >> more;
    } while (tolower(more) == 'y');

}
string readAccountNumber() {
    string account;
    cout<<"Enter account number:  ";
    cin >> account;
    return account;
}
void loadFileToVector(string fileName, vector<string> &clients) {
    fstream File;
    string line;
    File.open(fileName, ios::in);
    if (File.is_open()) {
        while(getline(File, line)){
            clients.push_back(line);
        }
        File.close();
    }
}


int main(){
    addClients();  
}