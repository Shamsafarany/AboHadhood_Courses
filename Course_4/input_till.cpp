#include <iostream>
using namespace std;

int readInput(string msg){
    int n;
    cout <<msg << ": ";
    cin >> n;
    return n;
}

int sum() {
    int n = 0, total = 0, counter = 1;;
    do{
        n = readInput("Enter num " + to_string(counter));
        if (n == -99) {
            break;
        }
        total+=n;
        counter++;
    } while(n != -99);
    return total;
}
void printRes(int n) {
    cout << n << endl;
}

int main(){
    printRes(sum());
}