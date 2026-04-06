#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Client{
    string id;
    string name;
    string phone;
    double balance;
    bool markDelete = false;
};

//method declarations
int displayMenu();
void addClient(vector<Client>& clients, string fileName);
void getClientInfo(Client& client, vector<Client> clients);
void printVector(vector<Client> clients);
string convertRecToLine(Client client, string delim); 
void printClientInfo(Client client);
void writeLineToFile(string fileName, string line); 
void deleteClient(vector<Client>& clients, string fileName);
bool searchAccount(string number, vector<Client>& clients, Client& c);
void saveVectorToFile(string fileName, vector<Client>& clients);
string readClientId();
void findClient(vector<Client> clients);
vector<string> splitString(string line, string delim);
vector<string> readFileToVector(string fileName);
Client convertLineToRec(string line);
vector<Client> readClients(string fileName);
void markAccountDelete(string number, vector<Client> &clients);
void updateClient(vector<Client>& clients, string fileName);
void updateInfo(Client& c);
int displayTransactionsMenu();
void runOperation(int choice, vector<Client>& clients, string fileName);
void deposit(vector<Client>& clients, string fileName);
void runMainOperations(int choice, vector<Client>& clients, string fileName);
void withdraw(vector<Client>& clients, string fileName);
void displayTotalBalances(vector<Client> clients, string fileName);
void updateBalance(double amount, string number, vector<Client>& clients, string fileName);


int main(){ 
    string fileName = "clients.txt";
    vector <Client> clients = readClients(fileName);
    int choice;
    bool isRunning = true;
    do {
        choice = displayMenu();
        runMainOperations(choice, clients, fileName);
        if (choice == 7) {
            isRunning = false;
            cout <<"-----------------------------\n";
            cout<<"Exiting Program..... \n";
        }
    } while (isRunning);
    
}

int displayMenu(){
    int choice = 0;
    
    cout <<"====================================\n";
    cout<<"Menu"<< endl;
    cout <<"====================================\n";
    cout<<"[1]- View Client List \n";
    cout<<"[2]- Add Client \n";
    cout<<"[3]- Delete Client \n";
    cout<<"[4]- Update Client \n";
    cout<<"[5]- Find Client \n";
    cout<<"[6]- Transactions \n";
    cout<<"[7]- Exit\n";
    cout <<"====================================\n";
    cout<<"Choose Operation: ";
    cin >> choice;
    
    while(choice >7 || choice < 1) {
        cout<<"Invalid choice - Please choose a number between [1] and [7]: ";
        cin >> choice;
    }
    
    return choice;
}

void runMainOperations(int choice, vector<Client>& clients, string fileName) {
    switch(choice) {
        case 1: 
                cout<<"====================================\n";
                cout<<"VIEW CLIENT LIST"<< endl;
                printVector(clients);
                break;
        case 2:
                cout<<"====================================\n";
                cout<<"ADD NEW CLIENT"<< endl;
                cout<<"====================================\n";
                addClient(clients, fileName);
                break;
        case 3:
                cout<<"====================================\n";
                cout<<"DELETE CLIENT"<< endl;
                cout<<"====================================\n";
                deleteClient(clients, fileName);
                break;
        case 4: cout<<"====================================\n";
                cout<<"UPDATE CLIENT INFO"<< endl;
                cout<<"====================================\n";
                updateClient(clients, fileName);
                break;
        case 5:
                cout<<"====================================\n";
                cout<<"FIND CLIENT"<< endl;
                cout<<"====================================\n";
                findClient(clients);
                break;
        case 6: 
                cout<<"====================================\n";
                cout<<"Transactions"<< endl;
                cout<<"====================================\n";
                clients = readClients(fileName);
                int choice2 = displayTransactionsMenu();
                runOperation(choice2, clients, fileName);
                break;
        }
}
void addClient(vector<Client>& clients, string fileName) {
    Client client;
    char choice;
    do{
        getClientInfo(client, clients);
        clients.push_back(client);
        cout<<"Client added to vector\n";
        printVector(clients);
        string line = convertRecToLine(client, "//");
        writeLineToFile(fileName, line);
        cout<<"Do you want to add a new client: [y / n]: ";
        cin >> choice;
         while(tolower(choice)!= 'y' && tolower(choice) != 'n') {
            cout <<"Please enter y or n: ";
            cin >> choice;
        }
    }while (tolower(choice) == 'y');
    
}
void getClientInfo(Client& client, vector<Client> clients){
    cout<<"Client Info \n";
    cout<<"ID: ";
    getline(cin>>ws, client.id);
    while (searchAccount(client.id, clients, client)) {
        cout <<"ID already exists!" << endl;
        cout<<"Enter new ID: ";
        getline(cin>>ws, client.id);
    }
    cout<<"Name: ";
    getline(cin, client.name);
    cout<<"Phone: ";
    getline(cin, client.phone);
    cout<<"Balance: ";
    cin >> client.balance;
    while(client.balance < 100) {
        cout<<"Balance must atleast be 100$. \n";
        cout<<"Balance: ";
        cin >> client.balance;
    }
}

