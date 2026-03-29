#include <iostream>
using namespace std;

int readInput(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    return n;
}
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <=n; i++) {
        result *= i;
    }
    return result;
}

void printRes(int n) {
    cout << n << endl;
}
int main(){
   printRes(factorial(readInput()));
}