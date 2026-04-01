#include <iostream>
using namespace std;

int main(){

    int *x = new int;
    float *y = new float;
    *x = 10;
    *y = 70.32;
    cout << *x << " " << *y << endl;
    delete x;
    delete y;

    int *arr = new int[10];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < 10; i++) {
        cin >> *(arr + i);
    }
    cout <<"Numbers " << endl;
    for (int i =0; i< 10;i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
    delete [] arr;
}