#include <iostream>
#include <cstdlib> 
#include <ctime>     
using namespace std;

int randNum(int min, int max){
    return (int(rand()) % (max - min + 1)+ min);
}

char getChar(int operation) {
    switch(operation) {
        case 1: return (char)(randNum(65, 90)); 
        case 2: return (char)(randNum(97, 122)); 
        case 3: return (char)(randNum(33, 47)); 
        case 4: return (char)(randNum(48, 67)); 
    }
}

int main(){
    srand(time(NULL));
    cout << randNum(1, 10) << endl; 
    cout << randNum(1, 10) << endl; 
    cout << randNum(1, 10) << endl; 
    cout << getChar(1) << endl;
    cout << getChar(2) << endl;
    cout << getChar(3) << endl;
    cout << getChar(4) << endl;
}