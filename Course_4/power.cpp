#include <iostream>
using namespace std;

int enterM(){
    int m;
    cout <<"Enter m: ";
    cin>> m;
    return m;
}
int enterN(){
    int n;
    cout <<"Enter n: ";
    cin >> n;
    return n;
}
int power(int m, int n) {
    if (n == 0) {
        return 1;
    }
    int res = 1;
    for (int i = 0; i < n; i++) {
        res *= m;
    }
    return res;
}

int main(){
    cout << "Power " << power(enterM(), enterN()) << endl;
}