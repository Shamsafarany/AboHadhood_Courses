#include <iostream>
using namespace std;

int readInput(string msg){
    int n;
    do{
        cout <<msg << ": ";
        cin >> n;
    }while (n < 0);
    return n;
}

bool findIfPrime(int n){
    bool isPrime = true;
    for(int i = 2; i < n / 2; i++) {
        if (n % i == 0) {
            isPrime = false;
            return isPrime;
        }
    }
    return isPrime;
}

void printRes(bool isPrime) {
    (isPrime) ? cout << "Prime" << endl : cout <<"Not prime" << endl;
}

int main(){
    printRes(findIfPrime(readInput("Enter num")));
}