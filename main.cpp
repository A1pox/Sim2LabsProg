#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int m, n = 5;
    cout << "Enter number of rows (m): ";
    cin >> m;
    srand(time(0));
    int **B = new int*[m];
    for(int i = 0; i < m; i++){
        B[i] = new int[n];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            B[i][j] = rand() % 101 - 50;
        }
    }
    cout << "Original matrix B:" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    int maxVal = B[0][0], maxRow = 0, maxCol = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(B[i][j] > maxVal){
                maxVal = B[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    int newRows = m - 1, newCols = n - 1;
    int **C = new int*[newRows];
    for(int i = 0; i < newRows; i++){
        C[i] = new int[newCols];
    }
    int r = 0;
    for(int i = 0; i < m; i++){
        if(i == maxRow) continue;
        int c = 0;
        for(int j = 0; j < n; j++){
            if(j == maxCol) continue;
            C[r][c] = B[i][j];
            c++;
        }
        r++;
    }
    cout << "\nNew matrix C (without row " << maxRow << " and column " << maxCol << "):" << endl;
    for(int i = 0; i < newRows; i++){
        for(int j = 0; j < newCols; j++){
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    for(int i = 0; i < m; i++){
        delete[] B[i];
    }
    delete[] B;
    for(int i = 0; i < newRows; i++){
        delete[] C[i];
    }
    delete[] C;
    return 0;
}
