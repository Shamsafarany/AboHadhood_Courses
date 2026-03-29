#include <iostream>
using namespace std;

int generateRandomNumber(int from, int to) {
    int n = rand()% (to - from + 1) + from;
    return n;
}

void fillArray(int arr[3][3], int rows, int col) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = generateRandomNumber(1,10);
        }
    }
}
void printArray(int arr[3][3], int rows, int col) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j]<<  ' ';
        }
        cout << endl;
    }
}

int sum(int arr[3][3],int row, int col) {
    int res = 0;
    for (int i = 0; i < col; i++) {
        res += arr[row][i];
    }
    return res;
}
int sumCol(int arr[3][3], int rows, int col) {
    int res = 0;
    for (int i = 0; i < rows; i++) {
        res += arr[i][col];
    }
    return res;

}

void printRowSums(int arr[3][3], int rows, int col) {
    cout <<"Sum for rows: " << endl;
    for (int i = 0; i < rows; i++) {
        cout <<"Row " << i + 1 << " : " << sum(arr, i, col) << endl;
    }
}

void fillSumArray(int arr[3][3],int sumArr[3], int rows, int col) {
    for (int i = 0; i < rows; i++) {
        sumArr[i] = sum(arr, i, col);
    }
}
void printSumArray(int arr[3], int rows) {
    for (int i = 0; i < rows;i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;
}

void printColSum(int arr[3][3], int rows, int col) {
    for (int i = 0; i < col; i++) {
        cout <<"Col " << i + 1 << " : " << sumCol(arr, rows, i) << endl;
    }
}
void fillColArray(int arr[3][3],int sumArr[3], int rows, int col) {
    for (int i = 0; i < col; i++) {
        sumArr[i] = sumCol(arr, rows, i);
    }
}

void fillOrderedArray(int arr[3][3], int row, int col) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = count++;
        }
    }
}
void transposeMatrix(int arr[3][3], int transposed[3][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
           transposed[i][j] = arr[j][i];
        }
    }
}
void multiplyArrays(int arr1[3][3], int arr2[3][3], int res[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           res[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}
void printMidRow(int arr[3][3], int rows, int cols) {
    cout <<"Middle Row"<< endl;
    int mid = rows / 2;
    for (int i = 0; i < cols; i++) {
        cout<< arr[mid][i] << " ";
    }
    cout << endl;
}
void printMidCol(int arr[3][3], int rows, int cols) {
    cout <<"Middle Column "<< endl;
    int mid = cols / 2;
    for (int i = 0; i < rows; i++) {
        cout<< arr[i][mid] << " ";
    }
    cout << endl;
}
int sumTotal(int arr[3][3], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           sum += arr[i][j];
        }
    }
    return sum;
}
bool isEqualSum(int arr1[3][3], int arr2[3][3], int rows, int cols) {
    return (sumTotal(arr1,rows,cols) == sumTotal(arr2,rows,cols));
}
bool isTypical(int arr1[3][3], int arr2[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           if (arr1[i][j] != arr2[i][j]) {
            return false;
           }
        }
    }
    return true;
}
bool isIdentity(int arr[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           if (i == j) {
                if (arr[i][j]!= 1) {
                    return false;
                } else {
                    continue;
                }
           }
           if (arr[i][j] != 0) {
            return false;
           }
        }
    }
    return true;
}
bool isScalar(int arr[3][3], int rows, int cols) {
    int x = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           if (i == j) {
               if (arr[i][j] != x) {
                return false;
               }
           } else {
            if (arr[i][j] != 0){
                return false;
            }
        } 
        }
    }
    return true;
}
int countNumber(int arr[3][3], int number, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(number == arr[i][j]) {
                count++;
            }
        }
    }
    return count;
}
bool isSparse(int arr[3][3], int rows, int cols) {
    int countZero = countNumber(arr, 0, rows, cols);
    int countNotZero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(arr[i][j] != 0) {
                countNotZero++;
            }
        }
    }
    if (countZero > countNotZero) {
        return true;
    }
    return false;
}

bool exists (int arr[3][3], int number, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(arr[i][j] == number) {
               return true;
            }
        }
    }
    return false;
}

void intersectedNumbers(int arr1[3][3], int arr2[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (exists(arr1, arr2[i][j], rows, cols)) {
                cout << arr2[i][j] << " ";
            }
        }
    }
    cout << endl;
}
int minNumber(int arr[3][3], int rows, int cols) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;

}
int maxNumber(int arr[3][3], int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;

}
bool isPalindrome(int arr[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            if(arr[i][j] != arr[i][cols - j - 1]) {
                return false;
            }
        }
    }
    return true;
}
int main(){
    srand(time(NULL));
    int arr[3][3];
    int arr2[3][3];
    int sumArr[3];
    int colSumArr[3];
    int transposed[3][3];
    int mulRes[3][3];
    int identity[3][3] = {{9,0,0}, {0,9,0}, {0,0,9}};

    fillArray(arr, 3,3);
    printArray(arr, 3,3);
    printRowSums(arr, 3,3);
    fillSumArray(arr, sumArr, 3, 3);
    printSumArray(sumArr, 3);
    printColSum(arr, 3, 3);
    fillColArray(arr, colSumArr, 3, 3);
    printSumArray(colSumArr, 3);
    fillOrderedArray(arr2, 3, 3);
    printArray(arr2, 3, 3);
    transposeMatrix(arr2,transposed, 3, 3);
    printArray(transposed, 3, 3);
    multiplyArrays(arr, arr2, mulRes, 3, 3);
    printArray(mulRes, 3, 3);
    printMidRow(arr, 3,3);
    printMidCol(arr, 3, 3);
    cout <<"Sum: " << sumTotal(arr, 3,3) << endl;
    cout << "Is Equal: " << isEqualSum(arr,arr2, 3, 3) << endl;
    cout << "Is Equal: " << isEqualSum(arr2,transposed, 3, 3) << endl;
    cout << "Is Typical: " << isTypical(arr,arr2, 3, 3) << endl;
    cout << "Is Typical: " << isTypical(arr2,transposed, 3, 3) << endl;
    cout << "Is Typical: " << isTypical(arr2,arr2, 3, 3) << endl;
    cout <<"Is Identity; " << isIdentity(arr, 3,3) << endl;
    cout <<"Is Identity; " << isIdentity(identity, 3,3) << endl;
    cout <<"Is Scalar; " << isScalar(identity, 3,3) << endl;
    cout <<"Is Sparse; " << isSparse(identity, 3,3) << endl;
    cout <<"Is Sparse; " << isSparse(arr, 3,3) << endl;
    
    intersectedNumbers(arr, arr2, 3,3);
    cout <<"Min: " << minNumber(arr, 3,3) << endl;
    cout <<"Man: " << maxNumber(arr, 3,3) << endl;
    cout <<"Is Palindrome; " << isPalindrome(transposed, 3,3) << endl;
}