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
    int digit = 0, sum = 0;
    int result = 0;
    while(number > 0) {
        digit = number % 10;
        sum += digit;
        result = result* 10 + digit;
        number = number / 10;
    }
    cout <<endl << "Sum: " << sum << endl;
    return result;
}
void printDigits(int number) {
    int digit = 0, result = 0;
    while(number > 0) {
        digit = number % 10;
        number = number / 10;
        cout << digit << endl;
    }
}
void printRes(int s) {
    cout << s << endl;
}

int main(){
    printRes(reverse(readInput("Enter num")));
    printDigits(reverse(readInput("Enter num")));
}