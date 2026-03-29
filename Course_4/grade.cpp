#include <iostream>
using namespace std;

int validateGradeInput(int min, int max) {
    int grade;
    do{
        cout <<"Enter grade: ";
        cin >> grade; 
    } while(grade < min || grade > max);
    return grade;
}
char getGrade(int grade) {
        if (grade >= 90)
            return 'A';
        else if(grade >= 80) 
            return 'B';
        else if(grade >= 70) 
            return 'C';
        else if(grade >= 60) 
            return 'D';
        else 
            return 'F';      
    
}
void printRes(char grade) {
    cout << grade << endl;
}

int main(){
    printRes(getGrade(validateGradeInput(0, 100)));
}