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
    bool markDelete = false;
};

void readFileToVector(string fileName, vector<string>& lines){
    fstream File;
    File.open(fileName, ios::in);
     if (File.is_open()) {
        string line;
        while(getline(File, line)) {
            lines.push_back(line);
        }
        File.close();
    }
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
vector<string> splitString(string sentence, string delim) {
    vector<string> words;
    int pos;
    string word;
    while (sentence.length() > 0) {
        pos = sentence.find(delim);
        if (pos == -1) {
            word = word.substr(0, sentence.length());
            words.push_back(word);
            break;
        }
        word = sentence.substr(0, pos);
        if (word != "") {
            words.push_back(word);
        }
        sentence.erase(0, pos + delim.length());
    }
    return words;
}
Client convertLineToClient(string line, string delim) {
    vector<string> words= splitString(line, delim);
    Client c1;
    c1.accountNumber = words.at(0);
    c1.pinCode = words.at(1);
    c1.name = words.at(2);
    c1.phone = words.at(3);
    c1.balance= stod(words.at(4));
    return c1;
}
vector<Client> readClients(){
    vector<string> lines;
    vector<Client> clients;
    readFileToVector("clients.txt", lines);
    for (string &line: lines) {
        Client c1 = convertLineToClient(line, "//");
        clients.push_back(c1);
    }
    return clients;
}
bool search(string number, Client& client){
    vector<Client> clients = readClients();
    for (Client c : clients) {
        if(c.accountNumber == number) {
            client = c;
            return true;
        }
    }
    cout <<"Client " << number << " is not found!";
    return false;
}

void printInfo(Client client) {
    cout <<client.accountNumber << " " << client.name << endl;
}
string readAccountNumber(){
    string accountNumber;
    cout <<"Enter account number: ";
    getline(cin, accountNumber);
    return accountNumber;
}
bool searchAccountNumber(string number){
    Client client;
    bool isFound = search(number, client);
    if (isFound) {
        printInfo(client);
        return true;
    }
    return false;
}
void markAccountDelete(string number, vector<Client> &clients){
    for (Client &c : clients){
        if (c.accountNumber == number) {
            c.markDelete = true;
            return;
        }
    }
}
void saveVectorToFile(string fileName, vector<Client> clients) {
    fstream File;
    File.open(fileName, ios::out);
    string line = "";
    if (File.is_open()) {
        for (Client &c : clients) {
            line = convertRecToLine(c, "//");
            if (c.markDelete != true) {
                File << line << endl;
            }
        }
        File.close();
    }
}
void deleteClientByAccount(string number, vector<Client> &clients){
    char choice;
    if (searchAccountNumber(number)) {
        cout <<"Do you want to delete? y || n" << endl;
        cin >> choice;
        if ('y' == tolower(choice)) {
            cout <<"Deleteing Client..." <<endl;
            markAccountDelete(number,clients);
            saveVectorToFile("clients.txt", clients);
            clients = readClients();
        } else {
            cout <<"Cancel Delete" << endl;
        }

    }
    
}
void updateClient(string number, Client &c) {
    cout <<"Pincode: ";
    getline(cin >> ws, c.pinCode );
    cout <<"Name: ";
    getline(cin, c.name);
    cout <<"Phone: ";
    getline(cin, c.phone);
    cout<<"Balance: ";
    cin >> c.balance;
}
void updateClientByAccount(string number, vector<Client> &clients) {
    char choice;
    if (searchAccountNumber(number)) {
        cout <<"Do you want to update? y || n " << endl;
        cin >> choice;
        if (tolower(choice) == 'y') {
            cout <<"Update Client...." << endl;
            for (Client &c : clients) {
                if (c.accountNumber == number) {
                    updateClient(number, c);
                    break;  
                }
            }
            saveVectorToFile("clients.txt", clients);
            cout<<"Client Updated!" <<endl;

            
        } else {
            cout <<"Cancel Update" << endl;
        }
    } 
}
void printClients(vector<Client> clients) {
    for (Client c : clients) {
        cout << c.accountNumber << " " << c.name << " " << 
        c.balance<< endl;
    }
}
int main(){
    vector<Client> clients = readClients();
    printClients(clients);
    deleteClientByAccount(readAccountNumber(), clients);
    cout<<"After deletion: " << endl;
    printClients(clients);
    updateClientByAccount(readAccountNumber(), clients);
    cout<<"After update: " << endl;
    printClients(clients);
    
}
