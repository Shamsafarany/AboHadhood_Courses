#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    vector<int> numbers ;
    numbers.push_back(1); //add
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.pop_back(); //remove
    for (int &n : numbers) {
        cout << n << " ";
    }
    cout <<endl;
    cout << "First Element: " << numbers.front() << endl;
    cout << "Last Element: " << numbers.back() << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity : " << numbers.capacity() << endl;
    cout << "Empty : " << numbers.empty() << endl;

    cout << numbers.at(0) << endl;
    cout << numbers[1] << endl;

}