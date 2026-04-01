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
    c1.phone = stod(words.at(3));
    c1.balance= stod(words.at(4));
    return c1;
}
vector<Client> readClients(){
    vector<string> lines;
    vector<Client> clients;
    readFileToVector("clients.txt", lines);
    for (string line: lines) {
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
void searchAccountNumber(){
    string accountNumber = "";
    Client client;
    cout <<"Enter account number: ";
    getline(cin, accountNumber);
    bool isFound = search(accountNumber, client);
    if (isFound) {
        printInfo(client);
    }
}

int main(){
    vector<Client> clients = readClients();
    for (Client c : clients) {
        cout << c.accountNumber << " " << c.name << endl;
    }

    searchAccountNumber();
}
