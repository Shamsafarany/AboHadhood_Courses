#include<iostream>
using namespace std;

int readMonth(string msg, int min, int max) {
    int num;
    do{
        cout << msg <<" :";
        cin >> num;
    } while (num < min || num > max);
    return num;
}

string getMonth(int n) {
    switch(n) {
        case 1: return "January";
        case 2: return "Febuary";
        case 3: return "March";
        case 4: return "April";
        default: return "out of range";
    }
}

void printRes(string res) {
    cout << res << endl;
}

int main(){
   printRes(getMonth(readMonth("Enter month", 1, 12)));
}