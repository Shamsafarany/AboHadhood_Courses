#include <iostream>
using namespace std;

int readInput(string msg){
    int n = 0;
    do{
        cout <<msg << ": ";
        cin >> n;
    }while (n < 0);
    return n;
}

int calcFrequency(int number, int value) {
    int digit = 0, count = 0;
    while (number > 0){
        digit = number % 10;
        if (digit == value){
            count++;
        }
        number = number / 10;
    }
    return count;
}

void printCountOfDigits(int n) {
    int frequency = 0;
    for (int i = 0; i < 10; i++) {
       frequency = 0;
       frequency = calcFrequency(n, i);
       if (frequency != 0) {
        cout << i << " frequency: " << frequency << endl;
       }
    }
}

int main(){
    printCountOfDigits(readInput("Enter number"));
}