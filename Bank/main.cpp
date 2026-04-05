#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int displayMenu();
int main(){
    int choice = displayMenu();
    
    switch(choice) {
        case 1: 
                cout<<"====================================\n";
                cout<<"VIEW CLIENT LIST"<< endl;
                break;
        case 2:
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
