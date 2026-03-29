#include <iostream>
using namespace std;

void printFib(int n) {
    int prev = 0, next =1;
    if (n == 0){
        cout << prev << endl;
    } else if (n == 1) {
        cout << prev << " " << 1 << endl;
    } 
    else {
        for (int i = 0; i <= n; i++){
            int fib = prev + next;
            cout << fib << " ";
            prev = next;
            next = fib;
        }
    }
    
    cout << endl;
}
int FibRec(int n) {
    if (n == 0 || n == 1) {
       return n;
    }
    return FibRec(n - 1) + FibRec(n - 2);
}

void printFibsRec(int n){
    for (int i = 1; i <= n; i++) {
        cout << FibRec(i) << " ";
    }
    cout << endl;
}

int main(){
    printFib(5);
    printFibsRec(5);
}