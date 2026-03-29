#include <iostream>
#include <math.h>
using namespace std;
void readInput(int& a, int& b, int& c) {
    cout <<"Enter a: ";
    cin >> a;
    cout <<"Enter b: ";
    cin >> b;
    cout <<"Enter c: ";
    cin >> c;
}
double calcArea(int a, int b, int c) {
    double p = (double)(a + b + c) / 2;
    double area = 3.14 * pow(((a * b * c)/ (4 * sqrt(p * (p - a) * (p - b) * (p - c)))), 2);
    return area;
}
void printResult(int n){
    cout << n << endl;
}
int main(){

    int a, b , c;
    readInput(a, b ,c);
    printResult(calcArea(a, b , c));
    


}