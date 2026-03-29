#include <iostream>
using namespace std;

int readNum(){
    int num;
    cout <<"Enter num: ";
    cin >> num;
    return num;
}

bool validateResult(int n, int min, int max) {
    return (n >= min && n <= max);
}

int loopValidation(int min, int max){
    int n;
    do {
        n = readNum();
    } while (!validateResult(n, min, max));
    return n;
}

void printResult(int n) {
    cout << n << endl;
}

int main(){
    
    printResult(loopValidation(18, 50));
    return 0;
}