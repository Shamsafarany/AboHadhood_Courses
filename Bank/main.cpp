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
};

//method declarations
int displayMenu();
void addClient(vector<Client>& clients);
void getClientInfo(Client& client);
void printVector(vector<Client> clients);

int main(){
    vector <Client> clients = vector<Client>();
    string fileName = "clients.txt";
    
    int choice = displayMenu();
    switch(choice) {
        case 1: 
                cout<<"====================================\n";
                cout<<"VIEW CLIENT LIST"<< endl;
                printVector(clients);
                break;
        case 2:
                cout<<"====================================\n";
                cout<<"ADD NEW CLIENT"<< endl;
                addClient(clients);
                break;
        case 3:
        case 4:
        case 5:
        case 6: 
    }

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
    cout<<"[6]- Exit\n";
    cout <<"====================================\n";
    cout<<"Choose Operation: ";
    cin >> choice;
    
    while(choice >6 || choice < 1) {
        cout<<"Invalid choice - Please choose a number between [1] and [6]: ";
        cin >> choice;
    }
    
    return choice;
}

void addClient(vector<Client>& clients) {
    Client client;
    getClientInfo(client);
    clients.push_back(client);
    cout<<"Client added to vector\n";
    printVector(clients);
}
void getClientInfo(Client& client){
    cout<<"Client Info \n";
    cout<<"ID: ";
    getline(cin>>ws, client.id);
    cout<<"Name: ";
    getline(cin, client.name);
    cout<<"Phone: ";
    getline(cin, client.phone);
    cout<<"Balance: ";
    cin >> client.balance;
}

void printVector(vector<Client> clients) {
    cout<<"====================================\n";
    cout<<"Clients List \n";
    cout<<"====================================\n";
    if (clients.size() == 0) {
        cout <<"No Added Clients\n";
        return;
    }
    for (Client& client : clients) {
        cout << client.id << " - " << client.name << " - " << client.balance << endl;
    }
}

void writeToFile(string fileName, vector<Client> clients) {
    fstream File (fileName);

}