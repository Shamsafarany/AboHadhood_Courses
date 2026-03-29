#include <iostream>
#include <string>
using namespace std;

struct TaskDurationStruct{
    int days, hours, min, sec;
};
int readInput(string msg) {
    int n;
    cout << msg << " : ";
    cin >> n;
    return n;
}
TaskDurationStruct fillStruct(){
    TaskDurationStruct duration;
    duration.days = readInput("input days");
    duration.hours = readInput("input min");
    duration.min = readInput("input hours");
    duration.sec = readInput("input sec");
    return duration;
}

int Seconds (TaskDurationStruct duration) {
    int total = 0;
    total += duration.days * 24 * 60 * 60;
    total+= duration.hours * 3600;
    total+= duration.min * 60;
    total+= duration.sec;
    return total;
}
void printRes(int n) {
    cout << n << endl;
}

int main(){
    printRes(Seconds(fillStruct()));
}