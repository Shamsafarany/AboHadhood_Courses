#include <iostream>
using namespace std;

struct timeStruct{
    int days, hours, min, sec;
};
int readSec(){
    int n;
    cout<<"Enter sec: ";
    cin >> n;
    return n;
}

timeStruct fillStruct(int totalSec) {
    timeStruct duration;
    int remainder = 0;
    duration.days = totalSec / (24 * 3600);
    remainder = totalSec % (24 * 3600);
    duration.hours = remainder / 3600;
    remainder = remainder % (3600);
    duration.min = remainder / 60;
    remainder = remainder % 60;
    duration.sec = remainder;
    return duration;
}

void printRes(timeStruct duration) {
    cout << duration.days << " - " << duration.hours << " - " << duration.min << " - " << duration.sec << endl;
}

int main(){
   printRes(fillStruct(readSec()));
}