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

int reverse(int number) {
    int digit = 0, result = 0;
    while(number > 0) {
        digit = number % 10;
        result = result* 10 + digit;
        number = number / 10;
    }
    return result;
}

bool isPal(int n) {
    int reversed = reverse(n);
    return n == reversed;
}
void printRes(bool isPal) {
    (isPal) ? cout <<"Palindrome" << endl : cout <<"Not palindrome" << endl;
}

int main(){
    printRes(isPal(readInput("Enter num")));
}