void printVector(vector<Client> clients) {
    if (clients.size() == 0) {
        cout <<"No Added Clients\n";
        return;
    }
    cout<<"Clients : [" << clients.size() << "] \n";
    for (Client& client : clients) {
        cout << client.id << " - " << client.name << " - " << client.balance << endl;
    }
}

string convertRecToLine(Client client, string delim) {
    string line = "";
    line+= client.id + delim;
    line+= client.name  + delim;
    line+= client.phone + delim;
    line+= to_string(client.balance);
    return line;
}
void writeLineToFile(string fileName, string line) {
    fstream File;
    File.open(fileName, ios::out | ios::app);
    if (File.is_open()) {
        File << line << endl;
        File.close();
    }
}

string readClientId(){
    string id; 
    cout <<"Client ID: ";
    cin >> id;  
    return id;
}
void deleteClient(vector<Client>& clients, string fileName) {
    if (clients.size() == 0) {
        cout<<"No Clients Added \n";
        return;
    }
    Client c;
    char choice;
    string number = readClientId();
    while(!searchAccount(number, clients, c)){
        cout <<"Client not found. Try again \n";
        number = readClientId();
    }
    if(searchAccount(number, clients, c)) {
        printClientInfo(c);
        cout <<"Do you want to delete client " << "[" << c.id << "]? [y / n]: ";
        cin >> choice;
        while(tolower(choice)!= 'y' && tolower(choice) != 'n') {
            cout <<"Please enter y or n: ";
            cin >> choice;
        }
        if (tolower(choice) == 'n') {
            cout <<"Canceling operation... \n";
            return;
        } 
        markAccountDelete(number,clients);
        saveVectorToFile(fileName, clients);
        cout <<"Client deleted successfully \n";   
        clients = readClients(fileName);
        printVector(clients);
    } 
    
}

