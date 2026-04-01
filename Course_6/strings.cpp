#include <iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){

    char x, y;
    x = toupper('a');
    y = tolower('A');

    cout << isupper(x) << endl;
    cout << islower(y) << endl;
    cout << isdigit(x) << endl;
    cout << ispunct(x) << endl;

    string s1 = "hello world";
    cout << s1.length() << endl;
    cout << s1.at(3) << endl;
    s1.append("!");
    cout << s1 << endl;
    s1.insert(0, "HI");
    cout << s1 << endl;
    cout << s1.substr(10, 2);
    cout << s1.find("hello") << endl;
    s1.clear();
    cout << s1 << endl;


}
