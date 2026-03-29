#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Client{
    string accountNumber;
    string pinCode;
    string name;
    int phone;
    double balance;
};

Client getInfo(){
    Client client;
    cout<<"Client Info: " << endl;
    cout<<"Enter account number: ";
    getline(cin, client.accountNumber);
    cout<<"Enter pin code: ";
    getline(cin, client.pinCode);
    cout<<"Enter name: ";
    getline(cin, client.name); 
    cout<<"Enter phone: " ;
    cin >> client.phone;
    cout<<"Enter balance: ";
    cin >> client.balance;
    return client;
}

string convertRecToLine(Client c1, string delim) {
    string res = "";
    res+= c1.accountNumber + delim;
    res+= c1.name + delim;
    res+= to_string(c1.phone) + delim;
    res+= to_string(c1.balance);
    return res;
}
vector<string> splitString(string sentence, vector<string> list, string delim) {
    string word;
    int pos;
    while (sentence.length() > 0) {
        pos = sentence.find(delim);
        if (pos == -1) {
            word = sentence.substr(0, sentence.length());
            list.push_back(word);
            break;
        }
        word = sentence.substr(0, pos);
        if (word != "") {
            list.push_back(word);
        }
        sentence.erase(0, pos + delim.length());
    }
    cout <<"Tokens: " << list.size() << endl;
    return list;
}
Client convertLineToRecord(string line) {
    vector<string> words;
    Client c1;
    words = splitString(line, words, "#//#");
    c1.accountNumber = words.at(0);
    c1.pinCode = words.at(1);
    c1.name = words.at(2);
    c1.phone = stod(words.at(3));
    c1.balance= stod(words.at(4));
    return c1;
}

void printRecord(Client c1){
    cout << c1.accountNumber << endl;
    cout<< c1.pinCode << endl;
    cout<< c1.name << endl;
    cout << c1.phone << endl;
    cout<< c1.balance << endl;
}

int main(){
    Client c1 = getInfo();
    cout << convertRecToLine(c1, "//") << endl;
    string line = "A150#//#1234#//#Mohammed Abu- Hadhoud#//#079999#//#5270.000000";
    Client c2 = convertLineToRecord(line);
    printRecord(c2);
}
