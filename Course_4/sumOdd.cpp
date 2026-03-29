#include <iostream>
using namespace std;

int readInput(){
    int n;
    cout <<"Enter n: ";
    cin >> n;
    return n;
}

bool isOdd(int n) {
    return !(n % 2 == 0);
}

int sumOdd(int n) {
    int sum = 0;
    for (int i = 1 ; i <= n; i++){
        if (isOdd(i)) {
            sum += i;
        }
    }
    return sum;
} 
void printResult(int n) {
    cout << "Sum: " << n << endl; 
}
int main(){

    printResult(sumOdd(readInput()));

}