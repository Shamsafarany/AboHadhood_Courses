#include <iostream>
#include <cstdlib> 
#include <ctime>     
using namespace std;

int randNum(int min, int max){
    return (int(rand()) % (max - min + 1)+ min);
}
int readInput(string msg){
    int n;
    do{
        cout <<msg << ": ";
        cin >> n;
    }while (n < 0);
    return n;
}

void fillArrRandomNumbers(int arr[100], int& length) {
    length = readInput("Enter arr size");
    for(int i = 0; i < length; i++) {
        arr[i] = randNum(1, 100);
    }
}

int findMin(int arr[100], int length) {
    int min = arr[0];
    for (int i = 0; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
int findSum(int arr[100], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return sum;
}
int findAvg(int arr[100], int length) {
    return (float) (findSum(arr, length)) / length;
}

void printArray(int arr[100], int length){
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArr(int arr1[100], int arr2[100], int length) {
    for (int i = 0; i < length; i++) {
        arr2[i] = arr1[i];
    }
}

int main(){
    int arr[100], arrCopy[100];
    int length;
    srand(time(NULL));
    fillArrRandomNumbers(arr, length);
    printArray(arr, length);
    cout << findMin(arr, length) << endl;
    cout << findSum(arr, length)<< endl;
    cout << findAvg(arr, length)<< endl;
    copyArr(arr, arrCopy, length);
    printArray(arrCopy, length);
}