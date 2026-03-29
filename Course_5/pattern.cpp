#include <iostream>
#include <string>
using namespace std;

int readInput(string msg){
    int n;
    do{
        cout <<msg << ": ";
        cin >> n;
    }while (n < 0);
    return n;
}

void printPatternInverted(int n) {
    while(n > 0) {
        for (int i = 0; i < n; i++) {
            cout << n << " ";
        }
        n--;
        cout << endl;
    }
}
void printPattern(int n) {
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i <<" ";
        }
        cout << endl;
    }
}
void printInvertedLetter(int n) {
    int ascii = 65 + n - 1;
    for (int i = ascii; i >= 65; i--) {
        for (int j = i; j >= 65; j--) {
            cout << (char) i << " ";
        }
        cout << endl;
    }
}
void printLetter(int n) {
    int ascii = 65 + n - 1;
    for (int i = 65; i <= ascii; i++) {
        for (int j = i; j >= 65; j--) {
            cout << (char) i << " ";
        }
        cout << endl;
    }
}
int main(){
    printInvertedLetter(readInput("Enter letter"));
    printLetter(readInput("Enter letter"));
    printPattern(readInput("Enter num"));
    printPatternInverted(readInput("Enter num"));
}