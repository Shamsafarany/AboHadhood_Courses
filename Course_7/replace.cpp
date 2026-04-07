#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> splitString(string sentence, string delim) {
    vector<string> words;
    int pos;
    string word;
    while(sentence.length() > 0) {
        pos = sentence.find(delim);
        if (pos == -1){
            words.push_back(sentence);
            break;
        } else {
            word = sentence.substr(0, pos);
            if (word != "") {
                words.push_back(word);
            }
            sentence.erase(0, pos + delim.length());
        }
    }
    return words;
}
string tolowerALL(string word) {
    string res = "";
    for (int i = 0; i < word.length(); i++) {
        res+= tolower(word[i]);
    }
    return res;
}
string joinString(vector<string> words, string delim) {
    string res = "";
    for (string &word : words) {
        res+= word + delim;
    }
    return res.substr(0, res.length() - delim.length());
}
string replace(string original, string oldWord, string newWord, bool matchCase){
    vector<string> words  =splitString(original, " ");
    for (string &word : words) {
        if (matchCase) {
            if (word == oldWord) {
                word = newWord;
            }
        } else {
            if (tolowerALL(word) == tolowerALL(oldWord)) {
                word = newWord;
            }
        }
    }
    return joinString(words, " ");
}

int main(){
    string original = "Syria is good, syria is nice!";
    string newWord = "USA";
    string oldWord ="Syria";
    bool matchCase = true;
    string result1 = replace(original, oldWord, newWord, matchCase);
    string result2 = replace(original, oldWord, newWord, !matchCase);
    cout << result1 << endl;
    cout << result2 << endl;
    cout<<"Finished course!" << endl;
}
