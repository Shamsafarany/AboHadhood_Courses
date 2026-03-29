#include <iostream>
#include <string>
using namespace std;

string ReadPassword()
{
    string Password;  
    cout << "Please enter a 3-Letter Password (all capital)?\n";
    cin >> Password;  
    
    return Password; 
}
void guessPassword(string password){
    int count = 1;
    string res = "";
    for (int i = 65; i <= 90; i++) {
        for (int j =65; j <= 90; j++) {
            for(int k = 65; k <=90; k++) {
                res.append(1, char(i));
                res.append(1, char(j));
                res.append(1, char(k));
                cout << "Trial " << count << ": "<< res << endl; 
                if (res == password) {
                    cout<< "Found at trial " << count << endl;
                    cout <<"Password: " << password << endl;
                    return;
                }
                res = "";
                count++;
            }     
        }
        cout << endl;
    }
}


int main(){
   guessPassword(ReadPassword());
}