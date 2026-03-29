#include <iostream>
#include <vector>
#include <string>
using namespace std;

string readString(){
    string sentence = "";
    cout<<"Enter string: ";
    getline(cin, sentence);
    return sentence;
}
char readChar(){
    char c;
    cout<<"Enter char: ";
    cin >> c;
    return c;
}

void printFirstLetterOfWord(string sentence){
    cout << sentence[0] << " ";
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' '){
            cout << sentence[i+1] << " ";
        }
    }
}
string changeToUpper(string sentence) {
    sentence[0] = toupper(sentence[0]);
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' '){
            sentence[i+1] = toupper(sentence[i+1]);
        }
    }
    return sentence;
}

string changeToLower(string sentence) {
    sentence[0] = tolower(sentence[0]);
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' '){
            sentence[i+1] = tolower(sentence[i+1]);
        }
    }
    return sentence;
}
string changeToUpperAll(string sentence) {
    for (int i = 0; i < sentence.length(); i++) {
        sentence[i] = toupper(sentence[i]);
    }
    return sentence;
}
char invertLetter(char x) {
    return isupper(x) ? tolower(x) : toupper(x);
}
string invertCase(string sentence) {
    for(int i = 0; i < sentence.length(); i++) {
        sentence[i] = invertLetter(sentence[i]);
    }
    return sentence;
}
int countLetters(string sentence, char c) {
    int count = 0;
    for (int i = 0 ; i< sentence.length(); i++) {
        if (sentence[i] == c) {
            count++;
        }
    }
    return count;
}
bool isVowel(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c =='i' || c == 'u' || c == 'o') {
        return true;
    }
    return false;
}
int countVowels(string sentence) {
    int count = 0;
    for (int i =0; i < sentence.length(); i++) {
        if (isVowel(sentence[i])) {
            count++;
        }
    }
    return count;
}
void printVowels(string sentence) {
    for (int i =0; i < sentence.length(); i++) {
        if (isVowel(sentence[i])) {
            cout << sentence[i] << " ";
        }
    }
    cout <<endl;
}
void printWords(string sentence) {
    string word;
    string delim = " ";
    int pos, count = 0;
    while(sentence.length() > 0) {
        pos = sentence.find(delim);
        if (pos == -1) {
            cout << sentence.substr(0, sentence.length()) << endl;
            count++;
            break;
        }
        word = sentence.substr(0 , pos);
        if (word != "") {
            cout << word << endl;
            count++;       
        }
        sentence.erase(0, pos + delim.length());
    }
    cout << "Count: " << count << endl;
}
vector<string> splitString(string sentence, vector<string> list, string delim) {
    string word;
    int pos;
    while (sentence.length() > 0) {
        pos = sentence.find(delim);
        if (pos == -1) {
            word = sentence.substr(0, sentence.length());
            list.push_back(word);
            break;
        }
        word = sentence.substr(0, pos);
        if (word != "") {
            list.push_back(word);
        }
        sentence.erase(0, pos + delim.length());
    }
    cout <<"Tokens: " << list.size() << endl;
    return list;
}
string trimLeft(string sentence){
    string res = sentence;
    for (int i =0; i< sentence.length(); i++) {
        if (sentence[i] != ' '){
           return sentence.substr(i);
        }
    }
    return "";
}
string trimRight(string sentence){
    string res = sentence;
    for (int i = sentence.length() - 1; i> 0; i--) {
        if (sentence[i] != ' '){
            return sentence.substr(0, i+ 1);
        } 
    }
    return "";
}
string trim(string sentence){
    return trimRight(trimLeft(sentence));
} 
string joinString(vector<string> words, string delim) {
    string res = "";
    for (string word: words) {
        res += word + delim;
    }
    return res.substr(0, res.length() - delim.length());
}
string joinString(string words[], int size, string delim) {
    string res = "";
    for (int i =0; i < size; i++) {
        res += words[i] + delim;
    }
    return res.substr(0, res.length() - delim.length());
}

string reverseWords(string sentence, vector<string> list, string delim) {
    list = splitString(sentence, list, delim);
    string reversedWords = "";
    for (int i = list.size() - 1; i > 0; i--) {
        reversedWords += list.at(i) + delim;
    }
    return reversedWords;
}
string replaceWord(string sentence, string original, string newWord){
    int pos = sentence.find(original);
    while(pos != std::string::npos){
        sentence = sentence.replace(pos, original.length(), newWord);
        pos = sentence.find(original);
    }
    return sentence;
}
string removePunc(string sentence) {
    string res = "";
    for (int i = 0; i < sentence.length(); i++) {
        if (!ispunct(sentence[i])) {
            res+= sentence[i];
        }
    }
    return res;
}
void countLetterTypes(string sentence) {
    int sChar =0, uChar = 0;
    cout << "Length: " << sentence.length() << endl;
    for (int i =0;i< sentence.length(); i++) {
        if (isupper(sentence[i])){
            uChar++;
        } else if (islower(sentence[i])){
            sChar++;
        }
    }

    cout<<"Capital Letters: " << uChar << endl;
    cout<<"Small Letters: " << sChar << endl;
} 
void countCharMatch(string sentence, char c) {
    int countMatch =0, countNotMatch = 0;

    for (int i = 0;i < sentence.length(); i++) {
            if (sentence[i] == c) {
                countMatch++;
                countNotMatch++;
            if(tolower(sentence[i]) == tolower(c)) {
                countNotMatch++;    
            }
        }
     }
    cout <<"Match: " << countMatch << endl;
    cout<<"Not Match: " << countNotMatch << endl;
 }

int main(){
    string sentence = readString();
    cout << changeToUpper(sentence) << endl;
    cout << changeToLower(sentence) << endl;
    cout << changeToUpperAll(sentence) << endl;
    cout << invertCase(sentence) << endl;
    cout << countLetters(sentence, readChar()) << endl;
    cout<<"Vowel Count: " << countVowels(sentence) << endl;
    printVowels(sentence);
    printWords(sentence);
    vector <string> words;
    words = splitString(sentence, words, ",");
    for (string& word : words) {
        cout << word << endl;
    }
    string array[3] = {"sham", "hala", "noor"};
    cout << trim(sentence) << endl;
    cout << joinString(array,3, ",,.") << endl;
    cout << "Reversed: " << reverseWords(sentence, words, " ") << endl;
    cout << replaceWord(sentence, "Syria", "USA") << endl;
    cout << removePunc(sentence) << endl;
    countLetterTypes(sentence);
    countCharMatch(sentence, 'a');

}