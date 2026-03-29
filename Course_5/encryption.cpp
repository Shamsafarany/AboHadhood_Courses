#include <iostream>
#include <string>
using namespace std;

string ReadWord()
{
    string word;  
    cout << "Enter word: ";
    cin >> word;  
    
    return word; 
}

string encrypt(string word, int key) {
    for (int i = 0; i < word.length(); i++) {
      word[i] = char(int(word[i]) + key);
    }
    return word;
}
string decrypt(string word, int key) {
    for (int i = 0; i < word.length(); i++) {
      word[i]= char(int(word[i]) - key);
    }
    return word;
}

int main(){
    string word = ReadWord();
    string e_word = encrypt(word, 2);
    string d_word = decrypt(e_word, 2);

    cout <<"Before encryption: " << word<< endl;
    cout <<"After encryption: " << e_word << endl;
    cout <<"After decryption: " << d_word<< endl;

}