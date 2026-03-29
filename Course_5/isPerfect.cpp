#include <iostream>
using namespace std;

int readInput(string msg){
    int n;
    do{
        cout <<msg;
        cin >> n;
    }while (n < 0);
    return n;
}


bool isPerfect(int n){
    int sum = 0;
    for (int i = 1; i < n ; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

void printRes(bool isPerfect) {
    (isPerfect) ? cout <<"Perfect" << endl : cout <<"Not perfect" << endl;
}

void printPerfectNumbers(int n) {
    for(int i = 1; i <=n; i++) {
        if(isPerfect(i)){
            cout << i << endl;
        }
    }
}

int main(){
       printPerfectNumbers(readInput("Enter num: "));
}