bool searchAccount(string number, vector<Client>& clients, Client& c){
    for (Client& client : clients) {
        if (client.id == number) {
            c = client;
            return true;
        }
    }
    return false;
}
void markAccountDelete(string number, vector<Client> &clients){
    for (Client &c : clients){
        if (c.id == number) {
            c.markDelete = true;
            return;
        }
    }
}
void saveVectorToFile(string fileName, vector<Client>& clients) {
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

void findClient(vector<Client> clients) {
    Client c;
    if (searchAccount(readClientId(), clients, c)) {
        printClientInfo(c);
        return;
    } else {
        cout <<"Client not found. \n";
    }
}

void printClientInfo(Client client) {
    cout << client.id << " - " << client.name << " - " << client.balance << endl;
}

vector<string> splitString(string line, string delim) {
    string word = "";
    vector<string> words;
    int pos;
    while(line.length() > 0) {
        pos = line.find(delim);
        if (pos == -1) {
            word = line.substr(0, line.length());
            words.push_back(word);
            break;
        }
        word = line.substr(0, pos);
        if (word != "") {
            words.push_back(word);
        }
        line.erase(0, pos + delim.length());
    }
    return words;
}

Client convertLineToRec(string line) {
    Client c;
    vector<string> words = splitString(line, "//");
    c.id = words.at(0);
    c.name = words.at(1);
    c.phone = words.at(2);
    c.balance = stod(words.at(3));
    return c;
}

vector<string> readFileToVector(string fileName){
    vector<string> lines;
    fstream File;
    File.open(fileName, ios::in);
     if (File.is_open()) {
        string line;
        while(getline(File, line)) {
            if (line!= "") {
                lines.push_back(line);
            }   
        }
        File.close();
    }
    return lines;
}

vector<Client> readClients(string fileName){
    vector<string> lines = readFileToVector(fileName);
    vector<Client> clients;
    for (string& line : lines) {
        Client c = convertLineToRec(line);
        clients.push_back(c);
    }
    return clients;
}

void updateClient(vector<Client>& clients, string fileName) {
    if (clients.size() == 0) {
        cout<<"No Clients Added \n";
        return;
    }
    Client c;
    char choice;
    string number = readClientId();
    while(!searchAccount(number, clients, c)){
        cout <<"Client not found. Try again \n";
        number = readClientId();
    }
    if(searchAccount(number, clients, c)) {
        printClientInfo(c);
        cout<<"Update Client Info \n";
       for (Client &cl : clients) {
                if (cl.id== number) {
                    updateInfo(cl);
                    break;  
                }
        }
       saveVectorToFile(fileName, clients);
       cout<<"Client Updated!" <<endl;
    }
}

void updateInfo(Client& c) {
    cout <<"Name: ";
    getline(cin>>ws, c.name);
    cout <<"Phone: ";
    getline(cin, c.phone);
    cout<<"Balance: ";
    cin >> c.balance;
}

int displayTransactionsMenu(){
    int choice = 0;
    cout <<"====================================\n";
    cout<<"Operations"<< endl;
    cout <<"====================================\n";
    cout<<"[1]- Deposit \n";
    cout<<"[2]- Withdraw\n";
    cout<<"[3]- Total Balances \n";
    cout<<"[4]- Go back to Main Menu \n";
    cout <<"====================================\n";
    cout<<"Choose Operation: ";
    cin >> choice;
    
    while(choice >4 || choice < 1) {
        cout<<"Invalid choice - Please choose a number between [1] and [4]: ";
        cin >> choice;
    }
    return choice;
}

void runOperation(int choice, vector<Client>& clients, string fileName) {
    switch(choice) {
        case 1: 
                cout<<"====================================\n";
                cout<<"DEPOSIT"<< endl;
                deposit(clients, fileName);
                break;
        case 2:
                cout<<"====================================\n";
                cout<<"WITHDRAW"<< endl;
                cout<<"====================================\n";
                withdraw(clients, fileName);
                break;
        case 3:
                cout<<"====================================\n";
                cout<<"TOTAL BALANCES"<< endl;
                cout<<"====================================\n";
                displayTotalBalances(clients, fileName);
                break;
        case 4: 
               return;
    }
}

void deposit(vector<Client>& clients, string fileName){
    if (clients.size() == 0) {
        cout<<"No Clients Added \n";
        return;
    }
    Client c;
    char choice;
    double amount;
    string number = readClientId();
    while(!searchAccount(number, clients, c)){
        cout <<"Client not found. Try again \n";
        number = readClientId();
    }
    if(searchAccount(number, clients, c)) {
        printClientInfo(c);
        cout<<"Deposit Amount: ";
        cin >> amount;
        while (amount <= 0) {
            cout << "Please enter a valid amount to deposit: ";
            cin >> amount;
        }
       updateBalance(amount, number, clients, fileName);       
    } 
}

void withdraw(vector<Client>& clients, string fileName){
    if (clients.size() == 0) {
        cout<<"No Clients Added \n";
        return;
    }
    Client c;
    char choice;
    double amount;
    string number = readClientId();
    while(!searchAccount(number, clients, c)){
        cout <<"Client not found. Try again \n";
        number = readClientId();
    }
    if(searchAccount(number, clients, c)) {
        printClientInfo(c);
        cout<<"Withdraw Amount: ";
        cin >> amount;
        while (amount <= 0) {
            cout << "Please enter a valid amount to deposit: ";
            cin >> amount;
        }
        while (amount > c.balance) {
            cout<<"Amount exceeds available balance, you can withdraw up to " << c.balance << endl;
            cout <<"Enter amount: ";
            cin>> amount;
        }
       amount *= -1;
       updateBalance(amount, number, clients, fileName); 
    } 
    
}

void displayTotalBalances(vector<Client> clients, string fileName) {
    printVector(clients);
    cout<<"-------------------------\n";
   
    double total = 0;
    for (Client &c: clients) {
        total += c.balance;
    }
    cout<< "Total Balances: " << total << endl;
    int choice = displayTransactionsMenu();
    runOperation(choice, clients, fileName);

}

void updateBalance(double amount, string number, vector<Client>& clients, string fileName) {
    char choice;
    cout <<"Are you sure you want to proceed with transaction [y/n]?  ";
    cin >> choice;
    while (tolower(choice) != 'y' && tolower(choice)!= 'n'){
        cout<<"Please enter y or n: ";
        cin >> choice;
    }
    if (choice == 'n') {
        int choice2 = displayTransactionsMenu();
        runOperation(choice2, clients, fileName);
        return;
    }
    for (Client &cl : clients) {
        if (cl.id== number) {
            cl.balance += amount;
            cout <<"New Balance: " << cl.balance << endl;
            break;  
        }
    }
       saveVectorToFile(fileName, clients);
       cout<<"Transaction successful!" <<endl;
       int choice2 = displayTransactionsMenu();
       runOperation(choice2, clients, fileName);
}