#include <iostream>
using namespace std;

void readInput(int& a, int& b, char& c) {
    cout <<"Enter a: ";
    cin >> a;
    cout <<"ِِEnter b: ";
    cin >> b;
    cout <<"Enter operation: ";
    cin >> c;
}
double calculate(int a, int b, char c) {
    switch(c) {
        case '+': return a + b; break;
        case '-': return a - b; break;
        case '*': return a * b; break;
        case '/': return a / b; break;
    }
}
void printRes(int n){
    cout << n << endl;
}
int main(){
    int a , b;
    char operation;
    readInput(a, b, operation);
    printRes(calculate(a, b , operation));
}