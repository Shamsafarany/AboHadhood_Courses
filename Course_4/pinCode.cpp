#include <iostream>
#include <math.h>
using namespace std;

int readPin(string msg){
    int n;
    cout<<msg << " ";
    cin >> n;
    return n;
}

bool isLogin() {
    int pin, count = 3;
    do{
        pin = readPin("You have " + to_string(count) + " tries left");
        if (pin == 1234) {
            return true;
        }
        count--;
    }while (pin != 1234 && count >= 1);
}

int main(){

    if (isLogin()) {
        cout <<"Logged in" << endl;
    } else {
        cout <<"Sorry" << endl;
    }


}