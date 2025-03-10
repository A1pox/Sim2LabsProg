#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void computeRowSums(int** arr, int rows) {
    for(int i = 0; i < rows; i++){
        int len = arr[i][0];
        int sum = 0;
        for(int j = 1; j < len; j++){
            sum += arr[i][j];
        }
        cout << "Sum of row " << i << ": " << sum << endl;
    }
}
int main(){
    srand(time(0));
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    int** arr = new int*[rows];
    for(int i = 0; i < rows; i++){
        int len = rand() % 9 + 2;
        arr[i] = new int[len];
        arr[i][0] = len;
        for(int j = 1; j < len; j++){
            arr[i][j] = rand() % 101 - 50;
        }
    }
    cout << "The generated 2D array:" << endl;
    for(int i = 0; i < rows; i++){
        int len = arr[i][0];
        for(int j = 0; j < len; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nRow sums:" << endl;
    computeRowSums(arr, rows);
    for(int i = 0; i < rows; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
